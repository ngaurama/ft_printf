/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:37:52 by ngaurama          #+#    #+#             */
/*   Updated: 2024/11/09 13:02:29 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"

//flags
typedef struct s_flags
{
    int letter;
    int asterix;
    int left_justify;
    int zero_padding;
    int width;
    int precision;
    int hash;
    int plus;
    int space;
} t_flags;

int handler(char const *format, va_list args);
int	ft_printf(const char *format, ...);
t_flags ft_assign(void);
int ft_handle_flags(char const *format, int shift, va_list args, t_flags *flags);
int ft_conditions(int c);
int	is_letter(int c);
int ft_padding(int len, int shift, t_flags flags);
int ft_printf_s(char const *str, t_flags flags);
int ft_printf_c(char c, t_flags flags);
int ft_result(char letter, va_list args, t_flags flags);
int ft_printf_p(unsigned long n, t_flags flags);
int ft_printf_d_i(int n, t_flags flags);
int ft_print_e(const char *str);
int ft_printf_u(unsigned n, t_flags flags);
int ft_printf_xX(unsigned int n, t_flags flags, int big);
int	is_flag(int c);

#endif

/*
| Flag        | `%c` | `%s` | `%p` | `%d` | `%i` | `%u` | `%x` | `%X` | `%%` |
|-------------|------|------|------|------|------|------|------|------|------|
| **`-`**     | Yes  | Yes  | Yes  | Yes  | Yes  | Yes  | Yes  | Yes  | No   |
| **`0`**     | No   | No   | No   | Yes  | Yes  | Yes  | Yes  | Yes  | No   |
| **`.`**     | No   | Yes  | Yes  | Yes  | Yes  | Yes  | Yes  | Yes  | No   |
| **Width**   | Yes  | Yes  | Yes  | Yes  | Yes  | Yes  | Yes  | Yes  | No   |
| **`#`**     | No   | No   | Yes  | Yes  | Yes  | No   | Yes  | Yes  | No   |
| **`+`**     | No   | No   | No   | Yes  | Yes  | No   | No   | No   | No   |
| **` `**     | No   | No   | No   | Yes  | Yes  | No   | No   | No   | No   |
| **`%%`**    | No   | No   | No   | No   | No   | No   | No   | No   | Yes  |
*/