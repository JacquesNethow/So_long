/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramondo <jramondo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:12:03 by jramondo          #+#    #+#             */
/*   Updated: 2021/10/04 20:54:09 by jramondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	last;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (!*set)
		return (ft_strdup(s1));
	first = -1;
	last = ft_strlen(s1) + 2;
	while (s1[++first] && ft_strchr(set, s1[first]))
		;
	while (first < --last && ft_strchr(set, s1[last - 1]))
		;
	return (ft_substr(s1, first, last - first));
}
