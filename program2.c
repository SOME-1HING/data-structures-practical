#include <stdio.h>

void main()
{
  int a, b, res;

  // clrscr();

  printf("\nGreatest Common Divisor\n");

  printf("Enter the value for a : ");
  scanf("%d", &a);

  printf("Enter the value for b : ");
  scanf("%d", &b);

  res = gcd(a, b);

  printf("The Greatest Common Divisor of %d and %d is %d", a, b, res);

  // getch();
}

int gcd(int a, int b)
{
  if (a == b)
    return a;
  else
  {
    if (a > b)
      return gcd(a - b, b);
    else
      return gcd(a, b - a);
  }
}