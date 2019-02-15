#include<stdio.h>
 #include<stdlib.h>
 #define LIST_INIT_SIZE 100
 #define LISTINCREMENT 10
 #define OVERFLOW -2
 #define ERROR 0
 #define OK 1
typedef int Status;
typedef int ElemType; 
       typedef struct   LNode { 
               ElemType data;
               struct LNode *next;
       }LNode,*LinkList;
void CreateList_L(LinkList &L,int n){
	LNode *p;
	int i;
	int a[999999];
	for (i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	for (i = n;i > 0;i--)
	{
		p = (LinkList)malloc(sizeof(LNode));
		p->data = a[i];
		p->next = L->next;
		L->next = p;
    }
}
Status InitList_L(LinkList &L)
{
	L = (LinkList)malloc(sizeof(LNode));
	if (L == 0)
	exit(OVERFLOW);
	L->next = NULL;
	return OK;
}
Status ListInsert_L(LinkList &L, int i, ElemType e)
{
	LNode *p, *s;
	int j;
	p = L; j = 0;
	while (p && j < i-1)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i-1) return ERROR;
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}
void add(linklist &La,linklist &Lb,linklist &Lc)
{
	linklist pa,pb,pc;
	pa=La->next;
	pb=Lb->next;
	Lc=pc=La;
	while(pa&&pb)
	{
		if(pa->data<=pb->data)
		{
			pc->next=pa;
			pc=pa;
			pa=pa->next;
		}
		else
		{
			pc->next=pb;pc=pb;pb=pb->next;
		}
		pc->next=pa?pa:pb;
		free(Lb);
	}
}

int main()
{
	ElemType e, e1, e2;
	int n, m, k;
	int i=0,sum=0;
	int a[9999];
	LNode *p;
	LinkList La,Lb,Lc;	
	La = NULL;
	Lb = NULL;
	Lc = NULL;
	InitList_L(La);
	InitList_L(Lb);
	InitList_L(Lc);
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{scanf("%d",&e),ListInsert_L(La,i,e);}
	for(i=1;i<=m;i++)
	{scanf("%d",&e),ListInsert_L(Lb,i,e);}
	Merge_L(La,Lb,Lc);
	p=Lc->next;i=1;	
	while(p)
	{
		printf("%d ",p->data);
		i=-i;
		if(i<0)sum+=p->data;
		p=p->next;
	}
	printf("\n%d\n",sum);
	return 0;
}