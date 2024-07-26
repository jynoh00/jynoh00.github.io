#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer(quiz.size());
    int num1, num2, num3;
    char calcu, garbage;
    
    for (int i = 0; i < quiz.size(); i++){
        stringstream ss(quiz[i]);
        ss >> num1 >> calcu >> num2 >> garbage >> num3;
        if (calcu == '+') answer[i] = ((num1+num2) == num3) ? "O" : "X";
        else answer[i] = ((num1-num2) == num3) ? "O" : "X";
        ss.clear();
    }

    return answer;
}

int main(){

    vector<string> quiz = {"3 - 4 = -3", "5 + 6 = 11"};
    vector<string> ans_v = solution(quiz);
    for (string s : ans_v){cout << s << " ";}
    cout << endl;
    
}

/*
quiz 공백 기준 분류
3 , - , 4 , = , -3
5 , + , 6 , = , 11

"19 - 6 = 13", "5 + 66 = 71", "5 - 15 = 63", "3 - 1 = 2"

19 , - , 6 , = , 13
5 , + , 66 , = , 71
5 , - , 15 , = , 63

0 => 숫자1
1 => 연산
2 => 숫자2
3 => 무시
4 => 결과

숫자1 연산 숫자2 == 결과

*/