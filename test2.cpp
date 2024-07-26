#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

int main(){
    map<string, string> m;
    int n;
    cin >> n;
    cin.ignore(); // 

    for (int i = 0; i < n; i++){
        string s;
        getline(cin, s);
        stringstream ss(s);
        string score, name;
        ss >> name >> score;
        m.insert({score, name});
    }

    for (auto iter : m){cout << iter.second << " ";}
    cout << endl;

    return 0;
}