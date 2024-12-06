/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:39:54 by myuen             #+#    #+#             */
/*   Updated: 2024/07/24 18:54:15 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

#define INT_STR_MAX_LEN 65

static int	ft_print_sign(t_conversion *conver)
{
	int	ret;

	ret = 0;
	if (conver->sign)
		ret += write(STDOUT, "-", 1);
	if (conver->plus && !conver->sign)
		ret += write(STDOUT, "+", 1);
	if (conver->space && !conver->plus && !conver->sign)
		ret += write(STDOUT, " ", 1);
	return (ret);
}

static int	ft_prepare_number(long num, char *str, t_conversion *conver,
		int *precision_pad)
{
	unsigned long	unum;
	int				len;

	if (num < 0)
	{
		unum = (unsigned long)(-num);
		conver->sign = 1;
	}
	else
		unum = (unsigned long long) num;
	ft_itobase(unum, str, BASE_10);
	len = ft_strlen(str);
	*precision_pad = 0;
	if (conver->precision > len)
	{
		*precision_pad = conver->precision - len;
		len += *precision_pad;
	}
	if (conver->plus || conver->sign || conver->space)
		len++;
	return (len);
}

static int	ft_print_left_aligned(t_conversion *conver, char *str,
		int precision_pad, int len)
{
	int	ret;

	ret = ft_print_sign(conver);
	ret += ft_print_padding(precision_pad, '0');
	ret += write(STDOUT, str, ft_strlen(str));
	ret += ft_print_padding(conver->width - len, ' ');
	return (ret);
}

static int	ft_print_right_aligned(t_conversion *conver, char *str,
		int precision_pad, int len)
{
	int	ret;

	ret = 0;
	if (!conver->zero || conver->dot)
		ret += ft_print_padding(conver->width - len, ' ');
	ret += ft_print_sign(conver);
	if (conver->zero && !conver->dot)
		ret += ft_print_padding(conver->width - len, '0');
	ret += ft_print_padding(precision_pad, '0');
	ret += write(STDOUT, str, ft_strlen(str));
	return (ret);
}

int	ft_print_int(t_conversion *conver)
{
	int			ret;
	char		str[INT_STR_MAX_LEN];
	int			len;
	long		num;
	int			precision_pad;

	ret = 0;
	len = 0;
	precision_pad = 0;
	num = va_arg(conver->args, int);
	if (conver->dot && conver->precision == 0 && num == 0)
		return (ft_print_padding(conver->width, ' '));
	len = ft_prepare_number(num, str, conver, &precision_pad);
	if (conver->dash)
		ret = ft_print_left_aligned(conver, str, precision_pad, len);
	else
		ret = ft_print_right_aligned(conver, str, precision_pad, len);
	return (ret);
}
/*
static int	print_sign(t_conversion *conver)
{
	int	ret;

	ret = 0;
	if (conver->sign)
		ret += write(STDOUT, "-", 1);
	if (conver->plus && !conver->sign)
		ret += write(STDOUT, "+", 1);
	if (conver->space && !conver->plus && !conver->sign)
		ret += write(STDOUT, " ", 1);
	return (ret);
}

static int	eval_sign(t_conversion *conver, char *str, int padding)
{
	int	ret;

	ret = 0;
	if (conver->dash)
	{
		ret += print_sign(conver);
		ret += write(STDOUT, str, ft_strlen(str));
		ret += ft_print_padding(padding, ' ');
	}
	else if (conver->zero)
	{
		ret += ft_print_padding(padding, '0');
		ret += print_sign(conver);
		ret += write(STDOUT, str, ft_strlen(str));
	}
	else
	{
		ret += ft_print_padding(padding, ' ');
		ret += print_sign(conver);
		ret += write(STDOUT, str, ft_strlen(str));
	}
	return (ret);
}

int	ft_print_int(t_conversion *conver)
{
	int			ret;
	char		str[65];
	int			len;
	long long	num;

	ret = 0;
	num = va_arg(conver->args, int);
	if (conver->precision == 0 && num == 0)
		return (ft_print_padding(conver->width, ' '));
	if (num < 0)
	{
		num = (unsigned long long)(-num);
		conver->sign = 1;
	}
	ft_itobase(num, str, BASE_10);
	len = ft_strlen(str);
	if (conver->dot && conver->precision > len)
		len = conver->precision;
	if (conver->plus || conver->sign || conver->space)
		len++;
	ret += eval_sign(conver, str, conver->width - len - conver->sign);
	return (ret);
}*/
