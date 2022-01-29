/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee <salee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 04:16:31 by salee             #+#    #+#             */
/*   Updated: 2022/01/29 05:03:50 by salee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	size_calculator(long long n, int is_negative)
{
	int		i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	if (is_negative == 1)
		i++;
	return (i);
}

static char	*number_setter(long long n, int i, int is_negative, char *ret_string)
{
	int		digit;

	ret_string[i] = '\0';
	i--;
	while (n != 0)
	{
		digit = n % 10;
		ret_string[i] = digit + '0';
		n = n / 10;
		i--;
	}
	if (is_negative == 1)
		ret_string[i] = '-';
	return (ret_string);
}

char		*ft_itoa(long long n)
{
	int		i;
	int		is_negative;
	char	*ret_string;

	is_negative = 0;
	if (n < 0)
	{
		n = n * -1;
		is_negative = 1;
	}
	i = size_calculator(n, is_negative);
	if (n == 0)
	{
		ret_string = malloc(2);
		ret_string[0] = '0';
		ret_string[1] = '\0';
	}
	else
	{
		ret_string = malloc(i + 1);
		number_setter(n, i, is_negative, ret_string);
	}
	return (ret_string);
}
