/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 22:06:25 by muhakhan          #+#    #+#             */
/*   Updated: 2024/11/28 00:53:32 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

char	**destructor(char **arr, int i)
{
	while (i >= 0)
		free(arr[i--]);
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	i;
	size_t	len;

	i = 0;
	ptr = (char **) malloc(sizeof(char *) * count_words(s, c) + 1);
	if (!ptr)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				s++;
			ptr[i++] = ft_substr(s - len, 0, len);
			if (!ptr[i - 1])
				return (destructor(ptr, i - 1));
		}
		else
			s++;
	}
	ptr[i] = NULL;
	return (ptr);
}

// int	main()
// {
// 	char **arr = ft_split("", 'z');
// 	if(!arr[0])
// 		printf("TEST");
// }