/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: saladin <saladin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 02:51:30 by saladin       #+#    #+#                 */
/*   Updated: 2021/01/04 12:16:06 by saladin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*needle;
	char	*haystack;
	size_t	i;
	size_t	j;

	i = 0;
	needle = (char *)little;
	haystack = (char *)big;
	if (little == 0 || *little == 0 || len == 0)
		return ((*little == 0) ? (char *)big : NULL);
	while (i < len && haystack[i])
	{
		if (haystack[i] == *needle)
		{
			j = 0;
			while (j + i < len && haystack[i + j] == needle[j])
			{
				j++;
				if (!needle[j])
					return (haystack + i);
			}
		}
		i++;
	}
	return (NULL);
}
