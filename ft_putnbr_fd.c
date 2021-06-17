/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: saladin <saladin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 02:51:07 by saladin       #+#    #+#                 */
/*   Updated: 2020/12/14 14:55:32 by saladin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	long	long	int	input;
	int					divider;

	input = nb;
	divider = 1;
	if (input < 0)
	{
		ft_putchar_fd('-', fd);
		input *= -1;
	}
	while (nb / 10)
	{
		divider *= 10;
		nb /= 10;
	}
	if (input == 0)
		ft_putchar_fd('0', fd);
	else
		while (divider > 0)
		{
			ft_putchar_fd(input / divider + '0', fd);
			input %= divider;
			divider /= 10;
		}
	return ;
}
