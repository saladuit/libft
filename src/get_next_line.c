/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   get_next_line.c                                 |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: saladuit <safoh@student.codam.nl>          //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/07/20 20:15:11 by saladuit     /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/21 23:51:49 by saladuit     \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
}

int	get_next_line(int fd, char **line)
{
	static char	*saved[FOPEN_MAX] = {NULL};
	char		buffer[BUFFER_SIZE + 1];
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
}
