#include <stdio.h>
#include <math.h>

double myround(double x)
{
	int tmp = (int)x;
	if (x >= 0) {
		if (x - tmp >= 0.5)
			x = ceil(x);
		else
			x = floor(x);
	} else {
		if (x - tmp > -0.5)
			x = ceil(x);
		else
			x = floor(x);	
	}

	return x;
}

int main(void)
{
	double tmp = 0.0;
	double f = myround(tmp);
	printf("%.1lf\n", f);
	return 0;
}
