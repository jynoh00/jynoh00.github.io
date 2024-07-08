---
layout: post
title: 괄호 검사 알고리즘
date: 2024-07-08
categories: algorithm
---
#### 괄호 검사
> 다양한 언어로 코드를 작성할 때, 코드의 양이 길어지거나 복잡할 수록 괄호의 열고 닫음의 확인이 중요하다.
<br> 괄호는 (), {}, []가 있고 문자열이 주어졌을 때 괄호가 올바르게 작성되었는 지를 확인하는 알고리즘을 알아보겠다.

<br>
괄호 검사 알고리즘은 <a href = "/data-structure/2024/07/08/stack.html">스택(Stack) 자료구조</a>를 사용하면 쉽게 해결할 수 있다.

#### 1. C++, 괄호 검사 알고리즘
괄호는 (), {}, [] 3종류가 있고 각 괄호가 올바르게 입력되어 있는 지를 확인하면 된다.
- ex1) "sadadadsd()d{dasd[d]d}" // good
- ex2) "dgfdgsdkj([]){}asdddd[ddf]" // good
- ex3) "[dfvfsad{]}()asd{df}" // bad - <strong>{</strong> 괄호 입력 이후, 이전 입력 괄호 <strong>[</strong> 의 닫는 괄호인 <strong>]</strong> 가 <strong>}</strong> 보다 먼저 나오면 안 된다.

<br><br>
Stack을 객체로 구현한 후 괄호 검사를 수행하는 isBalanced함수를 정의하였다.
```c++
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

```
##### isBalanced 함수 설명
- 스택 s를 생성한다.
- 인자로 받아온 string 타입 str을 각 char 하나 씩 for문으로 검사한다.
- ch가 (, {, [ 중 하나면 스택에 ch를 push한다.
- ch가 ), }, ] 중 하나일 경우, 스택이 비어있으면 false를 리턴하고 함수를 끝낸다.
- ch가 ), }, ] 중 하나이면서, 스택이 안 비어있을 경우 스택을 pop한 값을 top 변수에 저장하고<br>
ch값과 top값을 비교하여, 괄호 매칭이 옳바르지 않다면 false를 리턴하고 함수를 끝낸다.
- 모든 반복문을 끝낸 후 스택의 isEmpty() 메소드를 실행한 결과를 isBalanced()함수의 반환 값으로 리턴한다.

##### // Stack 객체의 설명은 스택(Stack) 게시글에서

<br>

#### 2. main() 함수 예제
```c++
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
```

#### 3. output
```yml
괄호 검사 이상 없음
괄호 검사 이상 없음
괄호 검사 이상 발생
```
<br>

* * *
<br><br>

>메모, 
<br>괄호 검사 알고리즘은 스택을 사용하면 쉽게 구현할 수 있다.
<br>이때 스택의 요소들의 데이터 타입을 입력 값에 맞게 정의하는 것이 중요하다.
