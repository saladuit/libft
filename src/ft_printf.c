/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                     |o_o || |                */
/*                                                     +:+                    */
/*   By: safoh <safoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/11 15:03:31 by safoh         #+#    #+#                 */
/*   Updated: 2022/07/20 20:09:58 by saladuit     \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printpars(const char *format, size_t *len, va_list ap)
{
	size_t	i;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			ft_cnvspc(format[i + 1], len, ap);
			i += 2;
		}
		else
		{
			ft_printchr(len, format[i]);
			i++;
		}
	}
	return ;
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	len;

	len = 0;
	if (!format)
		return (0);
	va_start(ap, format);
	printpars(format, &len, ap);
	va_end(ap);
	return (len);
}
