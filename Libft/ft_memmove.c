/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:27:27 by muhakhan          #+#    #+#             */
/*   Updated: 2024/11/21 17:48:25 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*temp;

	temp = dest;
	if (dest == src || n == 0)
		return (temp);
	if (dest < src)
		while (n--)
			*(unsigned char *)dest++ = *(unsigned char *)src++;
	else
	{
		dest += n;
		src += n;
		while (n--)
			*(unsigned char *)(--dest) = *(unsigned char *)(--src);
	}
	return (temp);
}
