/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   ft_printhex.c                                   |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: saladuit <safoh@student.codam.nl>          //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/07/20 20:17:50 by saladuit     /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/20 20:17:53 by saladuit     \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_printhex(size_t *len, unsigned int ui)
{
	char	*result;

	result = ft_uitoh(ui);
	ft_putstr_fd(result, 1);
	*len += ft_strlen(result);
	free(result);
	return ;
}
