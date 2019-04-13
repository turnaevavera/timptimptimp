#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>
#include <string.h>

typedef struct strr
{
    int data;
    struct strr * left;
  struct strr * right;
  struct strr * parent;
}
strr;

typedef struct derev
{
    struct strr * korr;
  int count;
}
derev;

void init(derev* t)
{
    struct derev * new_derev = malloc(sizeof new_derev);
	new_derev->korr = NULL;
    new_derev->count = 0;
    t = new_derev;
}

int find(derev* t, int zna4, strr* n)
{
  struct strr * strrstrr;
strrstrr = t->korr;
  if (t->korr == NULL)
  {
    return 1;
  }
  while (1)
  {
    if (strrstrr == NULL)
	{
      return 1;
    }
	else if (strrstrr->data == zna4)
	{
      n->data = strrstrr->data;
      n->left = strrstrr->left;
      n->right = strrstrr->right;
      n->parent = strrstrr->parent;
      return 0;
    } 
	else if (zna4 > strrstrr->data)
	{
      strrstrr = strrstrr->right;
    } 
	else 
	{
      strrstrr = strrstrr->left;
    }
  }
  return 1;
}

int insert(derev* t, int zna4)
{
  struct strr * n, ** strrstrr, * last_strr = NULL;
struct strr * en;
en = malloc(sizeof * en);
    
int error = find(t, zna4, en);
  if (error == 0)
  {
    return 1;
  }
  strrstrr = &t->korr;
  n = t->korr;
  while (1)
  {
    if (n == NULL) 
	{
      n = * strrstrr = malloc(sizeof * n);
      if (n != NULL)
	  {
        n->data = zna4;
        n->left = NULL;
        n->right = NULL;
        n->parent = last_strr;
        t->count++;
        return 0;
      } 
	  else 
	  {
        return 2; 
      }
    }
    last_strr = n;  
    if (zna4 > n->data)
	{
      strrstrr = &n->right;
      n = n->right;
    }
	else
	{
      strrstrr = &n->left;
      n = n->left;
    }
  }
  return 0;
}

int depth(struct strr * n, int deep)
{
  if (n == NULL)
  {
    return deep;
  }
    
int depth1 = depth(n->left, deep + 1);
int depth2 = depth(n->right, deep + 1);
return (depth1 > depth2) ? depth1 : depth2;
}

void printstrr(struct strr * n, int current, int deep, int first)
{
  if (current == deep)
  {
      if (first > 0)
	  {
        printf(" ");
      } 
    if (n == NULL)
	{
      printf("_");
    }
	else
	{
      printf("%d", n->data);
    } 
  } 
  else if (n != NULL)
  {
    printstrr(n->left, current + 1, deep, first);
printstrr(n->right, current + 1, deep, first + 1);
  }
  else
	{
    printstrr(n, current + 1, deep, first);
	printstrr(n, current + 1, deep, first + 1);
	}
}

void print(struct strr * n)
{
  int m = depth(n, 0);
  for (int i = 1; i <= m; i++)
  {
  printstrr(n, 1, i, 0);
  printf("\n");
  }
}
   
void printderev(struct derev * t)
{
    print(t->korr);
}

void print_obh1(struct strr * n)
{
  int m = depth(n, 0);
int flag_derev = 0;
  for (int i = 1; i <= m; i++)
  {
    if (flag_derev > 0)
	{
        printf(" ");
    } 
	else 
	{
        flag_derev++;
    }
    printstrr(n, 1, i, 0);
  }
}   

void print_obh2(struct derev * t)
{
    strr* a[15];
int ab = 0;
strr* write[15];
int wb = 0;
strr* n = t->korr;
    while (wb<t->count)
	{ 
        while (n != NULL)
		{
            wb++;
            if (n->right != NULL)
			{
                ab++;
                a[ab] = n->right;
            }
            write[wb] = n;
            n = n->left;
        }
        n = a[ab];
        ab -= 1;    
    }  
    int flag_derev = 0;
    
    for (int i = 1; i <= wb; i++)
	{
        if (flag_derev > 0)
		{
            printf(" ");
        } else {
            flag_derev++;
        }
        printf("%d", write[i]->data);
    } 
  printf("\n");
}   

void print_obh3(struct strr * n, int flag_derev)
{
    if (n->left != NULL)
	{
        print_obh3(n->left, flag_derev + 1);
    } 
    if (n->right != NULL)
	{
        print_obh3(n->right, flag_derev + 1);
    }
    printf("%d", n->data);
    if (flag_derev > 0)
	{
        printf(" ");
    }   
}   

int main()
{
  struct derev * t = malloc(sizeof t);
init(t);
  for (int i = 0; i< 7; i++)
  {
    int a;
scanf("%d", &a);
insert(t, a);
  }
  print_obh3(t->korr, 0);
printf("\n");
  return 0;
}
