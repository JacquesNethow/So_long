/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramondo <jramondo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 15:49:37 by jramondo          #+#    #+#             */
/*   Updated: 2021/09/18 15:49:37 by jramondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void	*dest, const void *src, size_t n)
{
	void	*ptr;

	ptr = dest;
	if (dest < src)
	{
		while (n--)
		{
			*(unsigned char *) dest = *(unsigned char *) src;
			dest++;
			src++;
		}
	}
	else if (dest > src)
	{
		while (n--)
		{
			*(unsigned char *)(dest + n) = *(unsigned char *)(src + n);
		}
	}
	return (ptr);
}
