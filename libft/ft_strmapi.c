/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramondo <jramondo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:16:01 by jramondo          #+#    #+#             */
/*   Updated: 2021/10/06 17:16:01 by jramondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_s;
	size_t	index;	

	if (s == NULL)
		return (NULL);
	new_s = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (new_s == NULL)
		return (NULL);
	index = 0;
	while (index < ft_strlen(s))
	{
		new_s[index] = f(index, s[index]);
		index++;
	}
	new_s[index] = '\0';
	return (new_s);
}
