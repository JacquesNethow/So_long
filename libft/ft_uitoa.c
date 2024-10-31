/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramondo <jramondo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:08:25 by jramondo          #+#    #+#             */
/*   Updated: 2021/12/13 15:08:25 by jramondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_uitoa(unsigned int n)
{
	long long int	nbr;
	int				digits;
	char			*dest;

	nbr = n;
	digits = 1;
	while (n / 10 != 0 && digits++)
		n = n / 10;
	dest = malloc(digits + 1);
	if (!dest)
		return (NULL);
	dest[digits] = '\0';
	while (digits > -1 && digits--)
	{
		dest[digits] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (dest);
}
