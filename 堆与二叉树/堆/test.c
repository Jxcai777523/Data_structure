#define _CRT_SECURE_NO_WARNINGS
#include"Stack.h"
#include"Queue.h"
int main()
{
    stack s;
    StackInit(&s);
    StackPush(&s, 1);
    StackPush(&s, 2);
    StackPush(&s, 3);
    StackPush(&s, 4);
    while (!Stackempty(&s))
    {
        printf("%d  ", StackTop(&s));
        Stackpop(&s);
    }
    StackDestroy(&s);
    return 0;
}
//int main()
//{
//	Que pq;
//	QueInit(&pq);
//	Quepush(&pq, 1);
//	Quepush(&pq, 2);
//	Quepush(&pq, 3);
//	Quepush(&pq, 4);
//	QueSize(&pq);
//	printf("%d ", Quefront(&pq));
//	Quepop(&pq);
//	printf("%d ", Quefront(&pq));
//	Quepop(&pq);
//	printf("%d ", Quefront(&pq));
//	Quepop(&pq);
//	QueDestroy(&pq);
//	return 0;
//}