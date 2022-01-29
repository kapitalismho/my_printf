/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_anything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee <salee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 23:10:43 by salee             #+#    #+#             */
/*   Updated: 2022/01/29 19:44:25 by salee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	if (s == NULL)
		return (ft_putstr("(null)"));
	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putaddr(unsigned long long addr)
{
	char	*string;
	int		count;

	if (addr == 0)
		return ft_putstr("(nil)");
	count = 0;
	string = ft_itoa_hexa(addr, 1);
	count += ft_putstr("0x");
	count += ft_putstr(string);
	free(string);
	string = NULL;
	return (count);
}

int	ft_putnbr(long long number)
{
	char	*string;
	int		count;

	count = 0;
	string = ft_itoa(number);
	count += ft_putstr(string);
	free(string);
	string = NULL;
	return (count);
}

int	ft_puthexa(unsigned int number, int is_lowcase)
{
	char	*string;
	int		count;

	count = 0;
	string = ft_itoa_hexa(number, is_lowcase);
	count += ft_putstr(string);
	free(string);
	string = NULL;
	return (count);
}
