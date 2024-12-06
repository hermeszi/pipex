/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_specifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:11:34 by myuen             #+#    #+#             */
/*   Updated: 2024/07/24 18:56:58 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void	ft_set_flags(t_conversion *conver, const char *format, size_t *pos)
{
	while (format[*pos] && ft_strchr(ISFLAG, format[*pos]))
	{
		if (format[*pos] == '-')
		{
			conver->dash = 1;
			conver->zero = 0;
		}
		else if (format[*pos] == '0' && !conver->dash)
			conver->zero = 1;
		else if (format[*pos] == '#')
			conver->hash = 1;
		else if (format[*pos] == '+')
		{
			conver->plus = 1;
			conver->space = 0;
		}
		else if (format[*pos] == ' ' && !conver->plus)
			conver->space = 1;
		(*pos)++;
	}
}

static void	ft_set_width(t_conversion *conver, const char *format, size_t *pos)
{
	if (format[*pos] && ft_isdigit(format[*pos]))
	{
		conver->width = ft_atoi(&format[*pos]);
		while (ft_isdigit(format[*pos]))
			(*pos)++;
	}
}

static void	ft_set_precision(t_conversion *conver, \
	const char *format, size_t *pos)
{
	if (format[*pos] && format[*pos] == '.')
	{
		conver->dot = 1;
		(*pos)++;
		conver->precision = ft_atoi(&format[*pos]);
		while (ft_isdigit(format[*pos]))
			(*pos)++;
	}
	if (conver->precision < 0)
		conver->dot = 0;
	if (conver->dot)
		conver->zero = 0;
}

int	ft_set_specifiers(t_conversion *conver, const char *format, size_t *pos)
{
	int		ret;

	ret = 0;
	(*pos)++;
	ft_set_flags(conver, format, pos);
	ft_set_width(conver, format, pos);
	ft_set_precision(conver, format, pos);
	if (ft_strchr(ISCONVERSION, format[*pos]))
		ret = ft_process_conversion(conver, format, pos);
	return (ret);
}
