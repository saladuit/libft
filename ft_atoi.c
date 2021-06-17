/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: saladin <saladin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 18:50:33 by saladin       #+#    #+#                 */
/*   Updated: 2021/02/22 10:55:26 by saladin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	bool	ft_checkspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_atoi(const char *nptr)
{
	long long int	nbr;
	int				sign;

	nbr = 0;
	sign = 1;
	while (ft_checkspace(*nptr))
		nptr++;
	if (*nptr == '-')
	{
		sign = -sign;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr && ft_isdigit(*nptr))
	{
		if (nbr * sign < -2147483648 || nbr * sign > 2147483647)
			return (sign < 0 ? 0 : -1);
		nbr = nbr * 10 + *nptr - '0';
		nptr++;
	}
	return ((int)nbr * sign);
}
