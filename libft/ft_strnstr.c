/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramondo <jramondo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:18:50 by jramondo          #+#    #+#             */
/*   Updated: 2021/09/29 16:18:50 by jramondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	n_count;

	if (little == NULL)
		return ((char *) big);
	if (ft_strlen(little) > ft_strlen(big))
		return (NULL);
	n_count = 0;
	while (n - n_count >= ft_strlen(little))
	{
		if (!ft_strncmp(big, little, ft_strlen(little)))
			return ((char *)big);
		big++;
		n_count++;
	}
	return (NULL);
}
