/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramondo <jramondo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:19:18 by jramondo          #+#    #+#             */
/*   Updated: 2021/09/30 16:07:48 by jramondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	size_t	total_size;

	if (s1 == NULL)
		return (NULL);
	total_size = ft_strlen(s1) + ft_strlen(s2);
	new_s = malloc(total_size + 1);
	if (new_s == NULL)
		return (NULL);
	while (*s1)
	{
		*new_s = *s1;
		new_s++;
		s1++;
	}
	while (*s2)
	{
		*new_s = *s2;
		new_s++;
		s2++;
	}
	*new_s = '\0';
	return (new_s - total_size);
}
