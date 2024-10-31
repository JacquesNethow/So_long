/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramondo <jramondo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:13:55 by jramondo          #+#    #+#             */
/*   Updated: 2021/10/17 18:50:14 by jramondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	count_size(t_list *lst, int size)
{
	size++;
	if (lst->next != NULL)
		size = count_size(lst->next, size);
	return (size);
}

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	if (lst != NULL)
		size = count_size(lst, size);
	return (size);
}
