#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int solution(vector<int> array){
    set<int> s(array.begin(), array.end());
    vector<int> vec(s.begin(), s.end());
    vector<int> repeat(s.size());
    int index = 0;
    for (int i : s){
        int r = 0;
        for (int j : array){
            if (j==i) r++; 
        }
        repeat[index] = r;
        index++;
    }
    
    int max_index;
    int tmp = 0;
    for (int i = 0; i < s.size(); i++){
        if (repeat[i] > tmp){
            tmp = repeat[i];
            max_index = i;
        }
    }

    sort(repeat.rbegin(), repeat.rend());
    if (repeat[0] == repeat[1]) return -1;
    else return vec[max_index];
}
// 쥐렸다

int main(){
    vector<int> v = {1, 2, 3,3,3,4};
    vector<int> v1 = {1,1,2,2};
    vector<int> v2 = {1,1,1,1,1,1, 2, 3,3,3,3, 5,5,5,5,5,5,5,5, 6,6,6,6,6};

    cout << solution(v) << endl;
}

// tq
// int solution(vector<int> array) {
//     set<int> s(array.begin(), array.end());
//     int arr[s.size()];
//     int num = 0;
//     for (int i : s){
//         int a = 0;
//         for (int j : array){
//             if (j==i) a++;
//         }
//         arr[num] = a;
//         num++;
//     }

//     vector<int> vec(s.begin(), s.end());
//     int max_index = 0;
//     int tmp = 0;
//     for (int i = 0; i < s.size(); i++){
//         if (arr[i] > tmp){
//             tmp = vec[i];
//             max_index = i;
//         }
//     }

//     sort(arr, arr + s.size());
//     if (arr[s.size()-2] == arr[s.size()-1]) return -1;
//     else return vec[max_index];
// }


// 최빈값 문제