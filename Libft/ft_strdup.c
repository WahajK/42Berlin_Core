/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:58:33 by muhakhan          #+#    #+#             */
/*   Updated: 2024/11/21 19:07:58 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;

	if (*(char *)s == '\0')
	{
		ptr = malloc(1);
		ptr[0] = '\0';
		return (ptr);
	}
	ptr = malloc(ft_strlen((char *)s) + 1);
	if (!ptr)
		return (NULL);
	ft_strcpy(ptr, (char *)s);
	return (ptr);
}
