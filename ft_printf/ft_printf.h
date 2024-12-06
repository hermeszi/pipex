/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:39:30 by myuen             #+#    #+#             */
/*   Updated: 2024/07/24 18:53:54 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define ISCONVERSION "cspdiuxX%"
# define ISFLAG "-0# +"
# define UPPERCASE_16 "0123456789ABCDEF"
# define LOWERCASE_16 "0123456789abcdef"
# define BASE_10 "0123456789"

typedef struct s_conversion
{
	va_list	args;
	int		width;
	int		precision;
	int		dash;
	int		zero;
	int		dot;
	int		hash;
	int		space;
	int		plus;
	int		sign;
}	t_conversion;

/*/////////////////////////////////////////////////////
//	(re)set struct according to %conversion format	/// 
/////////////////////////////////////////////////////*/
int				ft_set_specifiers(t_conversion *conver, \
				const char *format, size_t *pos);
/*/////////////////////////////////////////////////////
//		eval and print %conversions 				/// 
/////////////////////////////////////////////////////*/
int				ft_process_conversion(t_conversion *conver, \
				const char *format, size_t *pos);
int				ft_print_char(t_conversion *conver);
int				ft_print_string(t_conversion *conver);
int				ft_print_int(t_conversion *conver);
int				ft_print_unsigned(t_conversion *conver);
int				ft_print_pointer(t_conversion *conver);
int				ft_print_hex(t_conversion *converc, char *prefix);
int				ft_print_escape(void);
/*/////////////////////////////////////////////////////
//		 			mis	/// 
/////////////////////////////////////////////////////*/
void			ft_itobase(unsigned long long value, \
				char *str, char *symbols);
int				ft_print_padding(int width, char pad_char);
/*/////////////////////////////////////////////////////
//		 		ft_printf							/// 
/////////////////////////////////////////////////////*/
int				ft_printf(const char *format, ...);
int				ft_fprintf(int fd, const char *format, ...);

#endif
/*
------------------>     -	    <-----------------------
The converted value is to be left adjusted on the field boundary.  
(The default is right justification.)  
The converted value is padded on the right with blanks, 
rather than on the left with blanks or zeros.
A - overrides a 0 if both are given.

 ---------------->      0       <--------------------- 
The value should be zero padded.  For d, i, o, u, x, X, a,
A, e, E, f, F, g, and G conversions, the converted value
is padded on the left with zeros rather than blanks.  If
the 0 and - flags both appear, the 0 flag is ignored.  If
a precision is given with an integer conversion (d, i, o,
u, x, and X), the 0 flag is ignored.

 ---------------->      .       <--------------------- 
An optional precision, in the form of a period ('.')  followed by
an optional decimal digit string.  Instead of a decimal digit
a string one may write "*" or "*m$" (for some decimal integer m) to
specify that the precision is given in the next argument, or in
the m-th argument, respectively, which must be of type int.  

Ifthe precision is given as just '.', the precision is taken to be
zero. 

A negative precision is taken as if the precision were
omitted.

This gives the minimum number of digits to appear for
d, i, o, u, x, and X conversions, the number of digits to appear
after the radix character for a, A, e, E, f, and F conversions,
the maximum number of significant digits for g and G conversions,
or the maximum number of characters to be printed from a string
for s and S conversions.

----------------->     #     <------------------------------     
The value should be converted to an "alternate form".  For
o conversions, the first character of the output string is
made zero (by prefixing a 0 if it was not zero already).
For x and X conversions, a nonzero result has the string
"0x" (or "0X" for X conversions) prepended to it.  For a,
A, e, E, f, F, g, and G conversions, the result will
always contain a decimal point, even if no digits follow
it (normally, a decimal point appears in the results of
those conversions only if a digit follows).  For g and G
conversions, trailing zeros are not removed from the
result as they would otherwise be.  For m, if errno
contains a valid error code, the output of
strerrorname_np(errno) is printed; otherwise, the value
stored in errno is printed as a decimal number.  For other
conversions, the result is undefined.

-------------------->   +   <------------------------
A sign (+ or -) should always be placed before a number
produced by a signed conversion.  By default, a sign is
used only for negative numbers.  A + overrides a space if
both are used.

--------------->     ' ' (a space)    <-------------
A blank should be left before a positive number
(or empty string) produced by a signed conversion.
*/
