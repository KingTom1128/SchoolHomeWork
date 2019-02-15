#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define STACK_INIT_SIZE 1000
#define STACKINCREMENT 10
typedef char ElemType;
typedef char string;
typedef struct{
    ElemType *base;
    ElemType *top;
    int stacksize;
}SqStack;
int init(SqStack &s)
{
    s.base = (ElemType*)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if(!s.base)
        exit(OVERFLOW);
    s.top = s.base;
    s.stacksize = STACK_INIT_SIZE;
    return OK;
}

int push(SqStack &s, ElemType e)
{
    if((s.top - s.base) >= s.stacksize)
    {
        s.base = (ElemType*)realloc(s.base, (s.stacksize + STACKINCREMENT) * sizeof(ElemType));
        if(!s.base)
            exit(OVERFLOW);
        s.top = s.base + s.stacksize;
        s.stacksize += STACKINCREMENT;
    }
    *s.top++ = e;
    return OK;
}

int pop(SqStack &s, ElemType &e)
{
    if(s.top == s.base)
        return ERROR;
    e = * --s.top;
    return OK;
}

int empty(SqStack &s)
{
    return s.top == s.base;
}

int get(SqStack &s, ElemType &e)
{
    if(s.top == s.base)
        return ERROR;
    e = *(s.top - 1);
    return OK;
}

int match(string a[])
{
    int i;
    SqStack s;
    init(s);
    for(i = 0; i < strlen(a); i ++)
    {
        if(a[i] == '[' || a[i] == '(')
        {
            push(s, a[i]);
        }      
        else
        {
            ElemType e;
            if(empty(s))
                return ERROR;
            get(s, e);
            if(a[i] == ']' && e == '(')
                return ERROR;
            if(a[i] == ')' && e == '[')
                return ERROR;
            pop(s, e);
        }
        
    }
        if(empty(s))
            return OK;
        else
            return ERROR;
}

int main()
{
    ElemType a[1000], e;
    while(gets(a))
    {
        if(match(a) == 1)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
