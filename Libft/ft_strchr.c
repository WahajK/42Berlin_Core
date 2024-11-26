/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:27:07 by muhakhan          #+#    #+#             */
/*   Updated: 2024/11/26 20:52:14 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c)
		if (!*s++)
			return (0);
	return ((char *)s);
}
// #include <stdio.h>
// int	main()
// {
// 	printf("%s", ft_strchr("My name is Meow", 'n'));
// 	printf("%s", ft_strchr("teste", 'e'));
// }