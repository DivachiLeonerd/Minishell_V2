/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:07:15 by afonso            #+#    #+#             */
/*   Updated: 2023/03/06 16:57:29 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdlib.h>
# include"../libft/libft.h"
# include <stdarg.h>

int			ft_printf(const char *string, ...);
int			print_pointer(void *ptr_x);
int			print_integer(int integer, char format);
int			print_hexa(va_list ap, char format, int counter);
int			print_unsigned_int(unsigned int u);
int			print_string(char *string);
char		*ft_utoa(unsigned int u);

#endif
