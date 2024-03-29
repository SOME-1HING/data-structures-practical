#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

float stack[50];
int top = -1;

float pop();
void push(float item);

int main()
{
  char post[50];
  int i, j;
  float value, n1, n2, final, result;

  printf("Enter a postfix expression: ");
  scanf("%[^\n]s", post);

  j = strlen(post);

  for (i = 0; i < j; i++)
  {
    if ((post[i] >= '0') && (post[i] <= '9'))
      push(post[i] - '0');
    else if (((post[i] >= 'a') && (post[i] <= 'z')) || ((post[i] >= 'A') && (post[i] <= 'Z')))
    {
      printf("Enter the value of %c: ", post[i]);
      scanf("%f", &value);

      push(value);
    }

    else
    {
      n2 = pop();
      n1 = pop();

      switch (post[i])
      {
      case '^':
        result = pow(n1, n2);

        push(result);

        break;

      case '*':
        result = n1 * n2;

        push(result);

        break;

      case '/':
        result = n1 / n2;

        push(result);

        break;

      case '+':
        result = n1 + n2;

        push(result);

        break;

      case '-':
        result = n1 - n2;

        push(result);

        break;

      default:
        printf("\nInvalid postfix expression");
      }
    }
  }

  final = pop();

  printf("\nValue of the expression = %f", final);

  // getch();

  return 0;
}

void push(float item)
{
  stack[++top] = item;

  return;
}

float pop()
{
  float res;

  res = stack[top--];

  return (res);
}
