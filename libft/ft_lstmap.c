/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramondo <jramondo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:35:28 by jramondo          #+#    #+#             */
/*   Updated: 2021/10/17 15:35:28 by jramondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*start;

	if (lst == NULL)
		return (NULL);
	start = ft_lstnew(f(lst->content));
	lst = lst->next;
	while (lst != NULL)
	{
		new_lst = ft_lstnew(f(lst->content));
		if (new_lst == NULL)
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		ft_lstadd_back(&start, new_lst);
		lst = lst->next;
	}
	return (start);
}
