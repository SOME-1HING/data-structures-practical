#include <stdio.h>
int fac(int x)
{
  if (x == 0 || x == 1)
    return 1;

  return x * fac(x - 1);
}
int main()
{
  int n, r;

  printf("Enter the value of n: ");
  scanf("%d", &n);

  printf("Enter the value of r: ");
  scanf("%d", &r);

  if (n < r)
  {
    printf("Invalid input\n");
    return 0;
  }

  printf("The value of %dC%d is %d\n", n, r, fac(n) / (fac(r) * fac(n - r)));

  return 0;
}