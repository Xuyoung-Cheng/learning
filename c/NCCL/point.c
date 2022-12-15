#include <stdio.h>
#include <math.h>

typedef struct point
{
	float x;
	float y;
} point_t;

float calculate(point_t p, point_t p2)
{
	float dx, dy;
	
	dx = p.x - p2.x;
	dy = p.y - p2.y;
	
	return sqrt(dx*dx + dy*dy);
}

int main(void)
{
	point_t p;
	point_t p2 = { 1.5, 2.5 };
	float distance;

	printf("demo structure\n");
	scanf("%f %f", &p.x, &p.y);
	printf("p.x = %.1f, p.y = %.2f\n", p.x, p.y);

	distance = calculate(p, p2);
	printf("distance = %f\n", distance);

#if 0
	printf("sizeof float = %ld\n", sizeof(float));
	printf("sizeof double = %ld\n", sizeof(double));
	printf("sizeof char = %ld\n", sizeof(char));
	printf("sizeof int = %ld\n", sizeof(int));
	printf("sizeof struct point = %ld\n", sizeof(struct point));
#endif

	return 0;
}
