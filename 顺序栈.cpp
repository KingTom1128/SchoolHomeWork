#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 10
#define STACK_INCREMENT 2
struct SqStack
{
    SElemType *base;
    SElemType *top;
    int stacksize;
};
void InitStack(SqStack &S)
{
    S.base = (SElemType)malloc(STACK_INIT_SIZE *sizeof(SElemType));
    if(!S.base) exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
}
void DestroyStack(SqStack &S)
{
    free(S.base);
    S.top = S.base = NULL;
    S.stacksize = 0;
}
void ClearStack(SqStack &S)
{
    S.top = S.base;
}
Status StackEmpty(SqStack S)
{
    if(S.top == S.base)
        return TRUE;
    else
        return FALSE;
}
int StackLength(SqStack S)
{
    return S.top - S.base;
}
Status GetTop(SqStack S, SElemType &e)
{
    if(S.top > S.base)
    {
        e = *(S.top - 1);
        return OK;        
    }
    else   
        return ERROR;
}
void push(SqStack &S, SElemType e)
{
    if(S.top - S.base == S.stacksize)
    {
        S.base = (SElemType)realloc(S.base, (S.stacksize + STACK_INCREMENT)*sizeof(SElemType));
        if(!S.base) exit(OVERFLOW);
        S.top = S.base + S.stacksize;
        S.stacksize += STACK_INCREMENT;
    }
    *(S.top) ++ = e;
}
Status Pop(SqStack &S, SElemType &e)
{
    if(S.top == S.base)
        return ERROR;
    e = * --S.top;
    return OK;
}
void StackTraverse(SqStack S, void(*visit)(SElemType))
{
    SElemType *p = S.base;
    while(S.top > p)
        visit(*p ++);
    printf("\n");
}
void visit(SElemType e)
{
    printf("%d", e);
}