/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: saladin <saladin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 02:51:01 by saladin       #+#    #+#                 */
/*   Updated: 2020/11/10 16:00:01 by saladin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char *ptr;

	ptr = (char*)s;
	while (n > 0)
	{
		(ptr)[n - 1] = ((char)c);
		n--;
	}
	return (s);
}
