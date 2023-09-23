/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejimene <lejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:17:38 by lejimene          #+#    #+#             */
/*   Updated: 2023/09/23 18:30:35 by lejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_gb	g_gb;

void print_tokens(char ***tokens, int num_commands) {
    for (int i = 0; i < 2; i++) {
        printf("Command %d:\n", i + 1);
        for (int j = 0; j < 2; j++) {
            
            printf("  Token[%d][%d]: %s\n", i, j, tokens[i][j]);
        }
        printf("\n");
    }
}

// Function to set up input redirection
static void setup_input_redirection(int pipe_fd) {
    dup2(pipe_fd, STDIN_FILENO);
    close(pipe_fd);
}

// Function to set up output redirection
static void setup_output_redirection(int pipe_fd) {
    dup2(pipe_fd, STDOUT_FILENO);
    close(pipe_fd);
}

// Function to execute a command
static int execute_command(char **command, char **env, int input_pipe_fd, int output_pipe_fd) {
    pid_t child_pid;
    int status;

    // Create a child process
    child_pid = fork();

    if (child_pid == -1) {
        perror("Error creating child process");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        // Code for the child process

        // Set up input redirection if there's an input pipe
        if (input_pipe_fd != -1) {
            setup_input_redirection(input_pipe_fd);
        }

        // Set up output redirection if there's an output pipe
        if (output_pipe_fd != -1) {
            setup_output_redirection(output_pipe_fd);
        }

        // Execute the command using execve
        execve(command[0], command, env);

        // If we reach here, there was an error in execve
        perror("Error executing the command");
        _exit(EXIT_FAILURE);
    } else {
        // Code for the parent process

        // Wait for the child process to finish
        waitpid(child_pid, &status, 0);

        if (WIFEXITED(status)) {
            // The child process exited normally
            return WEXITSTATUS(status);
        } else {
            // The child process did not exit normally
            return -1; // Error
        }
    }
}

// Function to execute a series of commands in a pipeline
int executing(t_node *node, char **env) {
    if (node == NULL || node->tokens == NULL) {
        return -1; // Error, the node or tokens are NULL
    }

    int num_commands = node->num_commands;
    int pipes[num_commands - 1][2]; // One less pipe than commands
    int input_pipe_fd = -1; // File descriptor for input pipe

    for (int i = 0; i < num_commands; i++) {
        char **command = node->tokens[i];
        int output_pipe_fd = -1; // File descriptor for output pipe

        if (i < num_commands - 1) {
            // Create a pipe for commands except the last one
            if (pipe(pipes[i]) == -1) {
                perror("Error creating pipe");
                exit(EXIT_FAILURE);
            }
            output_pipe_fd = pipes[i][1];
        }

        // Execute the command
        int exit_status = execute_command(command, env, input_pipe_fd, output_pipe_fd);

        if (i > 0) {
            // Close the input pipe descriptor from the previous command
            close(input_pipe_fd);
        }

        if (i < num_commands - 1) {
            // Close the output pipe descriptor from the current command
            close(output_pipe_fd);
            // Set the input pipe descriptor for the next command
            input_pipe_fd = pipes[i][0];
        }
    }

    return 0; // Success
}

int	main(int argc, char **argv, char **env)
{
	char	*input;
	t_node	*root;

	/* 	const char *path_variable = get_environment_variable(env, "PATH");
	const char *home_variable = get_environment_variable(env, "HOME"); */
	while (1)
	{
		_signal_start();                  // handle CTRL behavior
		input = readline("🔥minihell🔥$ "); // input of user gets stored
		if (!input)                       // close shell if input is NULL
			break ;
		if (strlen(input) == 0)
		{
			free(input); // Libera la memoria de la entrada
							// Continúa esperando el siguiente input
		}
		else
		{
			g_gb.under_exec = 1;		// this sets the under_execution status as: FALSE / 1 - - - why do we need this?
			add_history(input);			// cycle history of commands
			root = parsing(input, env);
            if (root)
                executing(root, env);	// PARSE the input
			//EDDY: =====================================================================================
			// input check builtins

			/* check_if_builtins(argv); */
			/*
				builtins to check:
					- echo with -n option
					
					- cd with only relative or absoulte path
						no need to implement -, ~

					- pwd no options

					- export no options

					- unset no options

					- env no options, no args

					- exit no options
			*/

			// if: not a built-in -> execute as execv
			
			
			// execute the commands
			/*g_gb.under_exec = 0;
		ret_mem_back(root);
		set_in_out(fd_in, fd_out); */
		}
	}
}

// REPROMPT: YANS ADVICE
// ioct (0, tiocsti, "/n") == press enter in terminal
