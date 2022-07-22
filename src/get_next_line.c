/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   get_next_line.c                                 |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
<<<<<<< HEAD
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/07/19 16:04:45 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/19 22:25:12 by safoh        \___)=(___/                 */
=======
/*   By: saladuit <safoh@student.codam.nl>          //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/07/20 20:15:11 by saladuit     /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/21 23:51:49 by saladuit     \___)=(___/                 */
>>>>>>> cccbef6916c0f5281339922ae5d1f94da9551cb3
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

<<<<<<< HEAD
//char	*ft_strjoin(char const *s1, char const *s2)
//{
//	size_t	len1;
//	size_t	len2;
//	char	*dest;
//
//	if (!s1 || !s2)
//		return (NULL);
//	len1 = ft_strlen(s1);
//	len2 = ft_strlen(s2);
//	if (len1 + len2 > __SIZE_MAX__ - 1)
//		return (NULL);
//	dest = ft_strnew(len1 + len2);
//	if (!dest)
//		return (NULL);
//	ft_memcpy((void *)dest, s1, ft_strlen(s1));
//	ft_memcpy((void *)&(dest[ft_strlen(s1)]), s2, ft_strlen(s2));
//	return (dest);
//}

//static char	*ft_strchr(const char *s, int c)
//{
//	char	*p;
//
//	if (!s)
//		return (NULL);
//	p = (char *)s;
//	while (*p)
//	{
//		if (*p == c)
//		{
//			return (p);
//		}
//		p++;
//	}
//	if (c == '\0')
//		return (p);
//	return (0);
//}

static int	newline(char **line, char **saved, t_line *data)
{
	size_t	len;

	len = 0;
	while ((*saved)[len] != '\n' && (*saved)[len] != '\0')
		len++;
	if ((*saved)[len] == '\n')
	{
		*line = ft_substr(*saved, 0, len);
		data->tmp = ft_strdup(&((*saved)[len + 1]));
		free(*saved);
		*saved = data->tmp;
	}
	else
	{
		*line = ft_strdup(*saved);
		if (*saved != NULL)
		{
			free(*saved);
			*saved = NULL;
		}
	}
	if (!*line)
		return (-1);
	return (1);
}

static int	output(int fd, char **line, char **saved, t_line *data)
{
	if (data->b_read < 0)
		return (-1);
	else if (data->b_read == 0 && !ft_strchr(saved[fd], '\n'))
	{
		*line = ft_strdup(saved[fd]);
		if (!*line)
		{
			free(saved[fd]);
			saved[fd] = NULL;
			return (-1);
		}
		if (saved[fd] != NULL)
		{
			free(saved[fd]);
			saved[fd] = NULL;
		}
		return (0);
	}
	else
		return (newline(line, &saved[fd], data));
=======
static int			search_and_save(char **saved, char **line)
{
	char			*tmp;
	
	if (!*saved)
		return (0);
	tmp = ft_strchr(*saved, '\n');
	if (*tmp == '\0')
		return (0);
	*tmp = '\0';
	*line = ft_strdup(*saved);
	*saved = ft_strdup(tmp + 1);
	return (1);
}

static	int			read_into_buffer(int fd, char *buffer, char **saved, char **line)
{
	ssize_t		ret;
	char		*tmp_saved;

	while (true)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret < 0)
			break ;
		buffer[ret] = '\0';
		if (*saved)
		{
			tmp_saved = *saved;
			*saved = ft_strjoin(tmp_saved, buffer);
			free(tmp_saved);
			tmp_saved = NULL;
		}
		else
			*saved = ft_strdup(buffer);
		if (search_and_save(saved, line))
			break ;
	}
	if (ret > 0)
		return (1);
	return (ret);
>>>>>>> cccbef6916c0f5281339922ae5d1f94da9551cb3
}

int	get_next_line(int fd, char **line)
{
	static char	*saved[FOPEN_MAX] = {NULL};
	char		buffer[BUFFER_SIZE + 1];
<<<<<<< HEAD
	t_line		data;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	data.b_read = 1;
	while (data.b_read && !ft_strchr(saved[fd], '\n'))
	{
		data.b_read = read(fd, buffer, BUFFER_SIZE);
		if (data.b_read == -1)
			return (-1);
		buffer[data.b_read] = '\0';
		if (saved[fd] == NULL)
			saved[fd] = ft_strdup(buffer);
		else
		{
			data.tmp = ft_strjoin(saved[fd], buffer);
			free(saved[fd]);
			saved[fd] = data.tmp;
		}
		if (!saved[fd])
			return (-1);
	}
	return (output(fd, line, saved, &data));
=======
	ssize_t			ret;

	if (!line || (fd < 0 || fd >= FOPEN_MAX) || BUFFER_SIZE <= 0 ||\
			(read(fd, buffer, BUFFER_SIZE) < 0))
		return (-1);
	if (search_and_save(&saved[fd], line))
		return (1);
	ret = read_into_buffer(fd, buffer, &saved[fd], line);
	if (ret != 0 || saved[fd] == NULL || saved[fd][0] == '\0')
	{
		if (!ret && *line)
			*line = NULL;
		return (ret);
	}
	*line = saved[fd];
	saved[fd] = NULL;
	return (1);
>>>>>>> cccbef6916c0f5281339922ae5d1f94da9551cb3
}
