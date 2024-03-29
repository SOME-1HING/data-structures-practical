#include <stdio.h>
#include <conio.h>
#include <string.h>

void convertIp(char infix[50], char postfix[50]);

int main()
{
  char ans = 'y', postfix[50], infix[50];

  while ((ans == 'y') || (ans == 'Y'))
  {
    infix[0] = '\0';
    postfix[0] = '\0';

    convertIp(infix, postfix);

    printf("\n\nDo you want to continue? : ");
    scanf(" %c", &ans);

    fflush(stdin);
  }

  return 0;
}

void convertIp(char infix[50], char postfix[50])
{
  char ch;
  int i, len, top = 0;

  postfix[0] = '(';

  printf("\nEnter infix expression: ");
  scanf("%[^\n]s", infix);

  len = strlen(infix);

  printf("postfix Expression: ");

  for (i = 0; i < len; i++)
  {
    ch = infix[i];

    if (((ch >= '0') && (ch <= '9')) || ((ch >= 'a') && (ch <= 'z')) || ((ch >= 'A') && (ch <= 'Z')))
      printf("%c", ch);

    if (ch == '(')
      postfix[++top] = ch;

    if ((ch == '*') || (ch == '/'))
    {
      while ((postfix[top] == '*') || (postfix[top] == '/'))
        printf("%c", postfix[top--]);

      postfix[++top] = ch;
    }

    if ((ch == '+') || (ch == '-'))
    {
      while ((postfix[top] == '*') || (postfix[top] == '/') || (postfix[top] == '+') || (postfix[top] == '-'))
        printf("%c", postfix[top--]);

      postfix[++top] = ch;
    }

    if (ch == ')')
    {
      while (postfix[top] != '(')
        printf("%c", postfix[top--]);

      top--;
    }
  }

  while (postfix[top] != '(')
    printf("%c", postfix[top--]);
}