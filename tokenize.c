/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejimene <lejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:53:35 by lejimene          #+#    #+#             */
/*   Updated: 2023/09/23 19:21:32 by lejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


char *find_command_path(const char *command, char **env) {
    // Iterate through the environment variables to find the PATH variable
    int i;

    i = 0;
    while(env[i++] != NULL) 
    {
        if (ft_strncmp(env[i], "PATH=", 5) == 0) 
        {
            char *path_variable = env[i] + 5; // Get the value after "PATH="
            char *path_copy = ft_strdup(path_variable);
            if (path_copy == NULL) 
            {
                perror("Error duplicating PATH variable");
                _exit(EXIT_FAILURE);
            }
            char *path = strtok_(path_copy, ":"); // change delimiter for NULL characters
            while (path != NULL) 
            {
                char *full_path = (char *)malloc(strlen(path) + ft_strlen(command) + 2); // +2 for '/' and null terminator
                if (full_path == NULL) 
                {
                    perror("Error allocating memory for full path");
                    free(path_copy); // Clean up path_copy before exiting
                    _exit(EXIT_FAILURE);
                }
                sprintf(full_path, "%s/%s", path, command);
                if (access(full_path, X_OK) == 0) // access checks is the path is executable
                {
                    free(path_copy);
                    return full_path;
                }
                free(full_path);
                path = strtok_(NULL, ":");
            }

            free(path_copy);
            break; // Stop searching after finding the first PATH variable
        }
    }

    return NULL; // Command not found in PATH
}

char **split_args(char *input) {
    char **args = NULL;
    char *token;
    const char *delimiters = " \t";
    int arg_count = 0;

    token = strtok_(input, delimiters);
    while (token != NULL) 
    {
        // Check if the token starts and ends with the same quote (single or double)
        if ((token[strlen(token) - 1] == '\"' && token[0] == '\"') 
            && (token[strlen(token) - 1] == '\'' || token[0] == '\'') )
        {
            // Remove the surrounding quotes from the argument
            int len = strlen(token);
            if (len > 1 && token[len - 1] == token[0]) 
            {
                // Eliminate the quotes around the argument
                token[len - 1] = '\0';
                token++;
            }
        }   
        // Add the token to the arguments array
        arg_count++;
        args = (char **)realloc(args, sizeof(char *) * arg_count); // WE HAVE TO IMPLEMENT REALLOC() NOT ALLOWED BY 42
        if (args == NULL) 
        {
            perror("Error reallocating memory for arguments");
            return NULL;
        }
        args[arg_count - 1] = ft_strdup(token);
        token = strtok_(NULL, delimiters);
    }
    // Add a NULL pointer at the end of the arguments array
    arg_count++;
    args = (char **)realloc(args, sizeof(char *) * arg_count); // WE HAVE TO IMPLEMENT REALLOC() NOT ALLOWED BY 42
    if (args == NULL) 
    {
        perror("Error reallocating memory for arguments");
        return NULL;
    }
    args[arg_count - 1] = NULL;
    return args;
}

// Función TO FREE ARGS
void free_args(char **args) 
{
    int i;

    i = 0;
    while (args[i++] != NULL)
        free(args[i]);
    free(args);
}

static t_node *initialize_tokens() 
{
    t_node *tokens = (t_node *)malloc(sizeof(t_node));
    if (tokens == NULL) {
        perror("Error allocating memory for tokens");
        return NULL;
    }
    tokens->tokens = NULL;
    tokens->num_commands = 0;
    return tokens;
}

// Function to process and allocate memory for a new command
static int process_new_command(t_node *tokens, char *command, char **env) 
{
    int num_args = 0;
    int num_commands = tokens->num_commands;
    char **new = split_args(command);
    if (new == NULL) 
    {
        perror("Error splitting input");
        return 0;
    }
    while (new[num_args])
        num_args++;
    tokens->num_commands++;
    tokens->tokens = realloc(tokens->tokens, sizeof(char ***) * tokens->num_commands);
    if (tokens->tokens == NULL) 
    {
        perror("Error reallocating memory for tokens array");
        free(new);
        return 0;
    }
    tokens->tokens[num_commands] = (char **)malloc(sizeof(char *) * (num_args + 2));
    if (tokens->tokens[num_commands] == NULL) 
    {
        perror("Error allocating memory for command and arguments");
        free(new);
        return 0;
    }
    char *command_path = find_command_path(new[0], env);
    if (command_path == NULL) 
    {
        perror("Command not found");
        free(new);
        return 0;
    }
    new[0] = ft_strdup(command_path);
    for (int i = 0; i < num_args; i++) 
    {
        if ((new[i][strlen(new[i]) - 1] == '\"' && new[i][0] == '\"') ||
            (new[i][strlen(new[i]) - 1] == '\'' && new[i][0] == '\''))
            tokens->tokens[num_commands][i] = ft_strdup(ft_strtrim(new[i], "\'\""));
        else
            tokens->tokens[num_commands][i] = ft_strdup(new[i]);
    }
    tokens->tokens[num_commands][num_args] = NULL;
    free(new);
    return 1;
}

// Function to tokenize the input
t_node *tokenize(char *input, const char *delimiter, char **env) {
    char *input_copy = ft_strdup(input);
    if (input_copy == NULL) 
    {
        perror("Error duplicating input");
        return NULL;
    }
    t_node *tokens = initialize_tokens();
    if (tokens == NULL) 
    {
        free(input_copy);
        return NULL;
    }

    char *pipe_position;
    char *remainder = input_copy;

    while ((pipe_position = strchr(remainder, '|')) != NULL) 
    {
        *pipe_position = '\0';

        if (!process_new_command(tokens, remainder, env)) {
            free(input_copy);
            return NULL;
        }

        remainder = pipe_position + 1;
    }

    if (strlen(remainder) > 0) {
        if (!process_new_command(tokens, remainder, env)) {
            free(input_copy);
            return NULL;
        }
    } else {
        perror("No command after the last pipe");
        free(input_copy);
        free(tokens);
        return NULL;
    }

    free(input_copy);
    return tokens;
}

void free_t_node(t_node *node) {
    if (node) {
        // Free the memory allocated for tokens
        if (node->tokens) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; node->tokens[i][j] != NULL; j++) {
                    free(node->tokens[i][j]);
                }
                free(node->tokens[i]);
            }
            free(node->tokens);
        }
        free(node);
    }
}