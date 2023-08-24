#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
int visited[7][7]; 
int graph[7][7]; 
vector<int> adj[6][6]; 
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int ans = 0; 
void flood(int r, int c, int numL, int numR, bool second){
    if(numL == numR){
        ans = max(ans, numL + numR); 
        return;
    }
    visited[r][c] = 1;
    for(int i = 0; i < 4; i++){
        int rr = r + dx[i];
        int cc = c + dy[i]; 

        if(!visited[rr][cc]){
            //cout << rr << " " << cc << "\n";
            if(graph[rr][cc] == 1){
                flood(rr, cc, numL, numR+1, true);
            }
            else if (!second){
                flood(rr, cc, numL+1, numR, false); 
            }
        }
    }
    visited[r][c] = 0;
}
int main(){
    ifstream fin ("hshoe.in");
    ofstream fout ("hshoe.out");
    int n; 
    fin >> n; 
    for(int i = 0; i <= 7; i++){
        for(int j = 0; j <= 7; j++){
            visited[i][j] = 0; 
        }
    }
    for(int i = 0; i <= n+1; i++){
        visited[0][i] = 1;
        visited[n+1][i] = 1;
        visited[i][0] = 1; 
        visited[i][n+1] = 1;
        graph[0][i] = -1;
        graph[n+1][i] = -1;
        graph[i][0] = -1; 
        graph[i][n+1] = -1;

    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char input; 
            fin >> input; 
            int num = 2; 
            if (input == '('){
                num = 0; 
            }
            else if (input == ')'){
                num = 1; 
            }
            graph[i][j] = num; 


        }
    }
    if(graph[1][1]==0){
        flood(1, 1, 1, 0, false); 
    }
    fout << ans;
}
// in main
