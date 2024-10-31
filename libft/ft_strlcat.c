/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramondo <jramondo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:15:04 by jramondo          #+#    #+#             */
/*   Updated: 2021/09/20 16:15:04 by jramondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	index;
	size_t	size_dest;

	size_dest = 0;
	index = 0;
	while (dest[size_dest] && size_dest < size)
		size_dest++;
	if (size_dest < size)
	{
		while (src[index] && size_dest + index < size - 1)
		{
			dest[size_dest + index] = src[index];
			index++;
		}
		dest[size_dest + index] = '\0';
	}
	return (size_dest + ft_strlen(src));
}
