/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee <salee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 12:24:16 by salee             #+#    #+#             */
/*   Updated: 2022/01/29 20:18:01 by salee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	size_calculator_u(unsigned long long n)
{
	int		i;

	i = 0;
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static char	*number_setter_u(unsigned long long n, int i, int is_l, char *ret)
{
	int		digit;
	char	*hexa;

	hexa = "0123456789abcdef";
	ret[i] = '\0';
	i--;
	while (n != 0)
	{
		digit = n % 16;
		ret[i] = hexa[digit];
		if (is_l == 0 && 'a' <= ret[i] && ret[i] <= 'z')
			ret[i] -= 32;
		n = n / 16;
		i--;
	}
	return (ret);
}

char	*ft_itoa_hexa(unsigned long long n, int is_lowcase)
{
	int		i;
	char	*ret_string;

	i = size_calculator_u(n);
	if (n == 0)
	{
		ret_string = malloc(2);
		ret_string[0] = '0';
		ret_string[1] = '\0';
	}
	else
	{
		ret_string = malloc(i + 1);
		number_setter_u(n, i, is_lowcase, ret_string);
	}
	return (ret_string);
}
