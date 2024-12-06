/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:19:22 by myuen             #+#    #+#             */
/*   Updated: 2024/07/24 18:56:10 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	ft_handle_padding(t_conversion *conver, int padding)
{
	if (!conver->dash && padding > 0)
	{
		if (conver->zero && !conver->dot)
			return (ft_print_padding(padding, '0'));
		else
			return (ft_print_padding(padding, ' '));
	}
	return (0);
}

int	ft_print_unsigned(t_conversion *conver)
{
	int				ret;
	char			str[21];
	unsigned int	num;
	int				len;
	int				padding;

	ret = 0;
	num = va_arg(conver->args, unsigned int);
	if (conver->precision == 0 && num == 0)
		return (ft_print_padding(conver->width, ' '));
	ft_itobase(num, str, BASE_10);
	len = ft_strlen(str);
	if (conver->dot && conver->precision > len)
		len = conver->precision;
	padding = conver->width - len;
	ret += ft_handle_padding(conver, padding);
	if (conver->dot)
		ret += ft_print_padding(conver->precision - ft_strlen(str), '0');
	ret += write(STDOUT, str, ft_strlen(str));
	if (conver->dash && padding > 0)
		ret += ft_print_padding(padding, ' ');
	return (ret);
}
