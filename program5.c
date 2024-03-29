/*Program to perform Binary Search using iteration*/

#include <stdio.h>
// #include <conio.h>

int binary(int arr[], int low, int high, int key);

int main()
{
  int i, j, temp, key, arr[20], n, loc;

  // clrscr();

  printf("Enter the number of elements: ");
  scanf("%d", &n);

  printf("Enter the elements\n");

  for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  // Bubble Sort The Array
  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - i - 1; j++)
    {
      if (arr[j] >= arr[j + 1])
      {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  printf("Sorted List\n");

  for (i = 0; i < n; i++)
    printf("%d\t", arr[i]);

  printf("\nEnter the search element: ");
  scanf("%d", &key);

  loc = binary(arr, 0, n - 1, key);

  if (loc >= 0)
    printf("%d is found at position %d in sorted list\n", key, loc + 1);
  else
    printf("%d is  not found\n", key);

  // getch();

  return 0;
}

// Binary search iterative function
int binary(int arr[20], int low, int high, int item)
{
  int mid;

  while (low <= high)
  {
    mid = (low + high) / 2;

    if (item == arr[mid])
      return (mid);
    else if (item > arr[mid])
      low = mid + 1;
    else
      high = mid - 1;
  }

  return -1;
}