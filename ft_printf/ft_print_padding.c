/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_padding.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:16:02 by myuen             #+#    #+#             */
/*   Updated: 2024/07/24 18:54:42 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_print_padding(int width, char pad_char)
{
	int	ret;

	ret = 0;
	while (width-- > 0)
		ret += write(STDOUT, &pad_char, 1);
	return (ret);
}
