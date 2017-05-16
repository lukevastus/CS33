#include <stdio.h>

int main()
{
  int x = 2147483647;
  int y = -2147483648;
  double dx = (double) x;
  double dy = (double) y;
  double ddx = (dx * dx) * dy;
  double dddx = dx * (dx * dy);
  printf("%d", ddx == dddx);
}
