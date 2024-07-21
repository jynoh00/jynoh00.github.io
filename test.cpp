#include <iostream>
#include <vector>
#include <set>

using namespace std;
int gcd(int a, int b){
    return a%b == 0 ? b : gcd(b, a%b);
}

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer(2);
    answer[1] = denom1*denom2;
    answer[0] = numer1*denom2 + numer2*denom1;
    
    int num = gcd(answer[0],answer[1]);

    answer[0] /= num;
    answer[1] /= num;

    return answer;
}


int main(){
    
    vector<int> ans = solution(11,2,1,3);
    cout << ans[0] << " " << ans[1] << endl;
}

        // 집합으로 풀면 되지 않을까, set -> setA = 분자 공약수, setB = 분모 공약수 setC = 교집합

        // 걍 분모의 공약수 집합만 구한 다음, 집합 순회하며 분자를 나눌 수 있으면 실행, 이후 또 분모 공약수 구하고 반복
        // -> 분모 공약수 집합을 전체 순회하였는데도 나누기 실행안되었으면 종료


//시간초과
/*
vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer(2);
    answer[1] = denom1*denom2;
    answer[0] = numer1*denom2 + numer2*denom1;

    set<int> s;
    bool isFin = false;

    while(!isFin){
        for (int i = 2; i <= answer[1]; i++){
            if (answer[1]%i==0) s.insert(i);
        }
        for (int i : s){
            if (answer[0]%i==0){
                answer[0] /= i;
                answer[1] /= i;
                isFin = false;
                s.clear();
                break;
            }
            isFin = true;
        }
    }
    return answer;
}
*/

//최종풀이
/*
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b){
    if (a%b==0) return b;
    else return gcd(b, a%b);
}

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer(2);
    answer[1] = denom1*denom2;
    answer[0] = numer1*denom2 + numer2*denom1;

    int num = gcd(answer[0],answer[1]);

    answer[0] /= num;
    answer[1] /= num;

    return answer;
}

*/

// 분수의 덧셈