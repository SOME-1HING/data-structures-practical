#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
  int info;
  struct node *left;
  struct node *right;
};

struct node *root = NULL;

void insert(int);
void create(int);
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);
struct node *search(struct node *, int);

int main()
{
  int ch, item, n;

  while (1)
  {
    // clrscr();

    printf("\nBinary Search Tree");
    printf("\n1.Create");
    printf("\n2.Insert");
    printf("\n3.Inorder Traversal");
    printf("\n4.Preorder Traversal");
    printf("\n5.Postorder Traversal");
    printf("\n6.Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
      printf("\nEnter how many elements: ");
      scanf("%d", &n);
      for (int i = 0; i < n; i++)
      {
        printf("\nEnter the value of the node: ");
        scanf("%d", &item);
        if (search(root, item) != NULL)
        {
          printf("\nItem found and no duplicate value allowed");
          i--;
        }
        else
          create(item);
      }
      break;
    case 2:
      printf("\nEnter an item to insert: ");
      scanf("%d", &item);
      if (search(root, item) != NULL)
        printf("\nItem found and no duplicate value allowed");
      else
        create(item);
      break;
    case 3:
      printf("\nInorder Traversal\n");
      if (root == NULL)
        printf("\nEmpty Binary Search Tree");
      else
        inorder(root);
      break;
    case 4:
      printf("\nPreorder Traversal\n");
      if (root == NULL)
        printf("\nEmpty Binary Search Tree\n");
      else
        preorder(root);
      break;
    case 5:
      printf("\nPostorder Traversal\n");
      if (root == NULL)
        printf("\nEmpty Binary Search Tree\n");
      else
        postorder(root);
      break;
    case 6:
      exit(0);
    }
  }
}

void create(int item)
{
  struct node *newnode, *currptr, *ptr;
  newnode = (struct node *)malloc(sizeof(struct node));
  newnode->info = item;
  newnode->left = NULL;
  newnode->right = NULL;
  if (root == NULL)
    root = newnode;
  else
  {
    currptr = root;
    while (currptr != NULL)
    {
      ptr = currptr;
      currptr = (item > currptr->info) ? currptr->right : currptr->left;
    }
    if (item < ptr->info)
      ptr->left = newnode;
    else
      ptr->right = newnode;
  }
}

void inorder(struct node *ptr)
{
  if (ptr != NULL)
  {
    inorder(ptr->left);
    printf("%d\t", ptr->info);
    inorder(ptr->right);
  }
}

void preorder(struct node *ptr)
{
  if (ptr != NULL)
  {
    printf("%d\t", ptr->info);
    preorder(ptr->left);
    preorder(ptr->right);
  }
}

void postorder(struct node *ptr)
{
  if (ptr != NULL)
  {
    postorder(ptr->left);
    postorder(ptr->right);
    printf("%d\t", ptr->info);
  }
}

struct node *search(struct node *ptr, int item)
{
  if (ptr == NULL)
    return NULL;
  else if (item < ptr->info)
    return search(ptr->left, item);
  else if (item > ptr->info)
    return search(ptr->right, item);
  else
    return ptr;
}
