#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main(){
    set<int> s;
    s.insert(16);
    s.insert(27);
    s.insert(10);
    s.insert(30);

    set<int>::iterator iter = s.emplace_hint(s.begin(), 101);
    s.emplace_hint(iter, 1);

    for (int i : s){cout << i << " ";}
    cout << endl;

    for (auto iter2 = s.begin(); iter2 != s.end(); iter2++){
        cout << *iter2 << " ";
    }
    cout << endl;

    for (auto iter2 = s.rbegin(); iter2 != s.rend(); iter2++){
        cout << *iter2 << " ";
    }
    cout << endl;

    set<int> s2(s);
    s2.clear();
    s2.emplace(3);
    for(int i : s2){cout << i << " ";}
    cout << endl;
    
    s.swap(s2);
    cout << "------" << endl;
    for(int i : s){cout << i << " ";} cout << endl;
    for(int i : s2){cout << i << " ";} cout << endl;

    s2.erase(30);
    for(int i : s2){cout << i << " ";} cout << endl;

    set<int>::iterator iter3 = s2.find(27); // s.find(key) 찾는 Key값이 있으면, 해당 위치의 Iter 반환, 없으면 s.end()
    set<int>::iterator iter4 = s2.find(999);
    cout << *iter3 << endl;
    cout << *iter4 << endl;
    cout << *s2.end() << endl; // iter4와 s2.end() 동일
}