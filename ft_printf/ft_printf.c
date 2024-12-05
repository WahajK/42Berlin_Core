/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:43:21 by muhakhan          #+#    #+#             */
/*   Updated: 2024/12/05 20:46:36 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	char	result[33];
	int		i;
	int		count;
	long	number;

	base_len = ft_strlen(base);
	count = 0;
	number = nbr;
	if (number < 0)
	{
		write(1, "-", 1);
		number = -number;
		count++;
	}
	i = 0;
	if (number == 0)
	{
		write(1, &base[0], 1);
		count++;
	}
	while (number > 0 && count++)
	{
		result[i++] = base[number % base_len];
		number = number / base_len;
	}
	while (--i >= 0)
		write(1, &result[i], 1);
	return (count);
}

void	print_address(unsigned long addr)
{
	int		i;
	char	address[16];

	i = 15;
	while (i >= 0)
	{
		address[i] = "0123456789abcdef"[addr % 16];
		addr /= 16;
		i--;
	}
	write(1, address, 16);
	write(1, ": ", 2);
}

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
			if (format[i] == 'c')
			{
				num = va_arg(args, int);
				ft_putchar_fd(num, 1);
				count++;
			}
			else if (format[i] == 's')
			{
				str = va_arg(args, char *);
				ft_putstr_fd(str, 1);
				count += ft_strlen(str);
			}
			else if (format[i] == 'p')
			{
				print_address(va_arg(args, unsigned long)); // Need work
				count += 16;
			}
			else if (format[i] == 'd')
			{
				num = va_arg(args, int);
				ft_putnbr_fd(num, 1);
			}
			else if (format[i] == 'i')
			{
				num = va_arg(args, int);
				ft_putnbr_fd(num, 1);
			}
			else if (format[i] == 'u')
			{
				num = va_arg(args, unsigned int);
				ft_putnbr_fd(num, 1);
			}
			else if (format[i] == 'x')
			{
				num = va_arg(args, unsigned int);
				count += ft_putnbr_base(num, "0123456789abcdef");
			}
			else if (format[i] == 'X')
			{
				num = va_arg(args, unsigned int);
				count += ft_putnbr_base(num, "0123456789ABCDEF");
			}
			else if (format[i] == '%')
			{
				write(1, "%", 1);
				count++;
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

#include <stdio.h>

int main(void)
{
	// ft_printf("Hello, %s! You have %d new messages.\n", "Alice", 5);
	int i;
	printf("Char = %c\n", 'a');
	printf("Str = %s\n", "Hello");
	printf("Int = %d\n", 42);
	printf("Hex = %x\n", 42);
	printf("Pointer = %p\n", &i);
	printf("Unsigned = %u\n", 42);
	printf("Percent = %%\n");
	printf("Int = %i\n", 42);
	printf("Cap Hex = %X\n", -42);
	printf("Neg ul = %u\n", -42);
	printf("Int = %X\n", 4294967254);
	return 0;
}