#include<iostream>
using namespace std;

class Cqueue
{
    int *a;
    int size, capacity;
    int front, rear;

public:
    Cqueue(int cap)
    {
        capacity = cap;
        a = new int[capacity];
        size = 0;
        front = rear = -1;
    }

    bool isEmpty()
    {
        return size <= 0;
    }

    bool isFull()
    {
        return size == capacity;
    }

    void enqueue(int data)
    {
        if (isFull())
        {
            cout << "Queue is full! Cannot insert " << data << endl;
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % capacity;
        a[rear] = data;
        size++;
        cout << data << " has been inserted into the queue." << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "The queue is empty! Cannot perform dequeue." << endl;
            return;
        }
        int del = front;
        cout << a[del] << " has been deleted from the queue." << endl;
        front = (front + 1) % capacity;
        size--;
        if (size == 0)
        {
            front = rear = -1;
        }
    }

    int getFront()
    {
        return isEmpty() ? -1 : a[front];
    }

    int getRear()
    {
        return isEmpty() ? -1 : a[rear];
    }

    void printQueue()
    {
        if (isEmpty())
        {
            cout << "The queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < size; i++)
        {
            cout << a[(i + front) % capacity] << " ";
        }
        cout << endl;
    }

    int getSize()
    {
        return size;
    }

    ~Cqueue()
    {
        delete[] a;
    }
};

int main()
{
    int cap;
    cout << "Enter the capacity of the queue: ";
    cin >> cap;
    Cqueue q(cap);
    cout << "\nQueue Operations Menu: \n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Check if Empty\n";
    cout << "4. Check if Full\n";
    cout << "5. Get Front Element\n";
    cout << "6. Get Rear Element\n";
    cout << "7. Print Queue\n";
    cout << "8. Get Queue Size\n";
    cout << "0. Exit\n";
    int choice;
    do
    {
       
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            {
                int data;
                cout << "Enter the element to insert: ";
                cin >> data;
                q.enqueue(data);
                break;
            }
        case 2:
            q.dequeue();
            break;
        case 3:
            cout << (q.isEmpty() ? "Queue is empty." : "Queue is not empty.") << endl;
            break;
        case 4:
            cout << (q.isFull() ? "Queue is full." : "Queue is not full.") << endl;
            break;
        case 5:
            cout << "Front element: " << q.getFront() << endl;
            break;
        case 6:
            cout << "Rear element: " << q.getRear() << endl;
            break;
        case 7:
            q.printQueue();
            break;
        case 8:
            cout << "Current queue size: " << q.getSize() << endl;
            break;
        case 0:
            cout << "Exiting the program..." << endl;
            break;
        default:
            cout << "Invalid choice, please try again!" << endl;
        }

    } while (choice != 0);

    return 0;
}

