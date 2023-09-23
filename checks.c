/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejimene <lejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:49:13 by lejimene          #+#    #+#             */
/*   Updated: 2023/09/21 15:51:54 by lejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	check_tok(char *s)
{
	t_token	tok;

	tok = check_token(s[0], s[1]);
	if (tok == OR || tok == AND)
	{
		ft_printf("bash: unexected token `%c%c'\n", s[0], s[1]);
		return (0);
	}
	else if (tok == PIPE || tok == RPR)
	{
		ft_printf("bash: unexpected token `%c'\n" , s[0]);
		return (0);
	}
	return (1);
}

t_token	check_token(char c1, char c2)
{
	if (c1 == '|' && c2 == '|')
		return (OR);
	if (c1 == '&' && c1 == '&')
		return (AND);
	if (c1 == '<' && c2 == '<')
		return (HEREDOC);
	if (c1 == '>' && c2 == '>')
		return (APPEND);
	if (c1 == '(')
		return (LPR);
	if (c1 == ')')
		return (RPR);
	if (c1 == '|')
		return (PIPE);
	if (c1 == '>')
		return (OUT);
	if (c1 == '<')
		return (IN);
	if (!c1)
		return (END);
	return (NOT);
}