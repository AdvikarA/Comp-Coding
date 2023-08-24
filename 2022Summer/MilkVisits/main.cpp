#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

const int MAXN = 100000;

int N, M;
string milk_type;
vector<int> adj[MAXN];


int color[MAXN]; // 0 if not visited, if > 0, its component/color
int curr_color = 1;

void dfs(int node, char milk) {
    // it's already been visited
    if (color[node] != 0 || milk_type[node] != milk) {
        return;
    }

    color[node] = curr_color;
    for (int neighbor: adj[node]) {
        dfs(neighbor, milk);
    }
}

int32_t main(){
    //ifstream cin("test.in");
    ifstream cin("milkvisits.in"); ofstream cout("milkvisits.out");

    cin >> N >> M;
    cin >> milk_type;

    for (int i=0; i<N-1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i=0; i<N; i++) {
        if (color[i] == 0) {
            // we have not yet visited the node
            // let's visit the node
            dfs(i, milk_type[i]);
            curr_color ++;
        }

    }

    // answer queries
    for (int i=0; i<M; i++) {
        int a, b;
        char milk;
        cin >> a >> b >> milk;
        a--; b--;

        // different components
        if (color[a] != color[b]) {
            cout << 1;
        }
        // same component
        else {
            if (milk == milk_type[a]) {
                cout << 1;
            }
            else {
                cout << 0;
            }
        }
    }
    cout << endl;
}