/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:26:05 by ngaurama          #+#    #+#             */
/*   Updated: 2024/11/08 21:43:24 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_padding(int len, int shift, t_flags flags)
{
    int count;

    count = 0;
    while (len - shift > 0)
    {
        if (flags.zero_padding)
            count += write(1, "0", 1);
        else
            count += write(1, " ", 1);
        len--;
    }
    return (count);
}

int ft_printf_c(char c, t_flags flags)
{
    int count;

    count = 0;
    if (flags.left_justify)
        count += write(1, &c, 1);
    count += ft_padding(flags.width, 1, flags);
    if (!flags.left_justify)
        count += write(1, &c, 1);
    return (count);
}