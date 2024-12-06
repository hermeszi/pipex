/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_conversion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:13:28 by myuen             #+#    #+#             */
/*   Updated: 2024/07/24 18:56:33 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_process_conversion(t_conversion *conver, const char *format, size_t *pos)
{
	int	ret;

	ret = 0;
	if (format[*pos] == 'c')
		ret += ft_print_char(conver);
	else if (format[*pos] == 's')
		ret += ft_print_string(conver);
	else if (format[*pos] == 'd' || format[*pos] == 'i')
		ret += ft_print_int(conver);
	else if (format[*pos] == 'p')
		ret += ft_print_pointer(conver);
	else if (format[*pos] == 'u')
		ret += ft_print_unsigned(conver);
	else if (format[*pos] == 'x')
		ret += ft_print_hex(conver, "0x");
	else if (format[*pos] == 'X')
		ret += ft_print_hex(conver, "0X");
	else if (format[*pos] == '%')
		ret += ft_print_escape();
	else
		return (-1);
	return (ret);
}
