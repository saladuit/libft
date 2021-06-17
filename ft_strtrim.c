/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: saladin <saladin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 02:51:34 by saladin       #+#    #+#                 */
/*   Updated: 2021/01/20 08:53:21 by saladin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	*ft_memalloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size);
	return (ptr);
}

static	char	*ft_strnew(size_t size)
{
	char	*str;

	if (size == __SIZE_MAX__)
		return (NULL);
	str = (char *)ft_memalloc(size + 1);
	return (str);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	start;
	size_t	end;
	size_t	len;

	if (!s1)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	if (set == NULL)
		return (ft_strdup(s1));
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	if (start == end)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[end - 1]) && end)
		end--;
	len = (start < end) ? end - start : 0;
	trim = ft_strnew(len);
	if (!trim)
		return (NULL);
	ft_memcpy((void *)trim, &(s1[start]), len);
	return (trim);
}
