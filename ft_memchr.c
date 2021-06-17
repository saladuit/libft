/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: saladin <saladin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 02:50:54 by saladin       #+#    #+#                 */
/*   Updated: 2021/01/14 20:37:28 by saladin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned	const	char	*chrp;
	unsigned	char			chr;

	chrp = s;
	chr = c;
	while (0 < n)
	{
		if (*chrp == chr)
			return ((void *)chrp);
		chrp++;
		n--;
	}
	return (NULL);
}
