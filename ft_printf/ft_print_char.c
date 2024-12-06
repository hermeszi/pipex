/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:26:26 by myuen             #+#    #+#             */
/*   Updated: 2024/07/24 18:53:18 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_print_char(t_conversion *conver)
{
	int		ret;
	int		padding;
	char	c;

	ret = 0;
	c = (char)va_arg(conver->args, int);
	padding = conver->width - 1;
	if (conver->dash)
	{
		ret += write(STDOUT, &c, 1);
		ret += ft_print_padding(padding, ' ');
	}
	else
	{
		ret += ft_print_padding(padding, ' ');
		ret += write(STDOUT, &c, 1);
	}
	return (ret);
}
