/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   ft_printstr.c                                   |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: saladuit <safoh@student.codam.nl>          //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/07/20 20:15:56 by saladuit     /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/20 20:15:59 by saladuit     \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_printstr(size_t *len, char *string)
{
	if (!string)
	{
		ft_putstr_fd("(null)", 1);
		*len += ft_strlen("(null)");
	}
	ft_putstr_fd(string, 1);
	if (string)
		*len += ft_strlen(string);
	return ;
}
