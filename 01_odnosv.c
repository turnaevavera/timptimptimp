#include <stdio.h>
#include<stdlib.h>

struct pampam {
 	int znachenie;
	struct pampam *next;
} pampam;

struct listt{
	struct pampam* p;
} listt;

int isEmpty(struct listt* tadam)
{
	return tadam->p==NULL;
}

struct pampam* find(struct listt* tadam,int znachenie)
{
	struct pampam *t=tadam->p;
	while(t->znachenie!=znachenie){
		if(t->next!=NULL)
			t=t->next;
		else
			return 0;
	}
	return t;
}
void init(struct listt* tadam,int znachenie)
{
	struct pampam* t;
	t = (struct pampam*)malloc(sizeof(struct pampam));
	t->znachenie=znachenie;
	t->next=NULL;
	tadam->p = t;
}
int push_back(struct listt* tadam, int x)
{
	if(isEmpty(tadam)==1)
		init (tadam,x);
	else
	{
		struct pampam* t = (struct pampam*)malloc(sizeof(struct pampam));
		t->znachenie=x;
		t->next=NULL;
		struct pampam* tm = tadam->p;
		while(tm->next!=NULL)
			tm=tm->next;
		tm->next=t;
	}
	return 0;
}
int push_front(struct listt* tadam,int x) 
{
	if(isEmpty(tadam)==1)
		init (tadam,x);
	else
	{
		struct pampam *t = (struct pampam*)malloc(sizeof(struct pampam));
		t->znachenie=x;
		t->next=tadam->p;
		tadam->p=t;
	}
	return 0;
}
int clear(struct listt* tadam)
{
	if(isEmpty(tadam)==1)
	{
		struct pampam *t=tadam->p;
		struct pampam *tm=NULL;
		while(t!=NULL)
		{
			tm=t->next;
			free(t);
			t=tm;
		}
		tadam->p=NULL;
	}
}
void _remove(struct listt* tadam, struct pampam *t){
	if(t!=NULL){
		if (t==tadam->p)
			tadam->p=t->next;
		else
		{
			struct pampam *tm = (struct pampam*)malloc(sizeof(struct pampam));
			tm=tadam->p;
			while(tm->next!=t)
				tm=tm->next;
			tm->next = t->next;
		}
		free(t);
	}
}
int removeFirst(struct listt* tadam, int x)
{
	struct pampam* elem = find(tadam,x);
	if (tadam!=NULL){
		_remove(tadam,elem);
		return 0;
	}
	return -1;
}
int insertAfter	(struct listt* tadam,int num, int znachenie)
{
	struct pampam *tm = malloc(sizeof(pampam));
	tm->znachenie=znachenie;

	struct pampam* t = tadam->p;
	struct pampam* prev_t = tadam->p;

	for (int i = 1;i<num+1;i++)
	{
		prev_t=t;
		t=t->next;
		if(t==NULL)
			return -1;
	}
	prev_t->next=tm;
	tm->next=t;
	return 0;
}
void print(struct listt* tadam)
{
	struct pampam* t=tadam->p;
	while(t->next!=NULL)
	{
		printf("%d ", t->znachenie);
		t=t->next;
	}
	printf("%d\n", t->znachenie);
}
int main()
{
	int n,a;
    struct listt* listt=(struct listt*)malloc(sizeof(struct listt));
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a);
		push_back(listt,a);
	}
	print(listt);

	int k[3];
        scanf("%d%d%d",&k[0],&k[1],&k[2]);
	for(int i=0;i<3;i++){
		if(find(listt,k[i])!=NULL)
			printf("1 ");
		else
			printf("0 ");
	}
	printf("\n");
	int m;
	scanf("%d",&m);
	push_back(listt,m);
	print(listt);

	int t;
	scanf("%d",&t);
	push_front(listt,t);
	print(listt);

	int j,x;
	scanf("%d%d",&j,&x);
	insertAfter(listt,j,x);
	print(listt);

	int z;
	scanf("%d",&z);
	removeFirst(listt,z);
	print(listt);

	clear(listt);
	return 0;
}
