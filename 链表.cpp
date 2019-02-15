#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define LIST_INIT_SIZE 10
#define LIST_CREMENT 2
#define OVERFLOW -2
typedef int ElemType;
typedef int Status;
struct LNode
{
    ElemType data;
    LNode *next;
};
typedef LNode *LinkList;

void InitList(LinkList &L)
{
    L = (LinkList*)malloc(sizeof(LNode));
    if(!L) exit (OVERFLOW);
    L -> next = NULL;
}

void Destroy List(LinkList &L)
{
    LinkList q;
    while(L)
    {
        q = L -> next;
        free(p);
        L = q;
    }
}

void ClearList(LinkList L)
{
    LinkList p = L -> next;
    L - > next = NULL;
    Destroy(p);
}

Status ListEmpty(LinkList L)
{
    if(L -> next)
        return FALSE;
    else 
        return TRUE;
}

Status ListLengh(LinkList L)
{
    int i = 0;
    LinkList p = L -> next;
    while(p)
    {
        i ++;
        p = p -> next;
    }
    return i;
}

Status GetElem(LinkList L, int i, ElemType &e)
{
    int j = 1;
    LinkList p = L -> next;
    while(p && j < i)
    {
        j ++;
        p = p-> next;
    }
    if(!p || j > 1) return ERROR;
    e = p -> data;
    return OK;
}

Status LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType))
{
    int i = 0;
    LinkList p = L -> next;
    while(p)
    {
        i ++;
        if(compare(p -> data, e))
            return i;
        p = p -> next;
    }
    return 0;
}
Status compare(ElemType a, ElemType b)
{
    if(a == b)
        return TRUE;
    else 
        return FALSE;
}

Status PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e)
{
    LinkList q, p = L -> next;
    while(p && p -> next)
    {
        q = p -> next;
        if(q -> data == cur_e)
        {
            pre_e = p -> data;
            return OK;
        }
        p = q;
    }
    return ERROR;
}

Status NextElem(LinkList L, ElemType cur_e, ElemType &next_e)
{
    LinkList p = L -> next;
    while(p && p -> next)
    {
        if(q -> data)
        {
            next_e = p -> next -> data;
            return OK;
        }
        p = p -> next;
    }
    return ERROR;
}

Status ListInsert(LinkList L, int i, ElemType e)
{
    int j = 0;
    LinkList s, p = L;
    while(p && j < i - 1)
    {
        j ++;
        p = p -> next;
    }
    if(!p || j > i - 1) return ERROR;
    s = (LinkList)malloc(sizeof(LNode));
    s -> data = e;
    s -> next = p -> next;
    p -> next = s;
    return OK;
}

Status ListDelete(LinkList L, int i, ElemType &e)
{
    int j = 0;
    LinkList q, p = L;
    while(p -> next && j < i - 1)
    {
        j ++;
        p = p -> next;
    }
    if(!p -> next || j > i - 1) return ERROR;
    q = p -> next;
    p -> next = q -> next;
    e = q -> data;
    free(p);
    return OK;
}

void ListTraverse(LinkList L, void(*visit)(ElemType))
{
    LinkList p = L -> next;
    while(p)
    {
        visit(p -> data);
        p = p -> next;
    }
    printf("\n");
}
void visit(ElemType e)
{
    printf("%d", e);
}