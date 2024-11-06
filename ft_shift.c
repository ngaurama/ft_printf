/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shift.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:45:08 by ngaurama          #+#    #+#             */
/*   Updated: 2024/11/06 20:03:03 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_shift(char *output, int *i)
{
    int shift;

    shift = 0;
    while (ft_isdigit(output[*i]))
    {
        shift = shift * 10 + (output[*(i++)] + '0');
    }
    return (shift);
}