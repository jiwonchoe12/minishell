/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejokim <sejokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:03:41 by sejokim           #+#    #+#             */
/*   Updated: 2023/06/23 14:12:06 by sejokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*unsigned_s1;
	unsigned char	*unsigned_s2;

	unsigned_s1 = (unsigned char *)s1;
	unsigned_s2 = (unsigned char *)s2;
	i = 0;
	while ((unsigned_s1[i] || unsigned_s2[i]) && i < n)
	{
		if (unsigned_s1[i] != unsigned_s2[i])
			return (unsigned_s1[i] - unsigned_s2[i]);
		i++;
	}
	return (0);
}
