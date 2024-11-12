/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:33:06 by ngaurama          #+#    #+#             */
/*   Updated: 2024/11/08 18:36:57 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_hextoa_len(long num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num >= 1)
	{
		len++;
		num /= 16;
	}
	return (len);
}

char	*ft_hex_to_str(unsigned long int num, char *str, size_t len)
{
	int	mod;

	str = ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	len--;
	while (len != (size_t)-1)
	{
		mod = num % 16;
		if (mod < 10)
			str[len] = mod + '0';
		else if (mod >= 10)
			str[len] = (mod - 10) + 'a';
		num = num / 16;
		len--;
	}
	return (str);
}

char	*ft_hextoa(unsigned long int num, int is_upper)
{
	size_t	len;
	char	*str;
	int		i;

	len = ft_hextoa_len(num);
	str = 0;
	str = ft_hex_to_str(num, str, len);
	if (!str)
		return (NULL);
	if (is_upper == 1)
	{
		i = 0;
		while (str[i])
		{
			if (str[i] >= 'a' && str[i] <= 'f')
				str[i] -= 32;
			i++;
		}
	}
	return (str);
}

int ft_phex(char *num, int n, int bigger, t_flags flags)
{
	int count;

	count = 0;
	if (flags.zero_padding && flags.hash && n)
	{
		if (bigger)
			count += write(1, "0X", 2);
		else 
			count += write (1, "0x", 2);
	}
	if (flags.left_justify)
	{
		if (!flags.zero_padding && flags.hash && n)
		{
			if (bigger)
				count += write(1, "0X", 2);
			else 
				count += write (1, "0x", 2);
		}
		if (flags.precision >= 0)
			count += ft_padding(flags.precision - 1, ft_strlen(num) - 1, flags);
		count += ft_print_e(num);
	}
	if (flags.precision >= 0 && (size_t)flags.precision < ft_strlen(num))
		flags.precision = ft_strlen(num);
	if (flags.precision >= 0)
	{
		flags.width-= flags.precision;
		count += ft_padding(flags.width, 0, flags);
	}
	else
		count += ft_padding(flags.width, ft_strlen(num) + (flags.hash * 2), flags);
	if (flags.left_justify == 0)
	{
		if (!flags.zero_padding && flags.hash && n)
		{
			if (bigger)
				count += write(1, "0X", 2);
			else 
				count += write (1, "0x", 2);
		}
		if (flags.precision >= 0)
			count += ft_padding(flags.precision - 1, ft_strlen(num) - 1, flags);
		count += ft_print_e(num);
	}
	return (count);
} 

int ft_printf_xX(unsigned int n, t_flags flags, int big)
{
    char *num;
    int count;

    count = 0;
    if (!flags.precision && !n)
    {
        count += ft_padding(flags.width, 0, flags);
        return (count);    
    }
    num = ft_hextoa(n, big);
    if (!num)
        return (0);
    count += ft_phex(num, n, big, flags);
	free(num);
	return (count);
}