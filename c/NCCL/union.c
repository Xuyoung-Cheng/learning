#include <stdio.h>

#define DEBUG 0

struct test_struct
{
    int n;
    char test[4];
};

typedef union test
{
    int n;
    unsigned char test[4];
    float f;
}test_t;

int main(void)
{
    test_t t;
    test_t u;

    printf("does your machine use little-endian\n");

#if DEBUG
    printf("[DEBUG] - sizeof struct test_struct: < %d >\n", sizeof(struct test_struct));
    printf("[DEBUG] - sizeof union  test       : < %d >\n", sizeof(union test));
#endif

    /* little-endian: 0x78 56 34 12 */
    /* big-endian   : 0x12 34 56 78 */
    t.n = 0x12345678;
    printf("test[0] = 0x%x\n", t.test[0]);
    printf("test[1] = 0x%x\n", t.test[1]);
    printf("test[2] = 0x%x\n", t.test[2]);
    printf("test[3] = 0x%x\n", t.test[3]);

    printf("t.n = 0x%x\n", t.n);

    t.test[0] = 0x99;
    printf("t.n = 0x%x\n", t.n);

    t.f = 1.0;
    printf("test[0] = 0x%x\n", t.test[0]);
    printf("test[1] = 0x%x\n", t.test[1]);
    printf("test[2] = 0x%x\n", t.test[2]);
    printf("test[3] = 0x%x\n", t.test[3]);
    printf("t.n = 0x%x\n", t.n);

    u.n = 0x3f800000;
    printf("u.f = %f\n", u.f);

    return 0;
}