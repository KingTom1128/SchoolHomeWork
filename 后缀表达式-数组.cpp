#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[256];
int stack[256];
int main()
{
    int top = 0;
    gets(str);
    int len = strlen(str);
    
    int i;
    for(i = 0; i <= len-2; i++)
    {
        switch(str[i])
        {
            case '+':stack[--top]+=stack[top+1];break;
            case '-':stack[--top]-=stack[top+1];break;
            case '*':stack[--top]*=stack[top+1];break;
            case '/':stack[--top]/=stack[top+1];break;
            default:
            {
                int x = 0;
                while(str[i] != ' ')
                    x = x * 10 + str[i++] - '0';
                stack[++top] = x;
                break; 
            }
        }
    }
    printf("%d\n", stack[top]);
    return 0;

}