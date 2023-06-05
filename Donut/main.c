#include "main.h"

int main()
{
    donut();
    return 0;
}

void donut()
{
    float A = 0, B = 0;
    float z[1760];
    char b[1760];
    printf("\x1b[2j");
    while (1)
    {
        memset(b, 32, 1760);
        memset(z, 0, 7040);
        for (float j = 0; j < 6.28; j += 0.07)
        {
            for (float i = 0; i < 6.28; i += 0.02)
            {
                float c = sin(i), d = cos(j);
                float e = sin(A), f = sin(j);
                float g = cos(A), h = d + 2;
                float D = 1 / (c * h * e + f * g + 5);
                float l = cos(i), m = cos(B);
                float n = sin(B);
                float t = c * h * g - f * e;
                int x = 40 + 30 * D * (1 * h * m - t * n);
                int y = 12 + 15 * D * (1 * h * n + t * m);
                int o = x + 80 * y;
                int N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);
                if (22 > y && y > 0 && x > 0 && 80 > x && D > z[o])
                {
                    z[o] = D;
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }
            }
        }
        printf("\x1b[H");
        for (int k = 0; k < 1761; k++)
        {
            putchar(k % 80 ? b[k] : 10);
            A += 0.00004;
            B += 0.00002;
        }
        usleep(30000);
    }
}
