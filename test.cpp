#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool dfs(int i, int j, vector<vector<int>>& v, int N, int M){
    if (i < 0 || i >= N || j < 0 || j >= M) return false;
    if (v[i][j] == 0){
        v[i][j] = 1;
        dfs(i-1, j, v, N, M);
        dfs(i+1, j, v, N, M);
        dfs(i, j-1, v, N, M);
        dfs(i, j+1, v, N, M);
        return true;
    }
    return false;
}

int main(){
    int N, M;
    int count = 0;

    cin >> N >> M;
    vector<vector<int>> v(N, vector<int>(M));
    
    for (int i = 0; i < N; i++){
        string input;
        cin >> input;
        for (int j = 0; j < M; j++){
            v[i][j] = (input[j] - '0');
        }
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (dfs(i, j, v, N, M)) count++;
        }
    }
    cout << count << endl;
}