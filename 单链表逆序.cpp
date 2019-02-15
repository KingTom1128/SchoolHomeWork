#include <stdio.h>
#include <stdlib.h>

typedef struct Lnode{
    int data;
    struct Lnode *next;
}Lnode, *linklist;

void init(linklist &L)
{
    L = (linklist)malloc(sizeof(Lnode));
    L -> next = NULL;
}

void insert(linklist L, int i, int e)
{
    int j = 0;
    linklist s, p = L;
    s = (linklist)malloc(sizeof(Lnode));
    while(p && j < i - 1)
    {
        ++ j;
        p = p -> next;
    }
    s -> data = e;
    s -> next = p ->next;
    p -> next = s;
}

int length(linklist L)
{
    linklist p = L -> next;
    int j = 1;
    while(p)
        j++;
    return j;
}

void print(linklist L)
{
    linklist p = L -> next;
    while(p)
    {
        printf("%d ", p -> data);
        p = p ->next;
    }
}

int print_result(linklist L)
{
    int sum = 0;
    linklist p = L -> next;
    while(p)
    {
        sum += p -> data;
        p = p -> next;
    }
    return sum;
}

int reverse(linklist &L)
{
	linklist p,q,r;
    if(!L -> next)
        return 1;
	p = L -> next;
	q = p -> next;
    if(!q)
        return 1;
	r = q -> next;
	p -> next = NULL;
	while(r)
    {
		q -> next = p;
		p = q;
		q = r;
		r = q -> next;
	}
	q -> next = p;
	L -> next = q;
    return 1;
}



int main()
{
    int n, i, e, sum;
    linklist L;
    init(L);
    scanf("%d", &n);
    for(i = 1; i <= n; i ++)
    {
        scanf("%d", &e);
        insert(L, i, e);
    }
    sum = print_result(L);
    reverse(L);
    print(L);
    printf("\n%d", sum);
    return 0;
}
