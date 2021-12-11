#ifndef MYSTACK_H
#define MYSTACK_H

#include <stdio.h>

const int MAXSTACK = 10;

class Stack
{
    int count;
    int data[MAXSTACK];
public:
    Stack();
    int get();
    int put(int _val);
    bool isEmpty();
    bool isFull();
};

Stack::Stack()
{
    count = 0;
    for(int i = 0; i < MAXSTACK; ++i)
        data[i] = -1;

}
int Stack::get()
{
    int rez = -1;
    if(count!=0)
    {
        rez = data[count-1];
        data[count-1] = -1;
        --count;
    }
    if(rez == -1)
    {
        count = -1;
        printf(" Stack is empty\n");
    }
    return rez;
}
int Stack::put(int _val)
{
    int rez = -1;
    if(count == MAXSTACK)
    {
        printf(" Stack is full\n");
    }
    else
    {
        data[count++] = _val;
        rez = count;
    }
    return rez;
}

bool Stack::isEmpty()
{
    if(count==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Stack::isFull()
{
    if(count == MAXSTACK)
        return true;
    else
        return false;
}

#endif // MYSTACK_H
