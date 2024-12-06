/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 20:00:53 by myuen             #+#    #+#             */
/*   Updated: 2024/07/24 18:54:04 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

#define HEX_STR_MAX_LEN 17

static int	ft_calculate_length_and_padding(t_conversion *conver, \
	char *str, unsigned int num)
{
	int	len;

	len = ft_strlen(str);
	if (conver->dot && conver->precision > len)
		len = conver->precision;
	if (conver->hash && num != 0)
		len += 2;
	return (conver->width - len);
}

static void	ft_convert_to_hex(unsigned int num, char *str, char *prefix)
{
	if (prefix[1] == 'X')
		ft_itobase(num, str, UPPERCASE_16);
	else
		ft_itobase(num, str, LOWERCASE_16);
}

static int	ft_print_formatted_hex(t_conversion *conver, char *str, \
	char *prefix, unsigned int num)
{
	int		ret;
	char	pad_char;
	int		padding;

	ret = 0;
	padding = ft_calculate_length_and_padding(conver, str, num);
	if (!conver->zero || conver->dot)
		pad_char = ' ';
	else
		pad_char = '0';
	if (!conver->dash && padding > 0)
		ret += ft_print_padding(padding, pad_char);
	if (conver->hash && num != 0)
		ret += write(STDOUT, prefix, ft_strlen(prefix));
	if (conver->dot)
		ret += ft_print_padding(conver->precision - ft_strlen(str), '0');
	ret += write(STDOUT, str, ft_strlen(str));
	if (conver->dash && padding > 0)
		ret += ft_print_padding(padding, ' ');
	return (ret);
}

int	ft_print_hex(t_conversion *conver, char *prefix)
{
	char			str[HEX_STR_MAX_LEN];
	unsigned int	num;
	int				ret;

	ret = 0;
	num = va_arg(conver->args, unsigned int);
	if (conver->precision == 0 && num == 0)
		return (ft_print_padding(conver->width, ' '));
	ft_convert_to_hex(num, str, prefix);
	ret = ft_print_formatted_hex(conver, str, prefix, num);
	return (ret);
}
/*
	if (!conver->dash && padding > 0 && (!conver->zero || conver->dot))
		ret += ft_print_padding(padding, ' ');
	if (conver->hash && num != 0)
		ret += write(STDOUT, prefix, ft_strlen(prefix));
	if (!conver->dash && padding > 0 && conver->zero && !conver->dot)
		ret += ft_print_padding(padding, '0');
	if (conver->dot)
		ret += ft_print_padding(conver->precision - ft_strlen(str), '0');
*/
