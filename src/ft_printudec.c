/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   ft_printudec.c                                  |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: saladuit <safoh@student.codam.nl>          //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/07/20 20:15:44 by saladuit     /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/20 20:15:46 by saladuit     \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_printudec(size_t *len, unsigned int n)
{
	ft_putuint_fd(n, 1);
	*len += ft_numlen(n);
	return ;
}
