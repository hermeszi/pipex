/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:06:10 by myuen             #+#    #+#             */
/*   Updated: 2024/07/24 18:55:47 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

#define NIL_STR_LEN 6
#define PTR_STR_MAX_LEN 17

int	ft_print_null_pointer(t_conversion *conver)
{
	int		ret;
	char	str[NIL_STR_LEN];
	int		len;
	int		padding;

	ret = 0;
	len = 5;
	ft_strlcpy(str, "(nil)", NIL_STR_LEN);
	padding = conver->width - len;
	if (!conver->dash && conver->zero)
		ret += ft_print_padding(padding, '0');
	else if (!conver->dash && !conver->zero)
		ret += ft_print_padding(padding, ' ');
	ret += write(STDOUT, str, len);
	if (conver->dash && padding > 0)
		ret += ft_print_padding(padding, ' ');
	return (ret);
}

int	ft_print_value_pointer(t_conversion *conver, unsigned long value)
{
	int		ret;
	char	str[PTR_STR_MAX_LEN];
	int		len;
	int		padding;

	ft_itobase(value, str, LOWERCASE_16);
	len = ft_strlen(str) + 2;
	padding = conver->width - len;
	ret = 0;
	if (!conver->dash && conver->zero)
		ret += ft_print_padding(padding, '0');
	else if (!conver->dash && !conver->zero)
		ret += ft_print_padding(padding, ' ');
	ret += write(STDOUT, "0x", 2);
	ret += write(STDOUT, str, ft_strlen(str));
	if (conver->dash && padding > 0)
		ret += ft_print_padding(padding, ' ');
	return (ret);
}

int	ft_print_pointer(t_conversion *conver)
{
	unsigned long	value;

	value = (unsigned long) va_arg(conver->args, void *);
	if (value == 0)
		return (ft_print_null_pointer(conver));
	else
		return (ft_print_value_pointer(conver, value));
}

/*
int	ft_print_pointer(t_conversion *conver)
{
	int					ret;
	unsigned long long	value;
	char				str[17];
	int					len;
	int					padding;

	ret = 0;
	value = (unsigned long long) va_arg(conver->args, void *);
	if (value == 0)
	{
		ft_strlcpy(str, "(nil)", 6);
		len = ft_strlen(str);
	}
	else
	{
		ft_itobase(value, str, LOWERCASE_16);
		len = ft_strlen(str) + 2;
	}
	padding = conver->width - len;
	if (!conver->dash && conver->zero)
		ret += ft_print_padding(padding, '0');
	else if (!conver->dash && !conver->zero)
		ret += ft_print_padding(padding, ' ');
	ret += write(STDOUT, "0x", 2);
	ret += write(STDOUT, str, ft_strlen(str));
	if (conver->dash && padding > 0)
		ret += ft_print_padding(padding, ' ');
	return (ret);
}*/
