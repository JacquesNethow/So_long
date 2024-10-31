/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramondo <jramondo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:44:49 by jramondo          #+#    #+#             */
/*   Updated: 2021/10/23 21:05:44 by jramondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static size_t	num_words(char const *s, char c)
{
	size_t	word_count;
	size_t	index;
	int		start_word;

	word_count = 0;
	index = 0;
	start_word = 0;
	while (s[index])
	{
		if (!start_word && s[index] != c)
		{
			word_count++;
			start_word = 1;
		}
		if (start_word && s[index] == c)
			start_word = 0;
		index++;
	}
	return (word_count);
}

static size_t	word_size(char const *s, char c)
{
	size_t	size;

	size = 0;
	while (s[size] && s[size] != c)
		size++;
	return (size);
}

static char	*create_word(char const *s, size_t	w_size)
{
	char	*word;
	size_t	index;

	word = malloc(w_size + 1);
	if (word == NULL)
		return (NULL);
	index = 0;
	while (index < w_size)
	{
		word[index] = s[index];
		index++;
	}
	word[index] = '\0';
	return (word);
}

static void	*fail_free(char **w_array, size_t size)
{
	size_t	index;

	index = 0;
	while (index <= size)
		free(w_array[index++]);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char		**w_array;
	size_t		words;
	size_t		w_size;
	size_t		index;

	if (s == NULL)
		return (NULL);
	index = 0;
	words = num_words(s, c);
	w_array = malloc((words + 1) * sizeof(char *));
	if (w_array == NULL)
		return (NULL);
	while (index < words)
	{
		w_size = word_size(s, c);
		if (w_size)
		{
			w_array[index] = create_word(s, w_size);
			if (w_array[index++] == NULL)
				return (fail_free(w_array, index - 1));
		}
		s += w_size + 1;
	}
	w_array[index] = NULL;
	return (w_array);
}
