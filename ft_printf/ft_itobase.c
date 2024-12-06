/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itobase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 20:57:53 by myuen             #+#    #+#             */
/*   Updated: 2024/07/24 18:53:06 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void	ft_strrev(char *str)
{
	size_t	i;
	size_t	len;
	char	temp;

	i = 0;
	len = ft_strlen(str);
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
		i++;
	}
}

void	ft_itobase(unsigned long long value, char *str, char *symbols)
{
	size_t	i;
	int		base;

	base = ft_strlen(symbols);
	if (base < 2)
	{
		str[0] = '\0';
		return ;
	}
	if (value == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return ;
	}
	i = 0;
	while (value > 0)
	{
		str[i] = symbols[value % base];
		value /= base;
		i++;
	}
	str[i] = '\0';
	ft_strrev(str);
}
