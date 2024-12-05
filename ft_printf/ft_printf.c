/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:43:21 by muhakhan          #+#    #+#             */
/*   Updated: 2024/12/05 18:55:20 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putnbr(int n);
int ft_printf(const char *format, ...)
{
	va_list args;
	int i = 0;
	int count = 0;
	char *str;
	int num;

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (format[i] == 's')
			{
				str = va_arg(args, char *);
				while (*str)
				{
					write(1, str++, 1);
					count++;
				}
			}
			else if (format[i] == 'd')
			{
				num = va_arg(args, int);
				count += ft_putnbr(num);
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

int ft_putnbr(int n)
{
	int count = 0;
	char c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	count++;
	return (count);
}
int main(void)
{
	ft_printf("Hello, %s! You have %d new messages.\n", "Alice", 5);
	return 0;
}