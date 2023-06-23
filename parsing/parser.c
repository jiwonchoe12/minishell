/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejokim <sejokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:16:13 by sejokim           #+#    #+#             */
/*   Updated: 2023/06/23 15:33:19 by sejokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	parser(t_tokens	*cmds, char *line)
{
	if (check_quote(line))
		return (1);
	if (tokenizer(&cmds, line) != 0 || !token || lexer(token) != 0)
	{
		
	}
}

/* 
=== check_quote ===
작동 방식 : 올바르지 않은 따옴표가 발견되면 1을 반환, 제대로 된 따옴표라면 0을 반환한다.
따옴표가 열렸는지, 닫혔는지를 확인하고 검사한다. 만약 따옴표가 제대로 되어있지 않다면, err message 출력
*/

static int	check_quote(char *line)
{
	char	quote;
	int		cmd_index;

	quote = 0;
	cmd_index = 0;
	while (line[cmd_index] != '\0')
	{
		if (!quote && (line[cmd_index] == '\'' || line[cmd_index] == '\"'))
		{
			quote = *line;
			while (quote && line[cmd_index + 1])
			{
				cmd_index++;
				if (line[cmd_index] == quote)
					quote = 0;
			}
		}
		cmd_index++;
	}
	if (quote)
	{
		print_error(quote error, 2);
		return (1);
	}
	return (0);
}
