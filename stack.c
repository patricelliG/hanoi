// This program implements a simple stack capable of storing int types
#define STACK_SIZE 64 
#include <stdio.h>

struct Stack
{
    int arr[STACK_SIZE];
    int top;
    char name[10]; // An optional name
} stack;

void push(struct Stack *s, int data)
{
    if(s->top + 1 > STACK_SIZE)
    {
        // This is out of bounds
    }
    else
    {
        // Index is in bounds, add data to stack
        s->top++;
        s->arr[s->top] = data;
    }
}

int pop(struct Stack *s)
{
    if(s->top < 0)
    {
        //This stack is empty
        return -1;
    }
    else
    {
        s->top--;
        return s->arr[s->top+1];
    }
}

int peek(struct Stack s)
{
    if(s.top < 0)
    {
        // This stack is empty
        return -1;
    }
    else
    {
        return s.arr[s.top];
    }
}

int index_peek(struct Stack s, int index)
{
    if(s.top < 0 || index > s.top || index < 0)
    {
        // This stack is empty or index is out of range
        return -1;
    }
    else
    {
        return s.arr[index];
    }
}

