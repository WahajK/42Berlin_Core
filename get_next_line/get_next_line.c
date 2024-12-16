/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:41:41 by muhakhan          #+#    #+#             */
/*   Updated: 2024/12/16 02:33:22 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * ft_strjoin - Allocates and returns a new string, which is the result of 
 * the concatenation of 's1' and 's2'.
 * @s1: The prefix string.
 * @s2: The suffix string.
 *
 * Return: The new string. NULL if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		ptr[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		ptr[j++] = s2[i];
		i++;
	}
	ptr[j] = 0;
	return (ptr);
}

char	*set_line(int fd, char *buffer, char **line)
{
	int		i;
	char	*temp;
	if(!*line || !ft_strchr(*line, '\n'))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		while (i > 0)
		{
			buffer[i] = 0;
			if (!*line)
				*line = ft_substr(buffer, 0, i);
			else
			{
				temp = *line;
				*line = ft_strjoin(*line, buffer);
				free(temp);
			}
			if (ft_strchr(*line, '\n'))
				break ;
			i = read(fd, buffer, BUFFER_SIZE);
		}
	}
	free(buffer);
}

char	*get_line(char **line)
{
	int		i;
	int		j;
	char	*ret;
	char	*temp;

	if (!*line)
		return (0);
	if (!ft_strchr(*line, '\n'))
	{
		ret = ft_substr(*line, 0, ft_strlen(*line));
		free (*line);
		*line = 0;
		return (ret);
	}
	i = ft_strlen(*line);
	j = ft_strlen(ft_strchr(*line, '\n'));
	ret = ft_substr(*line, 0, i - j + 1);
	temp = *line;
	*line = ft_substr(ft_strchr(*line, '\n'), 1, j - 1);
	free(temp);
	return (ret);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	static char	*line;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (BUFFER_SIZE < 1 || fd == -1 || read(fd, buffer, 0) == -1)
	{
		free(buffer);
		return (0);
	}
	set_line(fd, buffer, &line);
	return (get_line(&line));
}
// #include <stdio.h>
// #include <fcntl.h>
// int	main()
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	char *str;
// 	while (str = get_next_line(fd))
// 		printf("%s", str);
// }