#include "fractol.h"

void	error(void)
{
	perror("memory allocation fails");
	exit(EXIT_FAILURE);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!*s || fd < 0)
		return;
	write(fd, s,ft_strlen(s));
}

int ft_strncmp(char *s1, char *s2, int n)
{
	if (!*s1 || !*s2 || n <= 0)
		return (0);
	while (*s1 == *s2 && *s1 != '\0' && n > 0)
	{
		++s1;
		++s2
		--n;
	}
	return (*s1 - *s2);
}

double	atodbl(char *s)
{
	long	int_part = 0;
	double	fract_part = 0;
	double	pow = 1;
	int		sign = 1;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '+' | *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
		int_part = (int_part * 10) + (*s++ - '0');
	if (*s == '.')
	{
		s++;
		while (*s >= '0' && *s <= '9')
		{
			pow /= 10;
			fract_part += (*s++ - '0') * pow;
		}
	}
	return ((int_part + fract_part) * sign);
}
/*
int main(void)
{
	char	str[] = "-123.456";
	double	result = atodbl(str);
	printf("converted double value is : %f\n", result);
	return (0);
}
*/
