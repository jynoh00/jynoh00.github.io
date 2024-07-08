#include <iostream>
using namespace std;
#define MAX_STACK_SIZE 100

class Stack{
private:
    int top;
    char array[MAX_STACK_SIZE];
public:
    Stack(){ top = -1; }
    ~Stack(){}
    bool isEmpty(){ return top == -1; }
    bool isFull(){ return top == MAX_STACK_SIZE -1; }
    void push(int i){
        if(!isFull()) array[++top] = i;
        else return;
    }
    char pop(){
        if(!isEmpty()){ return array[top--]; }
    }
    void display(){
        for (int i = 0; i <= top; i++){
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

bool isBalanced(string str){
    Stack s;
    for (char ch : str){
        if (ch == '(' || ch == '{' || ch == '['){
            s.push(ch);
        }else if (ch == ')' || ch == '}' || ch == ']'){
            if (s.isEmpty()){
                return false;
            }
            char top = s.pop();
            if ((ch == ')' && top != '(') || (ch == '}' && top != '{') || (ch == ']' && top != '[')){
                return false;
            }
        }
    }
    return s.isEmpty();
}

int main(){
    string str[3] = {"sadadadsd()d{dasd[d]d}", "dgfdgsdkj([]){}asdddd[ddf]", "[dfvfsad{]}()asd{df}"};
    for (string s : str){
        if (isBalanced(s)){
            cout << "괄호 검사 이상 없음" << endl;
        }else{
            cout << "괄호 검사 이상 발생" << endl;
        }
    }
    return 0;
}