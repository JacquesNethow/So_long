/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramondo <jramondo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:54:25 by jramondo          #+#    #+#             */
/*   Updated: 2021/10/06 15:54:25 by jramondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static char	*transform_to_str(char *str, int n, size_t size)
{
	str[size] = '\0';
	if (n < 0)
	{
		while (--size)
		{
			str[size] = (n % 10) * -1 + '0';
			n /= 10;
		}
		str[size] = '-';
	}
	else
	{
		while (size--)
		{
			str[size] = n % 10 + '0';
			n /= 10;
		}
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		n_hold;
	size_t	digits;
	char	*str;

	n_hold = n;
	digits = 0;
	if (n_hold >= 0)
		digits = 1;
	else
	{
		digits = 2;
	}
	n_hold /= 10;
	while (n_hold)
	{
		n_hold /= 10;
		digits++;
	}
	str = malloc(digits + 1);
	if (str == NULL)
		return (NULL);
	str = transform_to_str(str, n, digits);
	return (str);
}
