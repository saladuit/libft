#include "ft_printf.h"
#include "libft.h"

void	ft_printpnt(size_t *len, unsigned long ul)
{
	char	*result;

	ft_putstr_fd("0x", 1);
	result = ft_ultoh(ul);
	ft_putstr_fd(result, 1);
	*len += ft_strlen(result) + 2;
	free(result);
	return ;
}
