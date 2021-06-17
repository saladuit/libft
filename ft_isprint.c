/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: saladin <saladin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 02:45:37 by saladin       #+#    #+#                 */
/*   Updated: 2020/11/18 13:37:37 by saladin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_isprint(int c)
{
	return ((unsigned int)c >= 32 && (unsigned int)c <= 126) ? (1) : (0);
}
