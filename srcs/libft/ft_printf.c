/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonso <afonso@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:00:57 by afonso            #+#    #+#             */
/*   Updated: 2022/03/08 11:27:59 by afonso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static int	fmt_handler(const char *format, va_list ap, int counter);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		counter;

	counter = 0;
	va_start(ap, format);
		counter += fmt_handler(format, ap, counter);
	va_end(ap);
	return (counter);
}

static	int	chr_string_handler(va_list ap, char format)
{
	int	counter;

	counter = 0;
	if (format == '%')
		ft_putchar_fd('%', 1);
	else if (format == 's')
		counter += print_string(va_arg(ap, char *)) - 1;
	counter++;
	return (counter);
}

static	int	is_valid_format(const char *format)
{
	int		i;
	char	fmt_array[10];

	fmt_array[0] = 'p';
	fmt_array[1] = 'x';
	fmt_array[2] = 'X';
	fmt_array[3] = 'c';
	fmt_array[4] = 'u';
	fmt_array[5] = 's';
	fmt_array[6] = 'i';
	fmt_array[7] = 'd';
	fmt_array[8] = '%';
	fmt_array[9] = '\0';
	i = 0;
	while (*format != fmt_array[i] && *format)
		i++;
	if (!*format)
		return (1);
	else
		return (0);
}

static	int	fmt_handler(const char *format, va_list ap, int counter)
{
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (is_valid_format(format))
				break ;
			if (*format == 'p' || *format == 'x'
				||*format == 'X' || *format == 'u')
				counter += print_hexa(ap, *format, 0);
			if (*format == 'd' || *format == 'i' || *format == 'c')
				counter += print_integer(va_arg(ap, int), *format);
			if (*format == '%' || *format == 's')
				counter += chr_string_handler(ap, *format);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			counter++;
		}
		format++;
	}
	return (counter);
}
