/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:37:52 by ngaurama          #+#    #+#             */
/*   Updated: 2024/11/06 20:03:18 by ngaurama         ###   ########.fr       */
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
    int left_justify;
    int zero_padding;
    int width;
    int precision;
    int alt_form;
    int sign;
    int space;
} t_flags;

int handler(char *output, va_list args, int i, char c);
int handler_c(char *output, va_list args, int i);
int ft_shift(char *output, int *i);

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