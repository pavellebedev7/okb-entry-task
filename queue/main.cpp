#include <iostream>
#include <mystack.h>
#include <queue.h>

using namespace std;

int main()
{
    // Empty queue
    Queue q;

    // Put 3 elements
    cout << "Put 1, 2, 3" << endl;
    q.put(1);
    q.put(2);
    q.put(3);

    // Get 2 elements
    cout << "Get 2 elements" << endl;
    cout << q.get() << endl;
    cout << q.get() << endl;

    // Put 4 elements
    cout << "Put 4, 5, 6, 7" << endl;
    q.put(4);
    q.put(5);
    q.put(6);
    q.put(7);

    // Put 6 elements
    cout << "Put 8, 9, 10, 11, 12, 13" << endl;
    q.put(8);
    q.put(9);
    q.put(10);
    q.put(11);
    q.put(12);
    q.put(13); // element do not get to the queue due to the overflow

    // Get 4 elements
    cout << "Get 4 elements" << endl;
    cout << q.get() << endl;
    cout << q.get() << endl;
    cout << q.get() << endl;
    cout << q.get() << endl;

    // Get 2 elements
    cout << "Get 2 elements" << endl;
    cout << q.get() << endl;
    cout << q.get() << endl;

    // Put 3 element
    cout << "Put 14, 15, 16" << endl;
    q.put(14);
    q.put(15);
    q.put(16);

    // Get 4 elements
    cout << "Get 4 elements" << endl;
    cout << q.get() << endl;
    cout << q.get() << endl;
    cout << q.get() << endl;
    cout << q.get() << endl;

    cin.get();
    return 0;
}

