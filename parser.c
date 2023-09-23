/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejimene <lejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:41:30 by lejimene          #+#    #+#             */
/*   Updated: 2023/09/23 19:08:19 by lejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node *parsing(char *input, char **env) 
{
    char *s;
    t_node *head = NULL;

    s = ft_strtrim(input, " \t\n\v\r\f");
    free(input);
    if (!s || !check_tok(s)) {
        free(s);
        return NULL;
    }

    // Tokenize with space delimiter
    const char *delimiter = " ";
    head = tokenize(s, delimiter, env);
    if (!head)
        return NULL;
    free(s);

    return head; //return the split node
}

char *strtok_(char *str, const char *delim) {
    static char *lastStr = NULL;
    char *token;

    if (str != NULL) {
        lastStr = str;
    }

    if (lastStr == NULL || *lastStr == '\0') {
        return NULL; // No more tokens
    }

    // Find the start of the token
    while (*lastStr != '\0' && strchr(delim, *lastStr) != NULL) {
        lastStr++;
    }

    if (*lastStr == '\0') {
        return NULL; // No more tokens
    }

    // Store the beginning of the token
    token = lastStr;

    // Find the end of the token
    while (*lastStr != '\0' && strchr(delim, *lastStr) == NULL) {
        lastStr++;
    }

    if (*lastStr != '\0') {
        *lastStr++ = '\0'; // Null-terminate the token
    }

    return token;
}