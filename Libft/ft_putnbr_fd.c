/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 22:03:31 by muhakhan          #+#    #+#             */
/*   Updated: 2024/11/26 22:04:58 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	arr[11];
	int		i = 0;
	int		is_negative = 0;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}
	while (n > 9)
	{
		arr[i++] = (n % 10) + '0';
		n /= 10;
	}
	arr[i++] = n + '0';
	if (is_negative)
		write(fd, "-", 1);
	while (--i >= 0)
		write(fd, &arr[i], 1);
}