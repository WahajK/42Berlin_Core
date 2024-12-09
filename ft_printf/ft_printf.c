/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:43:21 by muhakhan          #+#    #+#             */
/*   Updated: 2024/12/09 18:18:16 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include "stdio.h"

int	ft_putnbr_base(unsigned long nbr, char *base)
{
	char	result[33];
	unsigned	number;
	int			i;
	int			count;

	count = 0;
	number = nbr;
	i = 0;
	if (number == 0)
	{
		write(1, &base[0], 1);
		count++;
	}
	while (number > 0 && ++count)
	{
		result[i++] = base[number % 16];
		number = number / 16;
	}
	while (--i >= 0)
		write(1, &result[i], 1);
	return (count);
}

int	print_address(unsigned long addr)
{
	if(!addr)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	return(ft_putnbr_base(addr, "0123456789abcdef") + 2);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	i;
	int	count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (format[i] == 'c')
				count += ft_putchar_fd(va_arg(args, int), 1);
			else if (format[i] == 's')
				count += ft_putstr_fd(va_arg(args, char *), 1);
			else if (format[i] == 'p')
				count += print_address(va_arg(args, unsigned long));
			else if (format[i] == 'd')
				count += ft_putnbr_fd(va_arg(args, int), 1);
			else if (format[i] == 'i')
				count += ft_putnbr_fd(va_arg(args, int), 1);
			else if (format[i] == 'u')
				count += ft_putnbr_fd(va_arg(args, unsigned int), 1);
			else if (format[i] == 'x')
				count += ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
			else if (format[i] == 'X')
				count += ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
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

// #include <stdio.h>

// int main(void)
// {
// 	// ft_printf("Hello, %s! You have %d new messages.\n", "Alice", 5);
// 	int i;
// 	ft_printf("Char = %c | Str = %s | Int = %d | Smol Hex = %x | Biq Hex = %X | Pointer = %p | Unsigned = %u\n", 'a', "Meow", -42, 42, -42, -1, -42);
// 	printf("Char = %c | Str = %s | Int = %d | Smol Hex = %x | Biq Hex = %X | Pointer = %p | Unsigned = %u\n", 'a', "Meow", -42, 42, -42, -1, -42);
// 	printf(" NULL %p NULL \n", NULL);
// 	ft_printf(" NULL %p NULL ", NULL);
// 	// ft_printf("Char = %c\n", 'a');
// 	// printf("OG Char = %c\n", 'a');
// 	// ft_printf("Str = %s\n", "Hello");
// 	// printf("OG Str = %s\n", "Hello");
// 	// ft_printf("Int = %d\n", 42);
// 	// printf("OG Int = %d\n", 42);
// 	// ft_printf("Hex = %x\n", 42);
// 	// printf("OG Hex = %x\n", 42);
// 	// ft_printf("Pointer = %p\n", &i);
// 	// printf("OG Pointer: %p\n", &i);
// 	// ft_printf("Unsigned = %u\n", 42);
// 	// printf("OG Unsigned = %u\n", 42);
// 	// ft_printf("Percent = %%\n");
// 	// printf("OG Percent = %%\n");
// 	// ft_printf("Int = %i\n", 42);
// 	// printf("OG Int = %i\n", 42);
// 	// ft_printf("Cap Hex = %X\n", -42); //Need to be changed to unsigned
// 	// printf("OG Cap Hex = %X\n", -42);
// 	// ft_printf("Neg ul = %u\n", -42);
// 	// printf("OG Neg ul = %u\n", -42);
// 	// printf("HEX = %X\n", 967254);
// 	return 0;
// }