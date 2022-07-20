/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printchr.c                                   |o_o || |                */
/*                                                     +:+                    */
/*   By: safoh <safoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/26 18:29:48 by safoh         #+#    #+#                 */
/*   Updated: 2022/07/20 20:09:20 by saladuit     \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_printchr(size_t *len, int c)
{
	ft_putchar_fd(c, 1);
	*len += 1;
	return ;
}
