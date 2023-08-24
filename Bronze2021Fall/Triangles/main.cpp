#include <fstream>
#include <vector>
#include <utility>
using namespace std;

int main(){
    ifstream fin("triangles.in");
    ofstream fout("triangles.out");
    int n; 
    fin >> n; 
    vector <pair<int, int>> triangles; 
    for(int i = 0; i < n; i++){
        int x, y; 
        fin >> x >> y;
        triangles.push_back(make_pair(x, y)); 
    }
    int area = 0; 
    int ans = 0; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(i != j && i != k && j != k){
                    if(triangles[i].first == triangles[j].first){
                        if(triangles[j].second == triangles[k].second){
                            area = abs(triangles[i].second - triangles[j].second) * abs(triangles[k].first - triangles[j].first);
                        }
                    }
                }
                ans = max(ans, area); 
            }
        }
    }
    fout << ans; 
}