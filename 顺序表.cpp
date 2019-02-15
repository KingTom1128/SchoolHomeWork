//顺序链表
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define LIST_INIT_SIZE 10
#define LIST_CREMENT 2
#define OVERFLOW -2
typedef int ElemType;
typedef int Status;
struct Sqlist
{
    ElemType *elem;
    int length;
    int listlize;
};

void InitList(Sqlist &L)
{
    L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(L.elem) return ERROR;
    L.length = 0;
    L.listlize = LIST_INIT_SIZE;
}

void DestroyList(Sqlist &L)
{
    free(L.elem);
    L.elem = NULL;
    L.length = 0;
    L.listlize = 0;
}

void ClearList(Sqlist &L)
{
    L.length = 0;
}

Status ListEmpty(Sqlist L)
{
    if(L.length == 0)
        return TRUE;
    else 
        return FALSE;
}

Status ListLength(Sqlist L)
{
    return L.length;
}

Status GetElem(Sqlist L, int i, ElemType &e)
{
    if(i < 1 || i > L.length)
        return ERROR;
    e = *(L.elem + i - 1);
    return OK;
}

Status LocateElem(Sqlist L, ElemType e, Status(*compare)(ElemType, ElemType))
{
    int i = 1;
    Elem *p = L.elem;
    while(i <= L.length && !compare(*p++, e))
        i++;
    if(i <= L.length)
        return i;
    else 
    return ERROR;
}
Status compare(ElemType a, ElemType b)
{
    if(a == b)
        return TRUE;
    else 
        return FALSE;
}

Status PrionElem(Sqlist L, ElemType cur_e, ElemType &pre_e)
{
    int i = 2;
    ElemType *p = L.elem + 1;
    while(i <= L.length && p != cur_e)
    {
        p ++;
        i ++;
    }
    if(i > L.length)
        return ERROR;
    else
    {
        pre_e = *--p;
        return OK;
    }
}

Status NextElem(Sqlist L, ElemType cur_e, ElemType &next_e)
{
    int i = 1;
    ElemType *p = L.elem + 1;
    while(i < L.length && p != cur_e)
    {
        p ++;
        i ++;
    }
    if(i == L.length)
        return ERROR;
    else
        next_e = *++p;
        return OK;
}

Status ListInsert(Sqlist &L, int i, ElemType e)
{
    ElemType *p, *q, *newbase;
    if(i < 1 || i > L.length + 1) 
        return ERROR;
    if(L.length == L.listlize)
    {
        newbase = (ElemType*)realloc(L.elem,(L.listlize + LIST_CREMENT)*sizeof(ElemType));
        if(!newbase)
            exit OVERFLOW;
        L.elem = newbase;
        L.listlize += LIST_CREMENT;
    }
    q = L.elem + i - 1;
    for(p = L.elem + L.length - 1;p >= q; --p)
        *(p + 1) = *p;
    *q = e;
    L.length ++;
    return OK;
}

Status ListDelete(Sqlist L, int i, ElemType &e)
{
    ElemType *p, *q;
    if(i < 1 || i > L.length)
        return ERROR;
    p = L.elem + i - 1;
    e = *p;
    q = L.elem + L.length - 1;
    for(p ++; p <= q; p ++)
        *(p - 1) = *p;
    L.length --;
    return OK;
}

void ListTravel(Sqlist L, void(*visit)(ElemType))
{
    ElemType *p = L.elem;
    int i;
    for(i = 1; i <= L.length; i ++)
        visit(*p ++);
    printf("\n");
}
void visit(ElemType e)
{
    printf("%d", e);
}