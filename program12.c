#include <stdio.h>
#include <stdlib.h>

struct node
{
  int rollno;
  char name[20];
  struct node *link;
};

struct node *start = NULL, *p, *q, *prev;

void create();
void display();
void ins_beg();
void ins_end();
void ins_pos();
void del_item();
void search();

int main()
{
  int ch, regno;

  printf("1. Create a linked list\n");
  printf("2. Insert a node at the beginning\n");
  printf("3. Insert a node at the end\n");
  printf("4. Insert a node at a given position\n");
  printf("5. Delete a node by roll number\n");
  printf("6. Search for a node by roll number\n");
  printf("7. Display linked list\n");
  printf("8. Exit\n");

  while (1)
  {
    printf("\nEnter your choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
      create();
      break;
    case 2:
      printf("\nLinked list before insertion:\n");
      display();
      ins_beg();
      printf("\nLinked list after insertion:\n");
      display();
      break;
    case 3:
      printf("\nLinked list before insertion:\n");
      display();
      ins_end();
      printf("\nLinked list after insertion:\n");
      display();
      break;
    case 4:
      printf("\nLinked list before insertion:\n");
      display();
      ins_pos();
      printf("\nLinked list after insertion:\n");
      display();
      break;
    case 5:
      printf("\nThe linked list is:\n");
      display();
      printf("\nEnter the roll number to delete: ");
      scanf("%d", &regno);
      del_item(regno);
      printf("\nLinked list after deletion:\n");
      display();
      break;
    case 6:
      printf("\nEnter the roll number to search: ");
      scanf("%d", &regno);
      search(regno);
      break;
    case 7:
      display();
      break;
    case 8:
      return 0;
    default:
      printf("\nInvalid choice\n");
    }
  }
  return 0;
}

void create()
{
  char choice = 'y';

  start = NULL;

  while (choice == 'y')
  {
    p = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter the roll number & name: ");
    scanf("%d %s", &p->rollno, p->name);

    p->link = NULL;

    if (start == NULL)
      start = p;
    else
    {
      q = start;
      while (q->link != NULL)
        q = q->link;
      q->link = p;
    }

    printf("\nDo you want to create another node? (y/n): ");
    scanf(" %c", &choice);
  }
}

void display()
{
  printf("\nNodes in the list are:\nSTART -> ");

  p = start;

  while (p != NULL)
  {
    printf("%d %s -> ", p->rollno, p->name);
    p = p->link;
  }

  printf("NULL\n");
}

void ins_beg()
{
  p = (struct node *)malloc(sizeof(struct node));

  printf("\nEnter register number: ");
  scanf("%d", &p->rollno);

  printf("Enter name of student: ");
  scanf("%s", p->name);

  p->link = start;
  start = p;
}

void ins_end()
{
  p = (struct node *)malloc(sizeof(struct node));

  printf("\nEnter register number: ");
  scanf("%d", &p->rollno);

  printf("Enter name of student: ");
  scanf("%s", p->name);

  p->link = NULL;

  if (start == NULL)
    start = p;
  else
  {
    q = start;
    while (q->link != NULL)
      q = q->link;
    q->link = p;
  }
}

void ins_pos()
{
  int pos;

  printf("\nEnter the position to insert the new node: ");
  scanf("%d", &pos);

  if (pos == 1)
    ins_beg();
  else
  {
    q = start;
    for (int i = 1; i < pos - 1 && q != NULL; i++)
      q = q->link;

    if (q == NULL)
      printf("\nPosition out of range\n");
    else
    {
      p = (struct node *)malloc(sizeof(struct node));

      printf("\nEnter register number: ");
      scanf("%d", &p->rollno);

      printf("Enter name of student: ");
      scanf("%s", p->name);

      p->link = q->link;
      q->link = p;
    }
  }
}

void del_item(int regno)
{
  p = start;
  prev = NULL;

  if (start == NULL)
  {
    printf("\nLinked list is empty\n");
    return;
  }

  if (start->rollno == regno)
  {
    start = start->link;
    free(p);
    return;
  }

  while (p != NULL && p->rollno != regno)
  {
    prev = p;
    p = p->link;
  }

  if (p == NULL)
    printf("\nRoll number %d not found\n", regno);
  else
  {
    prev->link = p->link;
    free(p);
  }
}

void search(int regno)
{
  int i = 1;
  p = start;

  while (p != NULL)
  {
    if (regno == p->rollno)
    {
      printf("\nRoll no %d found at position %d\n", p->rollno, i);
      printf("Name: %s\n", p->name);
      return;
    }
    else
    {
      p = p->link;
      i++;
    }
  }

  printf("\nNode with register number %d does not exist\n", regno);
}
