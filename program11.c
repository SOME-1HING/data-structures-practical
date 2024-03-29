#include <stdio.h>
#include <conio.h>

void qinsert();
void qdelete();
void qdisplay();

int queue[10], front = 0, rear = -1;
int max = 3;

int main()
{
  int ch;

  // clrscr();

  do
  {
    printf("\n\nLINEAR QUEUE OPERATIONS\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
      qinsert();
      break;
    case 2:
      qdelete();
      break;
    case 3:
      qdisplay();
      break;
    case 4:
      return 0;
    default:
      printf("WRONG CHOICE");
    }
  } while (ch != 4);

  return 0;
}

void qinsert()
{
  int item;

  if (rear == max - 1)
    printf("Queue is full");
  else
  {
    printf("Enter the item to insert: ");
    scanf("%d", &item);

    rear++;
    queue[rear] = item;
  }
}

void qdelete()
{
  int item;

  if (front == rear + 1)
    printf("Queue is empty");
  else
  {
    item = queue[front];

    printf("%d is deleted", item);

    front++;
  }
}

void qdisplay()
{
  int item;
  int p = front;

  if (p == rear + 1)
    printf("Queue is empty");
  else
  {
    printf("Queue Elements: ");

    while (p <= rear)
    {
      printf("%d\t", queue[p]);

      p++;
    }
  }
}