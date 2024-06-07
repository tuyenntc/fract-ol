#include "fractol.h"

// implement scaling and ratio:
/*
[0.0 - 1.0] ==> [0.0 - 212.0] ==> x 212
[0.0 - 315.0] ==> [0.0 - 1.0] ==> / 315.0
you can map from any [zero-to-n] range to the range [zero-to-one]
and [zero-to-one] to [zero-to-m] OR simply put you can map [zero-to-n] to [zero-to-m]
and if you add a number x; ==> x-to(m + x)

// remap a random number from 0..1 to 0..10:
f = random() * 10.0;

// remap random number from 0..1 to 15..22:
g = (random() * 7.0) + 15.0;
*/

double	map(double unscaled_num, t_range new, t_range old)
{
	return (((new.max - new.min) * (unscaled_num - old.min) / (old.max - old.min)) + new.min);
}

double	map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
	return ((new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min);
}

/* i^2 = -1
(x + yi)^2 = x^2 + 2*x*yi + (yi)^2 = (x^2 - y^2) + 2*x*yi
real part: (x^2 - y^2)
imaginary part: 2 * x *yi
*/

t_complex	square(t_complex z)
{
	t_complex	result;
	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

t_complex	sum(t_complex z1, t_complex z2)
{
	t_complex	result;
	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}
