#include "minishell.h"

void	ft_error(char *msg)
{
	perror(msg);
	exit(1);
}