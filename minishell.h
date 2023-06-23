/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejokim <sejokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:25:04 by sejokim           #+#    #+#             */
/*   Updated: 2023/06/23 16:05:37 by sejokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define BUFFER_SIZE 42
# define STDERR_FILENO 2

# include <stdio.h>
# include <unistd.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

typedef enum e_token
{
	CMD, // ls, cd, echo 등 말 그대로 cmd
	WORD, // ls -l에서 '-l' 같은 거
	FILENAME, // a.txt
	PIPE, // 파이프
	RD_IN, // < 입력 리다이렉션
	RD_OUT, // > 출력 리다이렉션
	RD_HEREDOC, // << 히어독
	RD_APPEND, // >> append redirection
}	t_token_type;

typedef struct s_token
{
	enum e_token	flag; // 토큰의 타입 / t_token_type의 구조체를 저장하고 있다.
	char			*cmd; // token화 시킨 각각의 cmd
	struct s_token	*next; // 다음 토큰을 가리키는 포인터
}	t_token;

typedef struct s_script
{
	t_token			*head;  // 토큰화된 명령어들의 헤드
	int				red_in; // < 입력 리다이렉션
	int				red_out; // > 출력 리다이렉션
	int				herecnt; // << 히어독이 몇 개인지 세어주는 역할
	int				argc; // 이 스크립트 블록 내에 커맨드 라인 인자의 수가 몇 개인지 세어주어야 exec 계열 함수를 사용할 때 인자를 넘겨줄 수 있다.
	struct s_script	*next;
}	t_script;

typedef struct s_envp
{
	char			*key; // $PATH=42SEOUL 에서 PATH
	char			*value; // $PATH=42SEOUL 에서 42SEOUL
	struct s_envp	*next; // 다음 envp를 가리키는 포인터
}	t_envp;

typedef struct s_envp_info
{
	struct s_envp		*head; // envp의 헤드
	int					envp_cnt; // envp의 개수
	char				**envp; // envp를 가져오기 위한 변수
}	t_envp_info;

typedef struct s_sh
{
	struct s_script		*script; // 현재 실행중인 스크립트
	struct s_envp_info	envp_info; // 환경변수 정보를 담고 있는 구조체
	int					cmd_flag; // 여러 커맨드를 동시에 처리하고 있는지를 검사하기 위한 플래그
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
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isspace(char c);

#endif