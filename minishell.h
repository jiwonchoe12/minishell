/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejokim <sejokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:25:04 by sejokim           #+#    #+#             */
/*   Updated: 2023/06/19 19:28:01 by sejokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_redir
{
	int			argc;
	char		**argv;
	char		**cmds;
	char		*types;
}				t_redir;

typedef struct s_cmd
{
	char		**cmdlines;
	int			flag;
	int			preflag;
	char		quote;
	int			fds[2];
	int			has_redir;
}				t_cmd;

typedef struct s_data
{
	t_list		*lstlast;
	t_cmd		*cmd;
	char		*buff;
	int			i;
	int			j;
	int			k;
}				t_data;

#endif