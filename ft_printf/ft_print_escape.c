/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_escape.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 20:36:42 by myuen             #+#    #+#             */
/*   Updated: 2024/07/24 18:53:31 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_print_escape(void)
{
	int		ret;

	ret = 0;
	ret += write(STDOUT, "%", 1);
	return (ret);
}
/*not need for any treatment
int	ft_print_escape(t_conversion *conver)
{
	int		ret;
	int		padding;

	ret = 0;
	padding = conver->width - 1;
	if (conver->dash)
	{
		ret += write(STDOUT, "%", 1);
		ret += ft_print_padding(padding, ' ');
	}
	else
	{
		ret += ft_print_padding(padding, ' ');
		ret += write(STDOUT, "%", 1);
	}
	return (ret);
}
*/
