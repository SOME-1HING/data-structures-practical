/*Program to search an element in an array of integers using sequential search*/

#include <stdio.h>
// #include <conio.h>

int main()
{
  int n, i, item, arr[10];

  // clrscr();

  printf("Enter the number of elements: ");
  scanf("%d", &n);

  printf("\nEnter the elements\n");

  for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  printf("\nThe entered list is:\n");

  for (i = 0; i < n; i++)
    printf("%d\t", arr[i]);

  printf("\nEnter the item to search: ");
  scanf("%d", &item);

  for (i = 0; i < n; i++)
  {
    if (arr[i] == item)
    {
      printf("%d is found at index %d.\n", item, i);

      // getch();

      return 0;
    }
  }

  printf("\n%d is not found in the list.\n", item);

  // getch();

  return 0;
}