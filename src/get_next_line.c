/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   get_next_line.c                                 |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: saladuit <safoh@student.codam.nl>          //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/07/20 20:15:11 by saladuit     /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/20 22:01:48 by saladuit     \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			gnl_verify_line(char **stack, char **line)
{
	char			*tmp_stack;
	char			*strchr_stack;
	int				i;

	i = 0;
	strchr_stack = *stack;
	while (strchr_stack[i] != '\n')
		if (!strchr_stack[i++])
			return (0);
	tmp_stack = &strchr_stack[i];
	*tmp_stack = '\0';
	*line = ft_strdup(*stack);
	*stack = ft_strdup(tmp_stack + 1);
	return (1);
}

static	int			gnl_read_file(int fd, char *heap, char **stack, char **line)
{
	int				ret;
	char			*tmp_stack;

	while ((ret = read(fd, heap, BUFFER_SIZE)) > 0)
	{
		heap[ret] = '\0';
		if (*stack)
		{
			tmp_stack = *stack;
			*stack = ft_strjoin(tmp_stack, heap);
			free(tmp_stack);
			tmp_stack = NULL;
		}
		else
			*stack = ft_strdup(heap);
		if (gnl_verify_line(stack, line))
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
	int			ret;

	if (!line || (fd < 0 || fd >= FOPEN_MAX) || BUFFER_SIZE <= 0 ||\
			(read(fd, buffer, BUFFER_SIZE) < 0))
		return (-1);
	if (saved[fd])
		if (gnl_verify_line(&saved[fd], line))
			return (1);
	ret = gnl_read_file(fd, buffer, &saved[fd], line);
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
