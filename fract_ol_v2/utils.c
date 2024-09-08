
#include "fractol.h"

void	instructions(void)
{
	ft_printf("\nFractol\n");
	ft_printf("\nMovement: Press keys: W, A, S, D or Left, Right, Up, Down arrows\n");
	ft_printf("To zoom in: Scroll mouse wheel up\n");
	ft_printf("To zoom out: Scroll mouse wheel down\n");
	ft_printf("To switch colours: Press: Space bar\n");
	ft_printf("To increase iterations:	Press key: + (from the number pad)\n");
	ft_printf("To decrease iterations:	Press key: -\n");
	ft_printf("To rotate Julia:	Mouse left or right click\n");
	ft_printf("To quit: Press key: ESC or click X on window, or ^C on command line\n");
	ft_printf("To display julia set, provide 2 values within the range [-2.0 to 2.0]\n");
	ft_printf("\nTry: <./fractol julia -0.4 +0.6> or\n<./fractol julia -0.835 -0.2321>\n");
}

void	malloc_error(void)
{
	perror("MALLOC ERROR: ");
	exit(EXIT_FAILURE);
}

int ft_strncmp(char *s1, char *s2, int n)
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


# include <stdio.h>

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
double	atodbl(char *s)
{
	long	int_part = 0;
	double	fract_part = 0;
	double	pow = 1;
	int		sign = 1;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	if (!ft_isdigit(*s) && *s != '.')
	{
		printf("error: invalid input\n");
		return (0);
	}
	while (ft_isdigit(*s))
		int_part = (int_part * 10) + (*s++ - '0');
	if (*s == '.')
	{
		s++;
		if (!ft_isdigit(*s))
        {
            printf("invalid input\n");
            return 0;
        }
		while (ft_isdigit(*s))
		{
			pow /= 10;
			fract_part += (*s++ - '0') * pow;
		}
	}
	if (*s != '\0')
	{
		printf("invalid input\n");
		return (0);
	}
	return ((int_part + fract_part) * sign);
}
/*
//SHORT ATODBL - breaking into components

#include <stdio.h>

// Function to skip leading whitespace
char *skip_whitespace(char *s) {
    while (*s == 32 || (*s >= 9 && *s <= 13))
        s++;
    return s;
}

// Function to determine the sign and adjust the string pointer
int get_sign(char **s) {
    int sign = 1;
    if (**s == '+' || **s == '-') {
        if (**s == '-')
            sign = -1;
        (*s)++;
    }
    return sign;
}

// Function to convert integer part of the string to a long
long get_integer_part(char **s) {
    long int_part = 0;
    while (**s >= '0' && **s <= '9')
        int_part = (int_part * 10) + (*(*s)++ - '0');
    return int_part;
}

// Function to convert fractional part of the string to a double
double get_fractional_part(char **s) {
    double fract_part = 0, pow = 1;
    if (**s == '.') {
        (*s)++;
        while (**s >= '0' && **s <= '9') {
            pow /= 10;
            fract_part += (*(*s)++ - '0') * pow;
        }
    }
    return fract_part;
}

// Main function to convert a string to a double
double atodbl(char *s) {
    s = skip_whitespace(s);
    int sign = get_sign(&s);
    long int_part = get_integer_part(&s);
    double fract_part = get_fractional_part(&s);
    return (int_part + fract_part) * sign;
}



int main(void)
{
	char	str[] = "-123.456";

	char *test1 = "123.456";
    char *test2 = "-123.456";
    char *test3 = "   +789.123";
    char *test4 = "42";
    char *test5 = "-0.987";
    char *test6 = "   -45.67";
    char *test7 = "   +.42";
    char *test8 = "123abd";
    char *test9 = "abc 123";
    char *test10 = "abc123";

	double	result = atodbl(str);

	printf("converted double value is : %f\n", result);

	printf("Test 1: %s -> %f\n", test1, atodbl(test1));
    printf("Test 2: %s -> %f\n", test2, atodbl(test2));
    printf("Test 3: %s -> %f\n", test3, atodbl(test3));
    printf("Test 4: %s -> %f\n", test4, atodbl(test4));
    printf("Test 5: %s -> %f\n", test5, atodbl(test5));
    printf("Test 6: %s -> %f\n", test6, atodbl(test6));
    printf("Test 7: %s -> %f\n", test7, atodbl(test7));
    printf("Test 8: %s -> %f\n", test8, atodbl(test8));
    printf("Test 9: %s -> %f\n", test9, atodbl(test9));
    printf("Test 10: %s -> %f\n", test10, atodbl(test10));
	return (0);
}

*/
void	zoom_in(t_fractol *fract, double mouse_r, double mouse_i)
{
	double zoomFactor;

	zoomFactor = 0.95;
	fract->shift_r += (mouse_r - fract->shift_r) * (1 - zoomFactor);
	fract->shift_i += (mouse_i - fract->shift_i) * (1 - zoomFactor);
	fract->zoom *= zoomFactor;
}

void	zoom_out(t_fractol *fract, double mouse_r, double mouse_i)
{
	double zoomFactor;

	zoomFactor = 1.01;
	fract->shift_r += (mouse_r - fract->shift_r) * (1 - zoomFactor);
	fract->shift_i += (mouse_i - fract->shift_i) * (1 - zoomFactor);
	fract->zoom *= zoomFactor;
}
