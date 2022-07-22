/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   ft_put2d_fd.c                                   |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/06/23 15:11:38 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/14 20:48:22 by saladuit     \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put2d_fd(char **s2d, int fd, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		ft_putendl_fd(s2d[i], fd);
		i++;
	}
	return ;
}