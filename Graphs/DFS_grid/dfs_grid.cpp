// Basically, for solving this we'll store {x, y} in the stack and then we'll check for all the 4 directions just like dfs.
// The stack basically represents the ruccursion. 

#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void DFS(vector<vector<int>> &grid, vector<vector<bool>> &visited, vector<int> &ans, int x, int y){
    int n = grid.size();
    int m = grid[0].size();

    visited[x][y] = true;
    ans.push_back(grid[x][y]);


    for(int i = 0; i<4; i++){
        int new_x = x+dx[i];
        int new_y = y+dy[i];

        if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && !visited[new_x][new_y]){
            DFS(grid, visited, ans, new_x, new_y);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    cout<< "Original Grid -";
    for(int i = 0; i < n; i++){
        cout << endl;
        for(int j = 0; j < m; j++){
            cout << grid[i][j] << " ";
        }
    }
    vector<int> ans;
    DFS(grid, visited, ans, 0, 0);

    cout << endl;

    cout << "BFS Traversal - ";
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}