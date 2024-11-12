/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:45:00 by ngaurama          #+#    #+#             */
/*   Updated: 2024/11/08 21:43:21 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


size_t	ft_itoa_len(long num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		len++;
		num = -num;
	}
	while (num >= 1)
	{
		len++;
		num /= 10;
	}
	return (len);
}

char	*ft_num_to_str(long num, char *str, size_t len)
{
	str = ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	len--;
	while (len)
	{
		str[len] = (num % 10) + '0';
		num /= 10;
		len--;
	}
	if (str[0] != '-')
		str[0] = (num % 10) + '0';
	return (str);
}

char	*ft_printf_itoa(long num)
{
	size_t	len;
	char	*str;

	len = ft_itoa_len(num);
	str = 0;
	str = ft_num_to_str(num, str, len);
	if (!str)
		return (NULL);
	return (str);
}

int ft_pi(char *num, int n, t_flags flags)
{
    int count;

    count = 0;
    if (n < 0)
    {
        if (!flags.zero_padding || flags.precision >= 0)
            count += write(1, "-", 1);
    }
    else if (flags.plus && !flags.zero_padding)
        count += write(1, "+", 1);
    else if (flags.space && !flags.zero_padding)
        count += write(1, " ", 1);
    if (flags.precision >= 0)
    {
        flags.zero_padding = 1;
        count += ft_padding(flags.precision - 1, ft_strlen(num) - 1, flags);
    }
    count += ft_print_e(num);
    return (count);
}

int ft_plus(int n, t_flags *flags)
{
    int count;

    count = 0;
    if(n < 0 && flags->precision == -1)
    {
        count += write(1, "-", 1);
        flags->width--;
    }
    else if (flags->plus)
        count += write(1, "+", 1);
    else if (flags->space)
        count += write(1, " ", 1);
    return (count);
}

int ft_printf_int(char * num, int n, t_flags flags)
{
    int count;

    count = 0;
    if (flags.zero_padding)
        count += ft_plus(n, &flags);
    if (flags.left_justify)
        count += ft_pi(num, n, flags);
    if (flags.precision >= 0 && (size_t)flags.precision < ft_strlen(num))
        flags.precision = ft_strlen(num);
    if (flags.precision >= 0)
    {
        flags.width -= flags.precision;
        if (n < 0 && !flags.left_justify)
            flags.width -= 1;
        count += ft_padding(flags.width, 0, flags);
    }
    else
        count += ft_padding(flags.width - flags.plus - flags.space, ft_strlen(num), flags);
    if (!flags.left_justify)
        count += ft_pi(num, n, flags);
    return  (count);
}

int ft_printf_d_i(int n, t_flags flags)
{
    char *num;
    long nb;
    int count;

    nb = n;
    count = 0;
    if (nb < 0)
    {
        nb *= -1;
        if (!flags.zero_padding)
            flags.width--;
        flags.space = 0;
    }
    if (!flags.precision && !n)
    {
        count += ft_padding(flags.width, 0, flags);
        return (count);
    }
    num = ft_printf_itoa(nb);
    if (!num)
        return (0);
    count += ft_printf_int(num, n, flags);
    free(num);
    return (count);
}
