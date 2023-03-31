#include <iostream>
using namespace std;

#define SIZE 5 // maximum size of the queue

class Queue {
private:
    int items[SIZE], front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        if (front == 0 && rear == SIZE - 1) {
            return true;
        }
        if (front == rear + 1) {
            return true;
        }
        return false;
    }

    bool isEmpty() {
        if (front == -1) {
            return true;
        }
        else {
            return false;
        }
    }

    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full." << endl;
        }
        else {
            if (front == -1) {
                front = 0;
            }
            rear = (rear + 1) % SIZE;
            items[rear] = element;
            cout << "Inserted " << element << endl;
        }
    }

    void dequeue() {
        int element;
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        }
        else {
            element = items[front];
            if (front == rear) {
                front = -1;
                rear = -1;
            }
            else {
                front = (front + 1) % SIZE;
            }
            cout << "Deleted element: " << element << endl;
        }
    }

    void display() {
        int i;
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        }
        else {
            cout << "Front -> " << front << endl;
            cout << "Items -> ";
            for (i = front; i != rear; i = (i + 1) % SIZE) {
                cout << items[i] << " ";
            }
            cout << items[i] << endl;
            cout << "Rear -> " << rear << endl;
        }
    }
};

int main() {
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    return 0;
}
