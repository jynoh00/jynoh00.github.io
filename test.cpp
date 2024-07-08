#include <iostream>
using namespace std;

#define MAX 5
#define PUSH 1
#define POP 2
class Queue{
private:
    int front;
    int rear;
    int lastOp;
    int data[MAX];
public:
    Queue(){
        front = 0;
        rear = 0;
        lastOp = 0;
    }
    ~Queue(){}
    int isEmpty(){
        if(front == rear && lastOp != PUSH){
            return 1;
        }else return 0;
    }
    bool isFull(){
        if(front == rear && lastOp == PUSH) return 1;
        else return 0;
    }
    void enqueue(int i){
        if (!isFull()){
            rear = (rear+1)%MAX;
            this->data[rear] = i;
            lastOp = PUSH;
        }
    }
    int dequeue(){
        if(!isEmpty()){
            lastOp = POP;
            front = (front+1)%MAX;
            return data[front];
        }
        return 0;
    }
    void printQ(){
        int numberOfQ;
        numberOfQ = rear > front ? rear-front : (rear+MAX) - front;
        int index = front +1;
        for (int i = 0; i < numberOfQ; i++){
            cout << data[(index+i)%MAX] << " ";
        }
        cout << endl;
    }
};

int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    cout << q.dequeue() << endl;
    q.enqueue(9);
    q.printQ();
}