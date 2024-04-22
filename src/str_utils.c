#include "fractol.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	size_t	len;

	len = ft_strlen(s);
	write(fd, s, len);
	write(fd, "\n", 1);
}


int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int i = 0;
	while (n != '\0' && s1[i] && (s1[i] == s2[i]))
	{
		i++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return (*(unsigned char *)&s1[i] - *(unsigned char *)&s2[i]);
}
