#include <stdio.h>
#include <stdlib.h>

typedef struct Lnode
{
    int data;
    struct Lnode *next;
}Lnode,*linklist;

void init(linklist &l)
{
    l=(linklist)malloc(sizeof(Lnode));
    l->next=NULL;
}

void listinsert(linklist l, int i, int e)
{
    int j=0;
    linklist s, p=l;
    while(p&&j<i-1)
    {
        ++j;
        p=p->next;
    }
    s=(linklist)malloc(sizeof(Lnode));
    s->data=e;
    s->next=p->next;
    p->next=s;
}

void add(linklist &la, linklist &lb, linklist &lc)
{
    linklist pa, pb, pc;
    pa=la->next;
    pb=lb->next;
    lc=pc=la;
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
            pc->next=pb;
            pc=pb;
            pb=pb->next;
        }
    }
    pc->next=pa?pa:pb;
    free(lb);
}

void print(linklist l)
{
    linklist p=l->next;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

int main()
{
    int n,e1,e2,i,m;
    linklist la,lb,lc;
    init(la);
    init(lb);
    init(lc);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&e1);
        listinsert(la,i,e1);
    }
    print(la);
    printf("\n");
    for(i=1;i<=m;i++)
    {
        scanf("%d",&e2);
        listinsert(lb,i,e2);
    }
    print(lb);
    printf("\n");
    add(la,lb,lc);
    linklist pc=lc;
    print(lc);
    printf("\n");
    int sum=0;
    while(pc->next)
    {
        i=1;
        if(i%2==1)
            sum+=pc->data;
        i++;
        pc=pc->next;
    }
    printf("%d",sum);
    return 0;
}
