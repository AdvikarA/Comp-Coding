#include <fstream>
using namespace std; 
int main() {
    ifstream fin("lifeguards.in");
    ofstream fout("lifeguards.out");
    int n; 
    fin >> n; 
    int start_times[n]; 
    int end_times[n]; 
    int ans = 0; 
    for(int i = 0; i< n; i++){
        fin >> start_times[i] >> end_times[i];
        //big = max(big, end_times[i]); 
    }
    for(int j = 0; j < n; j++){
        bool times[1000] = {false};
        int count = 0; 
        for(int i = 0; i < n; i++){
            if(i != j){
                for(int a = start_times[i]; a < end_times[i]; a++){
                    times[a] = true;  
                }
            }
        }
        for(int i = 0; i < 1000; i++){
            if(times[i] == true){
                count++; 
            }
        }
        ans = max(count, ans);
    }
    fout << ans; 
}