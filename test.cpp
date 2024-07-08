#include <iostream>
using namespace std;
class Node{
private:
    int data;
    Node* link;
public:
    Node(int d = 0){ data = d; }
    ~Node(){}
    void setData(int d){ data = d; }
    int getData(){ return data; }
    void setLink(Node* nextNode){ link = nextNode; }
    Node* getLink(){ return link; }
};

class LinkedQueue{
private:
    Node* front;
    Node* rear;
public:
    LinkedQueue(){ front = rear = nullptr; }
    void enqueue(Node* n){
        if (front == nullptr && rear == nullptr){
            front = n;
            rear = n;
        }else{
            rear->setLink(n);
            rear = n;
        }
    }
    Node* dequeue(){
        Node* tmp = front;
        front = front->getLink();
        return tmp;
    }
    void display(){
        Node* tmp = front;
        while(tmp != nullptr){
            cout << tmp->getData() << " ";
            tmp = tmp->getLink();
        }
        cout << endl;
    }
};

int main(){
    LinkedQueue lq;
    lq.enqueue(new Node(10));
    lq.enqueue(new Node(20));
    lq.enqueue(new Node(30));
    lq.enqueue(new Node(40));

    lq.display();

    cout << lq.dequeue()->getData() << endl;
    cout << lq.dequeue()->getData() << endl;

    lq.display();

    lq.enqueue(new Node(50));
    lq.display();
}