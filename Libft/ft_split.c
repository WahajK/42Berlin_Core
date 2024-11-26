/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 22:06:25 by muhakhan          #+#    #+#             */
/*   Updated: 2024/11/27 00:50:14 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char	*ptr;

	ptr = malloc(n + 1);
	if (!ptr)
		return (NULL);
	ft_strncpy(ptr, s, n + 1);
	return (ptr);
}

static int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			while(s[i] == c)
				i++;
		count++;
		i++;
	}
	return (count);
}

static const char	*skip_delimeter(char const *s, char c)
{
	while (*s == c)
		s++;
	return s;
}

static	int	count_till_delimeter(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c)
		i++;
	return (i);
}
char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		words;
	int		word_len;
	int		i;
	int		j;
	int		flag;

	i = 0;
	words = count_words(s, c);
	ptr = (char **) malloc(words * sizeof(char *));
	printf("%d\n ", words);
	printf("BTE\n");
	if (!ptr)
		return (NULL);
	while (s[j] != '\0')
	{
		printf("HI\n");
		if (*s == c)
			s = skip_delimeter(s, c);
		else
		{
			word_len = count_till_delimeter(s, c);
			ptr[i] = ft_strndup(s, word_len);
			s += word_len;
		}
		i++;
		j++;
		s++;
	}
	return (ptr);
}

int	main()
{
	char str[17] = "My name is Meow";
	char **arr = ft_split(str, ' ');
	for (int i = 0; i < 5; i++)
	{
		printf("%s\n", arr[i]);
	}
}