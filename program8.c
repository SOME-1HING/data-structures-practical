#include <stdio.h>
#include <conio.h>

#define size 3

void push();
int pop();
void display();

int top = -1, stk[size];

int main()
{
	int ch, item;

	// clrscr();

	while (1)
	{
		printf("\n1.Push\n");
		printf("2.Pop\n");
		printf("3.Display\n");
		printf("4.Exit\n");

		printf("\nEnter ur choice: ");
		scanf("%d", &ch);

		switch (ch)
		{
		case 1:
			if (top == (size - 1))
				printf("Stack full\n");
			else
				push();

			break;

		case 2:
			item = pop();

			if (item != -1)
				printf("Popped element=%d\n", item);

			break;

		case 3:
			display();

			break;

		case 4:
			return 0;

		default:
			printf("Invalid choice\n");
		}
	}

	return 0;
}

void push()
{
	int item;

	printf("Enter the element: ");
	scanf("%d", &item);

	top++;

	stk[top] = item;
}

void display()
{
	int i;

	i = top;

	printf("Stack Contents\n");

	if (i == (-1))
		printf("Empty stack\n");
	else
	{
		while (i != (-1))
		{
			printf("%d\t", stk[i]);

			i--;
		}
	}
}

int pop()
{
	int item;

	if (top == (-1))
	{
		printf("Stack underflow\n");

		return (-1);
	}
	else
	{
		item = stk[top];

		top--;

		return (item);
	}
}