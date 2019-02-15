#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXQSIZE 100001
typedef struct{
	int *base;
	int front;
	int rear;
}SqQueue;
int init(SqQueue &Q){
	Q.base = (int*)malloc(MAXQSIZE * sizeof(int));
	if(!Q.base) exit(-1);
	Q.front = Q.rear = 0;
	return 1;
}
int length(SqQueue &Q){
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}
int En(SqQueue &Q, int e){
	if((Q.rear + 1) % MAXQSIZE == Q.front) return 0;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return 1;
}
int De(SqQueue &Q, int &e){
	if(Q.front == Q.rear) return 0;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return 1;
}
int main(){
	int n, i, s, r;
    char a[100];
    SqQueue q;
    init(q);
    while(scanf("%d%*c", &n)!=EOF)
	{
        scanf("%s", a);
        if(strcmp(a, "enqueue") == 0)
        {
            scanf("%d%*c",&s);
            En(q, s);
        }
        if(strcmp(a, "dequeue") == 0)
        {
            if(De(q, r))
            {
                printf("%d\n", r);
            }
            else
            {
                printf("-1\n");
            }

        }
    }


	return 0;
}
