#include <stdio.h>
#include<stdlib.h>

struct Node { 
 	int value;
	struct Node *next;
} Node;

struct list{		
	struct Node* start;	
} list;

int isEmpty(struct list* spissokk)
{
	return spissokk->start==NULL;
}

struct Node* find(struct list* spissokk,int value)
{
	struct Node *tmp=spissokk->start;
	while(tmp->value!=value){
		if(tmp->next!=NULL)
			tmp=tmp->next;
		else
			return 0;
	}
	return tmp;
}

void init(struct list* spissokk,int value)
{
	struct Node* tmp;
	tmp = (struct Node*)malloc(sizeof(struct Node));
	tmp->value=value;
	tmp->next=NULL;
	spissokk->start = tmp;
}

int push_back(struct list* spissokk, int x)
{
	if(isEmpty(spissokk)==1)
		init (spissokk,x);
	else
	{
		struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));
		tmp->value=x;
		tmp->next=NULL;
		struct Node* temp = spissokk->first;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=tmp;
	}
	return 0;
}

int push_front(struct list* spissokk,int x) 
{
	if(isEmpty(spissokk)==1)
		init (spissokk,x);
	else
	{
		struct Node *tmp = (struct Node*)malloc(sizeof(struct Node));
		tmp->value=x;
		tmp->next=spissokk->first;
		spissokk->start=tmp;
	}
	return 0;
}

int clear(struct list* spissokk)
{
	if(isEmpty(spissokk)==1)
	{
		struct Node *tmp=spissokk->start;
		struct Node *temp=NULL;
		while(tmp!=NULL)
		{
			temp=tmp->next;
			free(tmp);
			tmp=temp;
		}
		spissokk->start=NULL;
	}
}

void _remove(struct list* spissokk, struct Node *tmp){
	if(tmp!=NULL){
		if (tmp==spissokk->start)
			spissokk->start=tmp->next;
		else
		{
			struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
			temp=spissokk->start;
			while(temp->next!=tmp)
				temp=temp->next;
			temp->next = tmp->next;
		}
		free(tmp);
	}
}

int removeFirst(struct list* spissokk, int x)
{
	struct Node* element = find(spissokk,x);
	if (element!=NULL){
		_remove(spissokk,element);
		return 0;
	}
	return -1;
}

int insertAfter	(struct list* spissokk,int num, int value)
{
	struct Node *temp = malloc(sizeof(Node));
	temp->value=value;

	struct Node* tmp = spissokk->start;
	struct Node* prev_tmp = spissokk->start;
	
	for (int i = 1;i<num+1;i++)
	{
		prev_tmp=tmp;
		tmp=tmp->next;
		if(tmp==NULL) 
			return -1;
	}
	prev_tmp->next=temp;
	temp->next=tmp;
	return 0;   
}

void print(struct list* spissokk)
{
	struct Node* tmp=spissokk->start;
	while(tmp->next!=NULL)
	{
		printf("%d ", tmp->value);
		tmp=tmp->next;
	}
	printf("%d\n", tmp->value);
}

int main()
{
	int n,a;
    struct list* list=(struct list*)malloc(sizeof(struct list));	
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a);
		push_back(list,a);
	}
	print(list);
	
	int k[3];
        scanf("%d%d%d",&k[0],&k[1],&k[2]);
	for(int i=0;i<3;i++){
		if(find(list,k[i])!=NULL)
			printf("1 ");
		else
			printf("0 ");
	}
	printf("\n");

	int m;
	scanf("%d",&m);
	push_back(list,m);
	print(list);

	int t;
	scanf("%d",&t);
	push_front(list,t);
	print(list);

	int j,x;
	scanf("%d%d",&j,&x);
	insertAfter(list,j,x);
	print(list);

	int z;
	scanf("%d",&z);
	removeFirst(list,z);
	print(list);

	clear(list);
	return 0;
}
