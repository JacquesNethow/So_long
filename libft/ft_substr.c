/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramondo <jramondo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:39:47 by jramondo          #+#    #+#             */
/*   Updated: 2021/09/30 14:39:47 by jramondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	size;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	if (size < start)
	{
		sub_s = malloc(sizeof(char) * 1);
		len = 0;
	}
	else
	{	
		if (size < start + len)
			sub_s = malloc(((size - start + 1) * sizeof(char)));
		else
			sub_s = malloc((len + 1) * sizeof(char));
		s += start;
	}
	if (sub_s == NULL)
		return (NULL);
	ft_strlcpy(sub_s, s, len + 1);
	return (sub_s);
}
