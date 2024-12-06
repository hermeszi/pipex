/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:06:19 by myuen             #+#    #+#             */
/*   Updated: 2024/07/24 18:53:42 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void	ft_bzero_conversion(t_conversion *conversion)
{
	conversion->width = 0;
	conversion->precision = -1;
	conversion->dash = 0;
	conversion->zero = 0;
	conversion->dot = 0;
	conversion->hash = 0;
	conversion->space = 0;
	conversion->plus = 0;
	conversion->sign = 0;
}

int	ft_printf(const char *format, ...)
{
	int				ret;
	size_t			i;
	t_conversion	conver;

	if (!format)
		return (-1);
	ft_bzero_conversion(&conver);
	va_start (conver.args, format);
	i = -1;
	ret = 0;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			ret += ft_set_specifiers(&conver, format, &i);
			ft_bzero_conversion(&conver);
		}
		else
			ret += write(STDOUT, &format[i], 1);
	}
	va_end(conver.args);
	return (ret);
}

int	ft_fprintf(int fd, const char *format, ...)
{
	int				ret;
	size_t			i;
	t_conversion	conver;

	if (!format)
		return (-1);
	ft_bzero_conversion(&conver);
	va_start (conver.args, format);
	i = -1;
	ret = 0;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			ret += ft_set_specifiers(&conver, format, &i);
			ft_bzero_conversion(&conver);
		}
		else
			ret += write(fd, &format[i], 1);
	}
	va_end(conver.args);
	return (ret);
}
/*
#include <stdio.h>
#include <limits.h>
#include "./libftprintf/ft_printf.h"
int	main(void)
{
	char *str = "bonjour";
	printf("%c%sl%co, %s.\nI am %0100d 
			years old.\n", 72, "e", 'l', "world", 31);
	ft_printf("%c%sl%co, %s.\nI am %0100d 
			years old.\n", 72, "e", 'l', "world", 31);
	printf("at the address %p, the string %10.12s is stored\n", str, str);
	ft_printf("at the address %p, the string %10.12s is stored\n", str, str);

	printf("  ||  %i\n", printf(" NULL %s NULL", (char *)NULL));
	printf("  ||  %i\n", ft_printf(" NULL %s NULL", (char *)NULL));
  	printf("  ||  %i\n", ft_printf("%p", NULL));
  	printf("  ||  %i\n", printf("%p", NULL));
	printf("%p %p \n", (void *) (void *) 0 , (void *)0);
	ft_printf("%p %p \n", (void *) (void *) 0 , (void *)0);
	printf("  ||  %i\n", ft_printf(" %x ", 0));
	printf("  ||  %i\n", printf(" %x ", 0));
	ft_printf("  %%%%  \n");
	printf("  %%%%  \n");

	printf("  ||  %i\n", ft_printf("\x01\x02\a\v\b\f\r"));
	printf("  ||  %i\n", printf("\x01\x02\a\v\b\f\r"));

	printf("  ||  %i\n", ft_printf(""));
	printf("  ||  %i\n", printf(""));

	printf("  ||  %i\n", ft_printf("%%c"));
	printf("  ||  %i\n", printf("%%c"));

	printf("  ||  %i\n", ft_printf("%%%%%%"));
	printf("  ||  %i\n", printf("%%%%%%"));

	printf("  ||  %i\n", ft_printf("%%%c", 'x'));
	printf("  ||  %i\n", printf("%%%c", 'x'));

	printf("  ||  %i\n", ft_printf("%cc%cc%c", 'a', '\t', 'b'));
	printf("  ||  %i\n", printf("%cc%cc%c", 'a', '\t', 'b'));

	printf("  ||  %i\n", ft_printf("%s", (char *)NULL));
	printf("  ||  %i\n", printf("%s", (char *)NULL));

	printf("  ||  %i\n", ft_printf("%sx", "{} al$#@@@^&$$^#^@@^$*((&"));
	printf("  ||  %i\n", printf("%sx", "{} al$#@@@^&$$^#^@@^$*((&"));

	printf("  ||  %i\n", ft_printf(" %s", "can it handle \t and \n?"));
	printf("  ||  %i\n", printf(" %s", "can it handle \t and \n?"));

	printf("  ||  %i\n", ft_printf("%u", UINT_MAX));
	printf("  ||  %i\n", printf("%u", UINT_MAX));

	printf("  ||  %i\n", ft_printf("%u", -6000023));
	printf("  ||  %i\n", printf("%u", -6000023));

	printf("  ||  %i\n", ft_printf("%X", UINT_MAX));
	printf("  ||  %i\n", printf("%X", UINT_MAX));

	printf("  ||  %i\n", ft_printf("%pp", (void *)LONG_MAX + 423856));
	printf("  ||  %i\n", printf("%pp", (void *)LONG_MAX + 423856));
	printf("  ||  %i\n", ft_printf("%pp", (void *)INT_MAX));
	printf("  ||  %i\n", printf("%pp", (void *)INT_MAX));
	printf("  ||  %i\n", ft_printf("%pp", (void *)0));
	printf("  ||  %i\n", printf("%pp", (void *)0));

	printf("  ||  %i\n", ft_printf("0x%p-", (void *)ULONG_MAX));
	printf("  ||  %i\n", printf("0x%p-", (void *)ULONG_MAX));

	printf("  ||  %i\n", ft_printf("%p", (void *)-14523));
	printf("  ||  %i\n", printf("%p", (void *)-14523));

	printf("  ||  %i\n", ft_printf("%p", ""));
	printf("  ||  %i\n", printf("%p", ""));

	printf("  ||  %i\n", ft_printf("%-d", INT_MIN));
	printf("  ||  %i\n", printf("%-d", INT_MIN));
	
	ft_printf("%-20i\n", 12);
	printf("%-20i\n", 12);
	
	printf("%i\n", ft_printf("%#020X\n", INT_MAX));
	printf("%i\n", printf("%#020X\n", INT_MAX));
	
	printf("%i\n", ft_printf("%+020i\n", INT_MIN));
	printf("%i\n", printf("%+020i\n", INT_MIN));
	
	printf("%i\n", ft_printf("%+020i\n", INT_MAX));
	printf("%i\n", printf("%+020i\n", INT_MAX));
	
	printf("%i\n", ft_printf("% 020i\n", INT_MIN));
	printf("%i\n", printf("% 020i\n", INT_MIN));
}
*/
