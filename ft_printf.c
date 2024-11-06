/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:16:54 by ngaurama          #+#    #+#             */
/*   Updated: 2024/11/06 20:10:16 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		count;
	int		i;
	int		j;
	char	*output;

	va_start(args, format);
	i = 0;
	output = format;
	while (output[i])
	{
		if (output[i] == '%' && output[i + 1] != '%')
		{
			i++;
			j = i;
			while (output[j] != 'c' || output[j] != 's' || output[j] != 'p'
				|| output[j] != 'd' || output[j] != 'i' || output[j] != 'u'
				|| output[j] != 'x' || output[j] != 'X')
            {
                j++;
            }
            count += handler(output, args, i, output[j]);
            i = j;
		}
		else
			count += write(1, &output[i++], 1);
	}
	va_end(args);
	return (count);
}

int main()
{
    ft_printf("%c", 'c');
}