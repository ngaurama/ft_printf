/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:25:13 by ngaurama          #+#    #+#             */
/*   Updated: 2024/11/09 13:05:45 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handler(char const *format, va_list args)
{
	t_flags flags;
	int count = 0;
	int shift = -1;
	while (format[++shift])
	{
		flags = ft_assign();
		if (format[shift] == '%' && format[shift + 1])
		{
			int start = shift;
			shift = ft_handle_flags(format, shift, args, &flags);
			if (format[shift] && flags.letter && is_letter(format[shift]))
				count += ft_result(format[shift], args, flags);
			else
			{
				while (start <= shift)
					count += write(1, &format[start++], 1);
			}
		}
		else

			count += write(1, &format[shift], 1);
	}
	return (count);
}