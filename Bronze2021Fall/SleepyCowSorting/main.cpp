#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool iscorrect(vector<int>order){
    vector<int> temp = order; 
    sort(temp.begin(), temp.end());
    for(int i = 0; i < order.size(); i++){
        if(temp[i] != order[i]){
            return false;
        }
    }
    return true;
}
int main(){
    ifstream fin("sleepy.in");
    ofstream fout("sleepy.out");
    int n; 
    fin >> n; 
    vector <int> order; 
    vector <int> temper; 
    for(int i = 0; i < n; i++){
        int temp; 
        fin >> temp; 
        order.push_back(temp);
        temper.push_back(temp);
    }      
    int ans = 0; 
    for(int i = n-1; i > 0; i--){
        if(order[i] < order[i-1]){
            ans = i; 
            break; 
        }
    }
    fout << ans; 
}