#include <fstream>
using namespace std;

int ptime[2001][2001];

int main(){
    ifstream fin("mowing.in");
    ofstream fout("mowing.out");
    int n;
    fin >> n;
    int x = 10000;  
    int currx = 1000;
    int timeel = 0; 
    int curry = 1000; 
    for(int aa = 0; aa < 2001; aa++){
        for(int bb = 0; bb < 2001; bb++){
            ptime[aa][bb] = 0; 
        }
    }
    char dir[n];
    int steps[n]; 
    for(int i = 0; i < n; i++){
        fin >> dir[i] >> steps[i];
    }
    for(int i = 0; i < n; i++){
        int posx = 0;
        int posy = 0; 
        if(dir[i] == 'N'){
                posy=1;
            }
            else if(dir[i] == 'S'){
                posy=-1;
            }
            else if(dir[i] == 'E'){
                posx=1;
            }
            else if(dir[i] == 'W'){
                posx=-1;
            }
        for(int j = 0; j < steps[i]; j++){
            timeel++;
            currx+=posx;
            curry+=posy;
            //fout << timeel << " " << ptime[currx][curry] << "\n";
            if(ptime[currx][curry] > 0 && x > timeel - ptime[currx][curry]){
                x = abs(timeel - ptime[currx][curry]);
            }
            ptime[currx][curry] = timeel; 
            
        }
    }
    if(x != 10000) fout << x; 
    else{
        fout << -1;
    }
}