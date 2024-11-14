/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:31:24 by muhakhan          #+#    #+#             */
/*   Updated: 2024/11/14 17:56:06 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	j;
	unsigned int	dest_len;
	unsigned int	src_len;

	j = 0;
	dest_len = 0;
	src_len = 0;
	while (dest[dest_len])
		dest_len++;
	while (src[src_len])
		src_len++;
	if (size <= dest_len)
		return (size + src_len);
	while (src[j] && j < size - dest_len - 1)
	{
		dest[dest_len + j] = src[j];
		j++;
	}
	dest[dest_len + j] = '\0';
	return (dest_len + src_len);
}

// #include <stdio.h>

// int main(void)
// {
// 	char dest[20];
// 	unsigned int result;
// 	memset(dest, 'r', 15);
// 	result = ft_strlcat(dest, "lorem ipsum dolor sit amet", 5);
// 	printf("Resulting string: %s\n", dest);
// 	printf("Total length: %u\n", result);
// 	return 0;
// }