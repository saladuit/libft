/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: saladin <saladin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 02:51:11 by saladin       #+#    #+#                 */
/*   Updated: 2021/01/05 14:29:17 by saladin       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_arraycount(char const *s, char c)
{
	int				count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			while (*s != c && *s)
				s++;
			count++;
		}
		else
			s++;
	}
	return (count);
}

static	char	**ft_deletearray(char **array, size_t len)
{
	while (len)
	{
		len--;
		free(array[len]);
	}
	free(array);
	return (NULL);
}

static	char	**ft_createarray(char **array, char const *s, char c)
{
	size_t			i;
	size_t			j;
	size_t			len;

	i = 0;
	j = 0;
	while (s[i])
		if (s[i] != c)
		{
			len = 0;
			while (s[i] != c && s[i])
			{
				i++;
				len++;
			}
			array[j] = ft_substr(s, i - len, len);
			if (!array[j])
				return (ft_deletearray(array, j));
			j++;
		}
		else
			i++;
	array[j] = (void *)'\0';
	return (array);
}

char			**ft_split(char const *s, char c)
{
	char			**split;

	if (!s)
		return (NULL);
	split = (char **)malloc((ft_arraycount(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split = ft_createarray(split, s, c);
	return (split);
}
