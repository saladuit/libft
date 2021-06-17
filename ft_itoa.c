/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: saladin <saladin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 02:50:50 by saladin       #+#    #+#                 */
/*   Updated: 2021/01/04 16:02:55 by saladin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_itoa_strlen(int n)
{
	int						len;

	len = (n <= 0) ? 1 : 0;
	while (n)
	{
		++len;
		n /= 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	long	long	int		buffer;
	size_t					len;
	char					*alnum;

	buffer = n;
	len = ft_itoa_strlen(n);
	alnum = malloc(len + 1);
	if (!alnum)
		return (0);
	alnum[len - 1] = '\0';
	if (n == 0)
		*alnum = '0';
	if (n < 0)
	{
		*alnum = '-';
		buffer *= -1;
	}
	alnum[len] = '\0';
	while (buffer)
	{
		len--;
		alnum[len] = (buffer % 10) + '0';
		buffer /= 10;
	}
	return (alnum);
}
