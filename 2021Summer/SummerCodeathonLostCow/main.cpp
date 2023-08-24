#include <fstream>
using namespace std;
int main() {
    ifstream fin("lostcow.in");
    ofstream fout("lostcow.out");
    int x, y; 
    fin >> x >> y; 
    int pos = x; 
    int newpos = x; 
    int z = 1; 
    int ans = 0; 
    if(x < y){
        while(newpos < y){
            pos = newpos; 
            if(x+z >= y){
                ans+=abs(y-newpos); 
                newpos = x+z; 
            }
            else{
                newpos = x+z; 
                ans += abs(pos - newpos);
            }
            z *= -2; 
        }
    }
    else{
        while(newpos > y){
            int pos = newpos; 
            if(x+z <= y){
                ans+=abs(y-newpos); 
                newpos = x+z; 
            }
            else{
                newpos = x+z; 
                ans += abs(pos - newpos);
            }
            z *= -2; 
        }
    }
    fout << ans; 
}