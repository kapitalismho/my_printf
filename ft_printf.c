/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee <salee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 06:50:42 by salee             #+#    #+#             */
/*   Updated: 2022/01/29 19:29:36 by salee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_conversion(const char *string, va_list ap)
{
	char	*c;

	c = (char *)string;
	if (*c == 'c')
		return ft_putchar(va_arg(ap, int));
	else if (*c == 's')
		return ft_putstr(va_arg(ap, char *));
	else if (*c == 'p')
		return ft_putaddr(va_arg(ap, unsigned long long));
	else if (*c == 'd' || *c == 'i')
		return ft_putnbr(va_arg(ap, int));
	else if (*c == 'u')
		return ft_putnbr(va_arg(ap, unsigned int));
	else if (*c == 'x')
		return ft_puthexa(va_arg(ap, unsigned int), 1);
	else if (*c == 'X')
		return ft_puthexa(va_arg(ap, unsigned int), 0);
	else if (*c == '%')
		return ft_putchar('%');
	return (0);
}

int	ft_printf(const char *string, ...)
{
	va_list	ap;
	int		print_length;
	int		i;

	if (string == NULL)
		return (0);
	i = 0;
	print_length = 0;
	va_start(ap, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			print_length += ft_check_conversion(&string[i], ap);
		}
		else
			print_length += (int)write(1, &string[i], 1);
		i++;
	}
	va_end(ap);
	return (print_length);
}
