


// #Problem-13: Write a program to implement a queue data 
// # structure along with its typical operation.

#include <iostream>
using namespace std;

class Queue {
private:
    int* q; // pointer to store queue elements
    int capacity; // maximum capacity of the queue
    int front; // front points to front element in the queue if present
    int rear; // rear points to last element in the queue
    int count; // current size of the queue
    
public:
    // Constructor to initialize the queue
    Queue(int size) {
        q = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }
    
    // Destructor to deallocate memory
    ~Queue() {
        delete[] q;
    }
    
    // Function to remove front element from the queue
    void pop() {
        // check for queue underflow
        if (isEmpty()) {
            cout << "Queue UnderFlow!! Terminating Program." << endl;
            exit(1);
        }
        
        cout << "Removing element: " << q[front] << endl;
        
        front = (front + 1) % capacity;
        count--;
    }
    
    // Function to add a value to the queue
    void append(int value) {
        // check for queue overflow
        if (isFull()) {
            cout << "OverFlow!! Terminating Program." << endl;
            exit(1);
        }
        
        cout << "Inserting element: " << value << endl;
        
        rear = (rear + 1) % capacity;
        q[rear] = value;
        count++;
    }
    
    // Function to return front element in the queue
    int peek() {
        if (isEmpty()) {
            cout << "Queue UnderFlow!! Terminating Program." << endl;
            exit(1);
        }
        
        return q[front];
    }
    
    // Function to return the size of the queue
    int size() {
        return count;
    }
    
    // Function to check if the queue is empty or not
    bool isEmpty() {
        return size() == 0;
    }
    
    // Function to check if the queue is full or not
    bool isFull() {
        return size() == capacity;
    }
};

int main() {
    // create a queue of capacity 100
    Queue q(100);
    int n;
    
    while (true) {
        cout << "Press 0 then exit." << endl;
        cout << "Press 1 then go to append." << endl;
        cout << "Press 2 then go to pop." << endl;
        cout << "Press 3 then go to check isEmpty?" << endl;
        cin >> n;
        
        if (n == 0) {
            cout << "EXIT." << endl;
            break;
        }
        else if (n == 1) {
            int x;
            cout << "Enter the element: ";
            cin >> x;
            q.append(x);
        }
        else if (n == 2) {
            cout << "Queue size is " << q.size() << endl;
            cout << "Front element is " << q.peek() << endl;
            q.pop();
        }
        else if (n == 3) {
            if (q.isEmpty()) {
                cout << "Queue is empty" << endl;
            }
            else {
                cout << "Queue is not empty" << endl;
            }
        }
    }
    
    return 0;
}
