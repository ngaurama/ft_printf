/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:33:02 by ngaurama          #+#    #+#             */
/*   Updated: 2024/11/06 20:05:00 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int handler(char *output, va_list args, int i, char c)
{
    int count;

    count = 0;
    if (c == 'c')
    {
        count += handler_c(output, args, i);
    }
    // else if (c == 's')
    // {

    // }
    // else if (c == 'p')
    // {

    // }
    // else if (c == 'd')
    // {
        
    // }
    // else if (c == 'i')
    // {
        
    // }
    // else if (c == 'u')
    // {
        
    // }
    // else if (c == 'x')
    // {
        
    // }
    // else if (c == 'X')
    // {

    // }
    else 
        return (0);
    return (count);
}
