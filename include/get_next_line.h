/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   get_next_line.h                                 |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
<<<<<<< HEAD
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/07/19 22:23:35 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/19 22:24:05 by safoh        \___)=(___/                 */
=======
/*   By: saladuit <safoh@student.codam.nl>          //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/07/20 20:19:34 by saladuit     /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/07/20 20:27:37 by saladuit     \___)=(___/                 */
>>>>>>> cccbef6916c0f5281339922ae5d1f94da9551cb3
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif
<<<<<<< HEAD
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"
=======
# include <libft.h>
# include <fcntl.h>
# include <stdio.h>

>>>>>>> cccbef6916c0f5281339922ae5d1f94da9551cb3

typedef struct s_line
{
	ssize_t	b_read;
	char	*tmp;
}	t_line;

int		get_next_line(int fd, char **line);
<<<<<<< HEAD
//char	*ft_strdup(const char *s);
//size_t	ft_strlen(const char *s);
//char	*ft_strnew(size_t size);
//char	*ft_substr(char const *s, unsigned int start, size_t len);
//void	*ft_memcpy(void *dest, const void *src, size_t n);
=======
>>>>>>> cccbef6916c0f5281339922ae5d1f94da9551cb3

#endif
