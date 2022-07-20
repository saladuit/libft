/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printdec.c                                   |o_o || |                */
/*                                                     +:+                    */
/*   By: safoh <safoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 18:28:42 by safoh         #+#    #+#                 */
/*   Updated: 2022/07/20 20:09:47 by saladuit     \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_printdec(size_t *len, int n)
{
	ft_putnbr_fd(n, 1);
	*len += ft_numlen(n);
	if (n < 0)
		(*len)++;
	return ;
}
