#include <stdio.h>
#include <stdlib.h>

struct rational {
	int m;	/* molecule */
	int d;  /* denominator */
};

struct rational
make_rational(int a, int b)
{
	struct rational r;
	r.m = a;
	r.d = b;
	return r;
}

int get_m(struct rational r)
{
	return r.m;
}

int get_d(struct rational r)
{
	return r.d;
}

int GCD(int a, int b)
{
	if (b)
		return GCD(b, a%b);
	return a;
}

struct rational
reduce_rational(struct rational r)
{
	int m = get_m(r);
	int d = get_d(r);
	int gcd = GCD(m, d);
	r = make_rational(m/abs(gcd), d/abs(gcd));
	return r;
}

struct rational
add_rational(struct rational r1, struct rational r2)
{
	struct rational r;
	int d1 = get_d(r1);
       	int d2 = get_d(r2);
	int m1 = get_m(r1);
	int m2 = get_m(r2);

	r = make_rational(m1*d2 + m2*d1, d1*d2);
	if (get_m(r) == 0)
		return r;

	r = reduce_rational(r);
	
	return r;
}
struct rational
sub_rational(struct rational r1, struct rational r2)
{
	struct rational r;
	int d1 = get_d(r1);
       	int d2 = get_d(r2);
	int m1 = get_m(r1);
	int m2 = get_m(r2);
	
	r = make_rational(m1*d2 - m2*d1, d1*d2);
	if (get_m(r) == 0)
		return r;

	r = reduce_rational(r);

	return r;
}

struct rational
mul_rational(struct rational r1, struct rational r2)
{
	struct rational r;
	int d1 = get_d(r1);
       	int d2 = get_d(r2);
	int m1 = get_m(r1);
	int m2 = get_m(r2);

	r = make_rational(m1*m2, d1*d2);
	if (get_m(r) == 0)
		return r;

	r = reduce_rational(r);

	return r;
}

struct rational
div_rational(struct rational r1, struct rational r2)
{
	struct rational r;
	int d1 = get_d(r1);
       	int d2 = get_d(r2);
	int m1 = get_m(r1);
	int m2 = get_m(r2);
	
	r = make_rational(m1*d2, d1*m2);
	if (get_m(r) == 0)
		return r;

	r = reduce_rational(r);

	return r;
}

void
print_rational(struct rational r)
{
	if (get_m(r) == 0)
		printf("0\n");
	else
		printf("%d/%d\n", get_m(r), get_d(r));
}

int main(void)
{
	struct rational a = make_rational(1, 8); /* a=1/8 */
	struct rational b = make_rational(-1, 8); /* b=-1/8 */
	print_rational(a);
	print_rational(b);
	print_rational(add_rational(a, b));
	print_rational(sub_rational(a, b));
	print_rational(mul_rational(a, b));
	print_rational(div_rational(a, b));

	return 0;
}
