#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 10000
#define STACKINCREMENT 10
#define TURE 1
#define FALSE 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define OK 1
#define ERROR 0
typedef int Selemtype;
typedef int Status;
typedef struct
{
    Selemtype *base;
    Selemtype *top;
    int stacksize;
}Sqstack;

Status initstack(Sqstack &s) 
{
    s.base=(Selemtype*)malloc(STACK_INIT_SIZE*sizeof(Selemtype));
    if(!s.base) exit(OVERFLOW);
    s.top=s.base;
    s.stacksize=STACK_INIT_SIZE;
    return 0;
}

Status travelstack(Sqstack s)
{
    Selemtype *p;
    p=s.base;
    printf("%c",*p++);
    while(p!=s.top)     
    {
        printf(" %c",*p++);
    }
    return 0;
}

Status Gettop(Sqstack s)
{
    if(s.base==s.top) return ERROR;
    return *(s.top-1);
}

Status push(Sqstack &s,Selemtype e)
{
    if(s.top-s.base>=s.stacksize)
    {
        s.base=(Selemtype*)realloc(s.base,(s.stacksize+STACKINCREMENT)*sizeof(Selemtype));
        if(!s.base) exit(OVERFLOW);
        s.top=s.base+s.stacksize;
        s.stacksize+=STACKINCREMENT;
    }
    *s.top=e;
    s.top++;
    return OK;
}

Status pop(Sqstack &s,Selemtype &e)
{
    if(s.base==s.top) return ERROR;
    s.top--;
    e=*s.top;
    return OK;
}

Status compare(Selemtype a,Selemtype b)
{
    switch(a)
    {
        case '+':
        switch(b)
        {
            case '+':
            case ')':
            case '#':
            case '-':return '>';
            case '*':
            case '/':
            case '(':return '<';
        }
        case '-':
        switch(b)
        {
            case '+':
            case ')':
            case '#':
            case '-':return '>';
            case '*':
            case '/':
            case '(':return '<';
        }
        case '*':
        switch(b)
        {
            case '(':return '<';
            case '+':
            case ')':
            case '#':
            case '-':
            case '*':
            case '/':return '>';
        }
        case '/':
        switch(b)
        {
            case '(':return '<';
            case '+':
            case '#':
            case ')':
            case '*':
            case '-':
            case '/':return '>';
        }
        case '(':
        switch(b)
        {
            case ')':return '=';
            case '(':
            case '+':
            case '-':
            case '*':
            case '/':return '<';
        }
        case ')':
        switch(b)
        {
            case ')':
            case '+':
            case '#':
            case '-':
            case '*':
            case '/':return '>';
        }
        case '#':
        switch(b)
        {
            case '#':return '=';
            case '(':
            case '+':
            case '-':
            case '*':
            case '/':return '<';
        }
    }
}
Status operate(Selemtype a,Selemtype c,Selemtype b) 
{
    switch(c)
    {
        case '+':return a+b;
        case '-':return a-b;
        case '*':return (a)*(b);
        case '/':return (a)/(b);
    }
}
Status qiuzhi() 
{
    Selemtype c,a,b,x,theta;
    Sqstack optr,opnd,calculator;
    initstack(optr);
    initstack(opnd);
    initstack(calculator);
    push(optr,'#');
    c=getchar();
    while(c!='#'||Gettop(optr)!='#')
    {
       if(c=='\n') c='#';
        if(c>='0'&&c<='9') {push(opnd,c-48);push(calculator,c);c=getchar();}
        else
        {
            switch(compare(Gettop(optr),c))
            {
                case '<':push(optr,c);c=getchar();break;
                case '=':if(c=='#') break;
                else{pop(optr,x);c=getchar();break;}
                case '>':pop(optr,theta);pop(opnd,b);pop(opnd,a);
                push(calculator,theta);

                push(opnd,operate(a,theta,b));
                break;
            }
        }
    }
    travelstack(calculator);
    printf("\n");
    return Gettop(opnd);
}
int main() 
{
    printf("%d\n",qiuzhi());
    return 0;
}
