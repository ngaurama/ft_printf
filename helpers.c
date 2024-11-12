/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:53:20 by ngaurama          #+#    #+#             */
/*   Updated: 2024/11/09 12:44:10 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_assign(void)
{
	t_flags	flags;

	flags.letter = 0;
	flags.asterix = 0;
	flags.left_justify = 0;
	flags.zero_padding = 0;
	flags.width = 0;
	flags.precision = -1;
	flags.hash = 0;
	flags.plus = 0;
	flags.space = 0;
	return (flags);
}
int	is_flag(int c)
{
	if (c == '-' || c == '0' || c == '.' || c == '*' || c == '#' || c == ' '
		|| c == '+')
		return (1);
	return (0);
}

int	is_letter(int c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'u' || c == 'x'
		|| c == 'X' || c == 'p' || c == '%')
		return (1);
	return (0);
}

int	ft_conditions(int c)
{
	return (is_flag(c) || is_letter(c) || ft_isdigit(c));
}

int ft_precision(char const *format, int shift, va_list args, t_flags *flags)
{
    shift++;
    if (format[shift] == '*')
    {
        flags->precision = va_arg(args, int);
        return (shift++);
    }
    flags->precision = 0;
    while (ft_isdigit(format[shift]))
        flags->precision = (flags->precision * 10) + (format[shift++] - '0');
    return (shift);
}

int	ft_handle_flags(char const *format, int shift, va_list args, t_flags *flags)
{
	while (format[++shift] && ft_conditions(format[shift]))
    {
        if (format[shift] == '-')
        {
            flags->left_justify = 1; 
            flags->zero_padding = 0;
        }
        if (format[shift] == '#')
            flags->hash = 1;
        if (format[shift] == ' ')
            flags->space = 1;
        if (format[shift] == '+')
            flags->plus = 1;
        if (format[shift] == '0' && flags->left_justify == 0 && flags->width == 0)
            flags->zero_padding = 1;
        if (format[shift] == '.')
            shift = ft_precision(format, shift, args, flags);       
        if (format[shift] == '*')
        {
            flags->asterix = 1;
            flags->width = va_arg(args, int);
            if (flags->width < 0)
            {
                flags->left_justify = 1;
                flags->width *= -1;
            }
        }
        if (ft_isdigit(format[shift]))
        {
            if (flags->asterix == 1)
                flags->width = 0;
            flags->width = (flags->width * 10) + (format[shift] - '0');
        }
        if (is_letter(format[shift]))
        {
            flags->letter = format[shift];
            break;
        }
    }
    return (shift);
}
