/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejokim <sejokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:07:52 by sejokim           #+#    #+#             */
/*   Updated: 2023/06/20 18:34:54 by sejokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*sqc;
	t_list	*tmp;

	if (lst == NULL || del == NULL)
		return ;
	sqc = *lst;
	while (sqc != NULL)
	{
		tmp = sqc->next;
		ft_lstdelone(sqc, del);
		sqc = tmp;
	}
	*lst = NULL;
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*sqc;

	if (lst == NULL || f == NULL)
		return ;
	sqc = lst;
	while (sqc != NULL)
	{
		f(sqc->content);
		sqc = sqc->next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*sqc;
	t_list	*new;
	t_list	*tmp;

	if (lst == NULL || f == NULL)
		return (NULL);
	sqc = lst;
	new = NULL;
	while (sqc != NULL)
	{
		tmp = ft_lstnew(f(sqc->content));
		if (tmp == NULL)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, tmp);
		sqc = sqc->next;
	}
	return (new);
}
