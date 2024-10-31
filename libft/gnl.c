/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramondo <jramondo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:49:45 by jramondo          #+#    #+#             */
/*   Updated: 2022/04/14 22:38:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static char	*afternl(char *line)
{
	return (line = ft_substr(line, 1 + ft_strchr(line, '\n') - line
			, ft_strlen(ft_strchr(line, '\n'))));
}

static void	*check_line(char *line)
{	
	char	*swap;

	if (line)
	{
		if (!ft_strlen(line) || (ft_strlen(line) == 1 && ft_strchr(line, '\n')))
		{
			free(line);
			line = NULL;
		}
		else
		{
			if (ft_strchr(line, '\n'))
			{
				swap = line;
				line = afternl(line);
				free(swap);
			}
			else
			{
				free(line);
				line = NULL;
			}
		}
	}
	return (line);
}

static char	*result(char *line, ssize_t content_size)
{
	if (((content_size < 1 || BUFFER_SIZE < 1) && !line)
		|| (!ft_strlen(line) && content_size < 1))
	{
		free(line);
		return (NULL);
	}
	return (ft_substr(line, 0, ft_strchr(line, '\n') - line + 1));
}

char	*get_next_line(int fd)
{
	char			*content;
	static char		*line;
	char			*swap;
	ssize_t			content_size;

	line = check_line(line);
	content = malloc(1 + BUFFER_SIZE);
	content_size = read(fd, content, BUFFER_SIZE);
	while (content_size > 0)
	{
		content[content_size] = '\0';
		if (!line)
			line = ft_strjoin(content, "");
		else
		{
			swap = line;
			line = ft_strjoin(line, content);
			free(swap);
		}
		if (ft_strchr(line, '\n'))
			break ;
		content_size = read(fd, content, BUFFER_SIZE);
	}
	free(content);
	return (result(line, content_size));
}
