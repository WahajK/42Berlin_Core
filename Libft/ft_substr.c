/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:08:31 by muhakhan          #+#    #+#             */
/*   Updated: 2024/11/28 00:35:20 by muhakhan         ###   ########.fr       */
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (!s)
		return (NULL);
	if (start > strlen(s) || len == 0)
	{
		ptr = malloc(1);
		if (!ptr)
			return (NULL);
		ptr[0] = 0;
	}
	else
	{
		s += start;
		if (len > strlen(s))
			len = strlen(s);
		ptr = ft_strndup(s, len);
	}
	return (ptr);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char *result;

// 	// Test case 1: Normal case
// 	result = ft_substr("Hello, World!", 7, 5);
// 	printf("Test 1: %s\n", result); // Expected: "World"
// 	free(result);

// 	// Test case 2: Start index out of bounds
// 	result = ft_substr("Hello, World!", 20, 5);
// 	printf("Test 2: %s\n", result); // Expected: ""
// 	free(result);

// 	// Test case 3: Length exceeds string length
// 	result = ft_substr("Hello", 1, 10);
// 	printf("Test 3: %s\n", result); // Expected: "ello"
// 	free(result);

// 	// Test case 4: Start index is 0
// 	result = ft_substr("Hello", 0, 3);
// 	printf("Test 4: %s\n", result); // Expected: "Hel"
// 	free(result);

// 	// Test case 5: Empty string
// 	result = ft_substr("", 0, 5);
// 	printf("Test 5: %s\n", result); // Expected: ""
// 	free(result);

// 	return (0);
// }