/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:51:46 by muhakhan          #+#    #+#             */
/*   Updated: 2024/11/21 17:53:21 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *s, size_t n)
{
	char	*ptr;

	ptr = malloc(n + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s, n + 1);
	return (ptr);
}

static int	ft_is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*ptr;

	start = 0;
	end = ft_strlen((char *)s1) - 1;
	while (s1[start] && ft_is_in_set(s1[start], set))
		start++;
	while (end > start && ft_is_in_set(s1[end], set))
		end--;
	ptr = ft_strndup(&s1[start], end - start + 1);
	return (ptr);
}
