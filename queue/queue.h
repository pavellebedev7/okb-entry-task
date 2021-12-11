#ifndef QUEUE
#define QUEUE

#include <mystack.h>

using namespace std;

class Queue{
    int count;
    Stack left, right;
public:
    Queue();
    int get();
    int put(int _val);
    bool isEmpty();
    bool isFull();
    void print();
};

Queue::Queue()
{
    count = 0;
}

int Queue::get()
{
    int rez = -1;
    if(!isEmpty())
    {
        if(left.isEmpty()){
            while(!right.isEmpty()){
                left.put(right.get());
            }
        }
    rez = left.get();
    count--;
    }
    if(rez == -1)
    {
        printf("Queue is empty\n");
    }
    return rez;
}

int Queue::put(int _val)
{
    int rez = -1;
    if(count == MAXSTACK)
    {
        printf("Queue is full\n");
    }
    else
    {
        rez = right.put(_val);
        count++;
    }
    return rez;
}

bool Queue::isEmpty()
{
    if(left.isEmpty() && right.isEmpty()) return true;
    else return false;
}

bool Queue::isFull()
{
    if(count == MAXSTACK) return true;
    else return false;
}

// Test output that requires public access to the stack fields
/*
void Queue::print(){
    cout << "Status " << count << endl;
    for(int i = MAXSTACK-1; i >= 0; i--){
        cout << i << " " << left.data[i] << " " << right.data[i] << endl;
    }
}*/

#endif // QUEUE

