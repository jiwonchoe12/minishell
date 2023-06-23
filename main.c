#include "minishell.h"

void	shell_setting(int ac, char **av)
{
	struct termios	term;

	if (ac != 1)
		ft_error("Invalid Arguments");
	(void)ac;
	(void)av;
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term); //TCSANOW : 값을 즉시 변경한다
	//signal 처리 부분 함수 구현하기
}

int	main(int ac, char **av, char **ev)
{
	char	*str;
	t_token	*commands;

	shell_setting(ac, av);
	while (1)
	{
		str = readline("minishell$ ");
		if (!str)
			break;
		if (*str != '\0')
			add_history(str);
		if (!parsing(commands, str)) //파싱과 커맨드 에러 체크까지 해준다
		{
			free(str);
			continue ;
		}
		free(str);
		str = 0;
		//free_commands();
	}
}