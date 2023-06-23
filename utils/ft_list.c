/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejokim <sejokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:07:03 by sejokim           #+#    #+#             */
/*   Updated: 2023/06/22 16:43:17 by sejokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*sqc;

	sqc = (t_list *)malloc(sizeof(t_list));
	if (sqc == NULL)
		return (NULL);
	sqc->content = content;
	sqc->next = NULL;
	return (sqc);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	if (*lst != NULL)
		new->next = *lst;
	*lst = new;
}

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*sqc;

	count = 0;
	sqc = lst;
	while (sqc != NULL)
	{
		count++;
		sqc = sqc->next;
	}
	return (count);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*sqc;

	sqc = lst;
	if (sqc == NULL)
		return (NULL);
	while (sqc->next != NULL)
		sqc = sqc->next;
	return (sqc);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*sqc;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	sqc = ft_lstlast(*lst);
	sqc->next = new;
}
