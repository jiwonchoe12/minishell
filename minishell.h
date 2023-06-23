/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejokim <sejokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:25:04 by sejokim           #+#    #+#             */
/*   Updated: 2023/06/23 14:19:22 by sejokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define BUFFER_SIZE 42
# define STDERR_FILENO 2

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef enum e_token
{
	CMD,
	WORD,
	FILENAME,
	PIPE,
	RD_IN,
	RD_OUT,
	RD_HEREDOC,
	RD_APPEND,
}	t_token_type;

typedef struct s_token
{
	enum e_token	flag;
	char			*cmd;
	struct s_token	*next;
}	t_token;

typedef struct s_script
{
	t_token			*head;
	int				red_in;
	int				red_out;
	int				herecnt;
	int				argc;
	struct s_script	*next;
}	t_script;

typedef struct s_envp
{
	char			*key;
	char			*value;
	struct s_envp	*next;
}	t_envp;

typedef struct s_envp_info
{
	t_env		*head;
	int			envp_cnt;
	char		**envp;
}	t_envp_info;

typedef struct s_sh
{
	t_script	*script;
	t_env_info	envp_info;
	int			cmd_flag;
}	t_sh;

/*
utility function
*/

char	*get_next_line(int fd);
int		ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
int		find_newline(char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(const char *s, char c);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isspace(char c);

#endif