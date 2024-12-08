/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:53:33 by muhakhan          #+#    #+#             */
/*   Updated: 2024/12/09 00:37:49 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
int	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int	ft_putnbr_fd(size_t n, size_t fd);

#endif