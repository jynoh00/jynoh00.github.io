#include <iostream>
using namespace std;

#define MAX_STACK_SIZE 5

class Stack{
private:
    int top;
    int array[MAX_STACK_SIZE];
public:
    Stack(){ top = -1; }
    ~Stack(){}
    bool isEmpty(){ return top == -1; }
    bool isFull(){ return top == MAX_STACK_SIZE -1; }
    void push(int i){
        if(!isFull()) array[++top] = i;
        else return;
    }
    int pop(){
        if(!isEmpty()){ return array[top--]; }
    }
    void display(){
        for (int i = 0; i <= top; i++){
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    Stack s; // 스택 s 선언
    s.push(1); // 1 추가
    s.push(2); // 2 추가
    s.push(3); // 3 추가
    s.push(4); // 4 추가
    s.push(5); // 5 추가
    s.push(6); // isFull이 true이기에 추가 x
    cout <<s.pop() << endl; // 스택의 최상단 값이었던 5가 반환, 이후 top--
    s.push(7); // 7 추가
    s.display(); // 1 2 3 4 7

    return 0;
}