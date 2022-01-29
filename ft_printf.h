/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee <salee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 06:46:48 by salee             #+#    #+#             */
/*   Updated: 2022/01/29 20:19:35 by salee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *string, ...);
int		ft_check_conversion(const char *string, va_list ap);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putaddr(unsigned long long addr);
int		ft_putnbr(long long number);
int		ft_puthexa(unsigned int number, int is_lowcase);
char	*ft_itoa_hexa(unsigned long long n, int is_lowcase);
char	*ft_itoa(long long n);

#endif
