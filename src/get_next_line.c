/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   get_next_line.c                                 |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: saladuit <safoh@student.codam.nl>          //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/07/20 20:15:11 by saladuit     /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/20 20:15:16 by saladuit     \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
}

int	get_next_line(int fd, char **line)
{
	static char	*saved[FOPEN_MAX] = {NULL};
	char		buffer[BUFFER_SIZE + 1];
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
}
