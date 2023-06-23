/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejokim <sejokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:28:51 by sejokim           #+#    #+#             */
/*   Updated: 2023/06/23 12:29:24 by sejokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_error(char *msg, int fd)
{
	ft_putstr_fd("minishell: ", fd);
	ft_putstr_fd(msg, fd);
	ft_putstr_fd("\n", fd);
}
