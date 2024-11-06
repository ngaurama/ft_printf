/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:38:09 by ngaurama          #+#    #+#             */
/*   Updated: 2024/11/06 20:08:23 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int handler_c(char *output, va_list args, int i)
{
    int count;
    int shift;
    char c;

    count = 0;
    while (output[i])
    {
        if (output[i] == '-' && ft_isdigit(output[i + 1]))
        {
            i++;
            shift = ft_shift(output, &i);
            c = (char)va_arg(args, int);
            count += write(1, &c, 1);
            shift--;
            while (i < shift)
            {
                count += write(1, " ", 1);
                i++;
            }
        }
        else if (ft_isdigit(output[i]))
        {
            shift = ft_shift(output, &i);
            shift--;
            while (i < shift)
            {
                count += write(1, " ", 1);
                i++;
            }
            c = (char)va_arg(args, int);
            count += write(1, &c, 1);        
        }
        else
            i++;
    }
    return (count);
}
