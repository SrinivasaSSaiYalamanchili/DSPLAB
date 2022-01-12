#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include <limits.h>
struct Stack
{
int capacity;
int top;
int *array;
};
struct Stack* createStack(int capacity)
{
    struct Stack* stack =(struct Stack*) malloc(sizeof(struct Stack));
    stack -> capacity = capacity;
    stack -> top = -1;
    stack -> array =(int*) malloc(stack -> capacity * sizeof(int));
    return stack;
}
void push(struct Stack *stack, int item)
{
    if (stack->top == stack->capacity - 1)
        return;
    stack -> array[++stack -> top] = item;
}
int pop(struct Stack* stack)
{
    if (stack->top == -1)
        return INT_MIN;
    return stack -> array[stack -> top--];
}
void moveDisk(char t1, char t2, int disk)
{
    printf("\n Move the disk %d from '%c' to '%c'",disk, t1, t2);
}
void moveDisksBetweenTwoPoles(struct Stack *beg,
            struct Stack *end, char b, char e)
{
    int pole1TopDisk = pop(beg);
    int pole2TopDisk = pop(end);
    if (pole1TopDisk == INT_MIN)
    {
        push(beg, pole2TopDisk);
        moveDisk(e, b, pole2TopDisk);
    }
    else if (pole2TopDisk == INT_MIN)
    {
        push(end, pole1TopDisk);
        moveDisk(b, e, pole1TopDisk);
    }
    else if (pole1TopDisk > pole2TopDisk)
    {
        push(beg, pole1TopDisk);
        push(beg, pole2TopDisk);
        moveDisk(e, b, pole2TopDisk);
    }
    else
    {
        push(end, pole2TopDisk);
        push(end, pole1TopDisk);
        moveDisk(b, e, pole1TopDisk);
    }
}
void tower(int numberOfDisk, struct Stack *beg, struct Stack *aux, struct Stack *end)
{
    int i, moves;
    char b = 'A', e = 'C', a = 'B';
    if (numberOfDisk % 2 == 0)
    {
        char temp = e;
        e = a;
        a = temp;
    }
    moves = pow(2, numberOfDisk) - 1;
    for (i = numberOfDisk; i >= 1; i--)
        push(beg, i);

    for (i = 1; i <=moves; i++)
    {
        if (i % 3 == 1)
        moveDisksBetweenTwoPoles(beg, end, b, e);
        else if (i % 3 == 2)
        moveDisksBetweenTwoPoles(beg, aux, b, a);
        else if (i % 3 == 0)
        moveDisksBetweenTwoPoles(aux, end, a, e);
    }
}

void main()
{
    int numberOfDisk;
	printf("\nEnter the number of disks\n");
	scanf("%d", &numberOfDisk);
    struct Stack *beg, *end, *aux;
    beg = createStack(numberOfDisk);
    aux = createStack(numberOfDisk);
    end = createStack(numberOfDisk);
    tower(numberOfDisk, beg, aux, end);
}
