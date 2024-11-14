/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:37:32 by muhakhan          #+#    #+#             */
/*   Updated: 2024/11/14 17:17:05 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int chr)
{
	return ((chr >= 'A' && chr <= 'Z')
		|| (chr >= 'a' && chr <= 'z') || (chr >= '0' && chr <= '9'));
}
