// Program to sort a list of N elements using Bubble Sort

#include <stdio.h>
// #include <conio.h>

int main()
{
  int n, i, j, temp, a[100];

  // clrscr();

  printf("Enter the size of array: ");
  scanf("%d", &n);

  printf("\nEnter the elements\n");

  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);

  printf("Entered array is\n");

  for (i = 0; i < n; i++)
    printf("%d\t", a[i]);

  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - i - 1; j++)
    {
      if (a[j] >= a[j + 1])
      {
        temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
  }

  printf("\nSorted array is\n");

  for (i = 0; i < n; i++)
    printf("%d\t", a[i]);

  // getch();

  return 0;
}