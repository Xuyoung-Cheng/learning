#include <stdio.h>
#include <math.h>

enum coordinate_type { RECTANGULAR, POLAR };

struct complex_struct {
	enum coordinate_type t;
	double a, b;
};

struct complex_struct
make_from_real_img(double x, double y)
{
	struct complex_struct z;
	z.t = RECTANGULAR;
	z.a = x;
	z.b = y;
	return z;
}

struct complex_struct
make_from_mag_ang(double r, double A)
{
	struct complex_struct z;
	z.t = POLAR;
	z.a = r;
	z.b = A;
	return z;
}

double real_part(struct complex_struct z)
{
	if (z.t == RECTANGULAR) {
		return z.a;
	} else {
		return z.a * cos(z.b);	
	}
}

double img_part(struct complex_struct z)
{
	if (z.t == RECTANGULAR)
		return z.b;
	else
		return z.a * sin(z.b);
}

double magnitude(struct complex_struct z)
{
	if (z.t == POLAR)
		return z.a;
	else
		return sqrt(z.a*z.a + z.b*z.b);
}

double angle(struct complex_struct z)
{
	if (z.t == POLAR)
		return z.b;
	else
		return atan2(z.a, z.b);
}

