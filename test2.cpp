#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<long long> v(100);
    v[0] = 1;
    v[1] = 1;
    int n = 6;
    for (int i = 2; i < n; i++){
        v[i] = v[i-1] + v[i-2];
    }

    for (long long i : v){
        if(i != 0) cout << i << " ";
        }
    cout << endl;
}