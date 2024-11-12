/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:24:10 by ngaurama          #+#    #+#             */
/*   Updated: 2024/11/08 18:29:13 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_utoa_len(long num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num >= 1)
	{
		len++;
		num /= 10;
	}
	return (len);
}

char	*ft_u_to_str(unsigned int num, char *str, size_t len)
{
	str = ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	len--;
	while (len)
	{
		str[len] = (num % 10) + '0';
		num /= 10;
		len--;
	}
	str[0] = (num % 10) + '0';
	return (str);
}

char	*ft_printf_utoa(unsigned int num)
{
	size_t	len;
	char	*str;

	len = ft_utoa_len(num);
	str = 0;
	str = ft_u_to_str(num, str, len);
	if (!str)
		return (NULL);
	return (str);
}

int ft_pu2(char *num, t_flags flags)
{
    int count;

    count = 0;
    if (flags.precision >= 0)
        count += ft_padding(flags.precision - 1, ft_strlen(num) - 1, flags);
    count += ft_print_e(num);
    return (count);
}

int ft_pu(char *num, t_flags flags)
{
    int count;

    count = 0;
    if (flags.left_justify)
        count += ft_pu2(num, flags);
    if (flags.precision >= 0 && (size_t)flags.precision < ft_strlen(num))
		flags.precision = ft_strlen(num);
	if (flags.precision >= 0)
	{
		flags.width -= flags.precision;
		count += ft_padding(flags.width, 0, flags);
	}
	else
		count += ft_padding(flags.width, ft_strlen(num), flags);
	if (flags.left_justify == 0)
		count += ft_pu2(num, flags);
	return (count);
}

int ft_printf_u(unsigned n, t_flags flags)
{
    char *num;
    int count;

    count = 0;
    if (!flags.precision && !n)
    {
        count += ft_padding(flags.width, 0, flags);
        return (count);
    }
    num = ft_printf_utoa(n);
    if (!num)
        return (0);
    count += ft_pu(num, flags);
    return (count);
}