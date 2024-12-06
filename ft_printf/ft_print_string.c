/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:28:35 by myuen             #+#    #+#             */
/*   Updated: 2024/07/24 18:55:01 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	ft_calculate_length(t_conversion *conver, char *str)
{
	int	len;

	len = ft_strlen(str);
	if (conver->dot)
	{
		if (conver->precision < 0)
			conver->precision = len;
		else if (conver->precision < len)
			len = conver->precision;
	}
	return (len);
}

static char	*ft_handle_null_string(t_conversion *conver)
{
	if (conver->dot && conver->precision < 6)
		return ("");
	else
		return ("(null)");
}

static int	ft_print_string_with_padding(t_conversion *conver, \
	char *str, int len, int padding)
{
	int	ret;

	ret = 0;
	if (conver->dash)
	{
		ret += write(STDOUT, str, len);
		ret += ft_print_padding(padding, ' ');
	}
	else
	{
		ret += ft_print_padding(padding, ' ');
		ret += write(STDOUT, str, len);
	}
	return (ret);
}

int	ft_print_string(t_conversion *conver)
{
	int		ret;
	int		padding;
	int		len;
	char	*str;

	ret = 0;
	str = va_arg(conver->args, char *);
	if (!str)
	{
		str = ft_handle_null_string(conver);
	}
	len = ft_calculate_length(conver, str);
	padding = 0;
	if (conver->width > len)
		padding = conver->width - len;
	ret = ft_print_string_with_padding(conver, str, len, padding);
	return (ret);
}
