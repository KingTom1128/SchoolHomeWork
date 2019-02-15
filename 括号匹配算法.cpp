#include<stdio.h>
#include<stdlib.h>
typedef struct snode
{
	char data;
	struct snode *next;
}snode,*Linkstack;
void Linkstackpush(Linkstack *ls,char e)
{
	Linkstack p=(Linkstack)malloc(sizeof(snode));
	p->data=e;
	p->next=*ls;
	*ls=p;
}
int Linkstackpop(Linkstack *ls)
{
	Linkstack p;
	p=*ls;
	if(*ls==NULL) 
	return 0;
	(*ls)=(*ls)->next;
	free(p);
	return 1;
}
int Linkstackgettop(Linkstack ls,char *e)
{
	if(ls==NULL) 
	return 0;
	*e=(ls)->data;
	return 1;
}
void initLinkstack(Linkstack *ls)
{
	*ls=NULL;
}
void matching(char str[])
{
	char e;
	int k,flag=1;
	Linkstack s;
	initLinkstack(&s);
	for(k=0;str[k]!='\0' && flag;k++)
    {
        if(str[k]!='('&&str[k]!=')'&&str[k]!='['&&str[k]!=']'&&str[k]!='{'&&str[k]!='}')    
        continue;
        switch(str[k])
        {
            case'(':
            case'[':
            case'{':Linkstackpush(&s,str[k]);break;
            case')':if(s)
            {
                Linkstackgettop(s,&e);
                if(e=='(') 
                    Linkstackpop(&s);
                else 
                    flag=0;
            }
            else flag=0; break;
            case']':if(s)
            {
                Linkstackgettop(s,&e);
                if(e=='[')
                    Linkstackpop(&s);
                else flag=0;
            }
            else 
                flag=0; 
                break;
            case'}':if(s)
            {
                Linkstackgettop(s,&e);
                if(e=='}') 
                    Linkstackpop(&s);
                else 
                    flag=0;
            }
            else 
                flag=0; 
                break;
        }   
	}
	if(flag==1 && s==NULL)
    {
		printf("yes\n");
	}
	else printf("no\n");
}

int main()
{
	char str[8000];
	while(gets(str))
    {
		matching(str);
	}
	return 0;
}
