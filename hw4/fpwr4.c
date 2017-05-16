#include <stdlib.h>

static float u2f(unsigned u)
{
    unsigned* uptr = (unsigned*) malloc(sizeof(unsigned));
    *uptr = u;
    float* fptr = (float*) uptr;
    float f = *fptr;
    free(fptr);
    return f;
}

float fpwr4(int x)
{
    unsigned exp, frac;
    unsigned u;

    if (x < -74)
    {
        exp = 0;
        frac = 0;
    }

    else if (x < -63)
    {
        exp = 0;
        frac = 1 << (149 + 2 * x);
    }
    
    else if (x < 64)
    {
        exp = x * 2 + 127;
        frac = 0;
    }

    else
    {
        exp = 0xff;
        frac = 0;
    }
    u = exp << 23 | frac;
    return u2f(u);
}

int main()
{
    float f = fpwr4(32);
    return 1;
}
