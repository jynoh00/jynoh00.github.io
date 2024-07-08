#include <iostream>
#include <vector>
using namespace std;

void test1(vector<int> v){
    v.push_back(1);
    cout << v.size() << endl;
}

void test2(vector<int>* v){
    v->push_back(2);
}

void test3(vector<int>& v){
    v.push_back(3);
}

int main(){
    vector<int> vector = {0, 0};
    test1(vector);
    test2(&vector);
    test3(vector);
    for (int i : vector){
        cout << i << " ";
    }
    cout << endl;
}