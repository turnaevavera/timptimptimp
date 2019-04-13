#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>
#include <string.h>

typedef struct list
{
  int data;
  struct list * left;
  struct list * right;
  struct list * mamapapa;
} 
list;

typedef struct derevo
{
  struct list * square;   
  int count;            
} 
derevo;

void init(derevo * t)
{
    struct derevo * new_tree = malloc(sizeof new_tree);
    new_tree->square = NULL;
    new_tree->count = 0;
    t = new_tree;
}

int find(derevo* t, int ciferki, list* l)
{
  struct list * ll;
  ll = t->square;
  if (t->square == NULL)
  {
    return 1;
  }
  while (1)
  {
    if (ll == NULL) 
	{
      return 1;
    } else if (ll->data == ciferki)
	{
      l->data = ll->data;
      l->left = ll->left;
      l->right = ll->right;
      l->mamapapa = ll->mamapapa;
      return 0;
    } else if (ciferki > ll->data)
	{
      ll = ll->right;
    } else 
	{
      ll = ll->left;
    }
  }
  return 1;
}

int insert(derevo* t, int ciferki)
{
  struct list * l, ** ll, * lll = NULL;
  struct list * yes;
  yes = malloc(sizeof * yes);
  int error = find(t, ciferki, yes);
  if (error == 0)
  {
    return 1;
  }
  ll = &t->square;
  l = t->square;
  while (1){
    if (l == NULL)
	{
      l = *ll = malloc(sizeof * l);
      if (l != NULL)
	  {
        l->data = ciferki;
        l->left = NULL;
        l->right = NULL;
        l->mamapapa = lll;
        t->count++;
        return 0;
      }
	  else 
	  {
        return 2; 
      }
    }
    lll = l;  
    if (ciferki > l->data)
	{
      ll = &l->right;
      l = l->right;
    } 
	else
	{
      ll = &l->left;
      l = l->left;
    }
  }
  return 0;
}

int glubinadereva(struct list * l, int deep)
{
  if (l == NULL)
  {
    return deep;
  }
  int depth1 = glubinadereva(l->left, deep + 1);
  int depth2 = glubinadereva(l->right, deep + 1);
  return (depth1 > depth2) ? depth1 : depth2;
}

void printList(struct list * l, int current, int deep, int first)
{
  if (current == deep)
  {
      if (first > 0)
	  {
        printf(" ");
      }
      
    if (l == NULL)
	{
      printf("_");
    } else{
      printf("%d", l->data);
    } 
  } 
  else if (l != NULL)
  {
    printList(l->left, current + 1, deep, first);
    printList(l->right, current + 1, deep, first + 1);
  } 
  else 
  {
    printList(l, current + 1, deep, first);
    printList(l, current + 1, deep, first + 1);
  }
}

void print(struct list * l)
{
  int m = glubinadereva(l, 0);
  for (int i = 1; i <= m; i++){
    printList(l, 1, i, 0);
    printf("\n");
  }
}   

void printTree(struct derevo * t)
{
    print(t->square);
}
 
void print_round3(struct derevo * t)
{
    list * a[15];
    int var1 = 0;
    list * write[15];
    int var2 = 0;
    list * l = t->square;
    while (var2 < t->count)
	{ 
        while (l != NULL)
		{
            var2++;
            if (l->right != NULL)
			{
                var1++;
                a[var1] = l->right;
            }
            write[var2] = l;
            l = l->left; 
        }
        l = a[var1];
        var1 -= 1;   
    }
    int derevoplus = 0;
    for (int i = 1; i <= var2; i++)
	{
        if (derevoplus > 0)
		{
            printf(" ");
        } 
		else
		{
            derevoplus++;
        }
        printf("%d", write[i]->data);
    }   
  printf("\n");
}   

int main()
{
  struct derevo * t = malloc(sizeof t);
  init(t);
  for (int i = 0; i < 7; i++)
  {
    int a;
    scanf("%d", &a);
    insert(t, a);
  }
  print_round3(t);
  return 0;
}
