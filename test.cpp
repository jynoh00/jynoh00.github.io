#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int>v = { 1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << v.size() << endl;    // 9
    cout << v.capacity() << endl; // 9

    v.reserve(120); // 벡터의 capacity를 지정, 인자에 현 capacity보다 적은 값이 들어가면 현 capacity 유지
    cout << v.capacity() << endl; // 120

    v.shrink_to_fit(); // 벡터의 capacity를 size에 맞게
    cout << v.capacity() << endl; // 9

    cout << v.empty() << endl; // 0
    v.clear();
    cout << v.empty() << endl; // 1
    cout << v.capacity() << endl; // clear로 원소를 모두 제거하여도 capacity는 유지된다.
    vector<int>().swap(v);
    cout << v.capacity() << endl; // 빈 벡터 공간과 swap을 통해 capacity를 0으로 바꾸는 방법
}