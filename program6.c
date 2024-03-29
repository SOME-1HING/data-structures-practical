/* Program to perform Selection Sort */

#include <stdio.h>
// #include <conio.h>

int main()
{
  int i, j, small, loc, arr[20], n;

  // clrscr();

  printf("Enter the number of elements: ");
  scanf("%d", &n);

  printf("Enter the elements\n");

  for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  printf("Original list\n");

  for (i = 0; i < n; i++)
    printf("%d\t", arr[i]);

  for (i = 0; i <= n; i++)
  {
    small = arr[i];
    loc = i;

    for (j = i + 1; j < n; j++)
    {
      if (arr[j] < small)
      {
        small = arr[j];
        loc = j;
      }
    }

    arr[loc] = arr[i];
    arr[i] = small;
  }

  printf("\nSorted list\n");

  for (i = 0; i < n; i++)
    printf("%d\t", arr[i]);

  // getch();

  return 0;
}