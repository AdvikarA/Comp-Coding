#include <fstream>
using namespace std;
int ans = 0; 
bool cornerinside(int px, int py, int cx1, int cy1, int cx2, int cy2);
int main(){
    ifstream fin("billboard.in");
    ofstream fout("billboard.out");
    int lx1, lx2, ly1, ly2, cx1, cx2, cy1, cy2;
    fin >> lx1 >> ly1 >> lx2 >> ly2 >> cx1 >> cy1 >> cx2 >> cy2; 
    int corners = 0;
    if(cornerinside(lx2, ly2, cx1, cy1, cx2, cy2)){
        corners++; 
    }
    if(cornerinside(lx2, ly1, cx1, cy1, cx2, cy2)){
        corners++; 
    }
    if(cornerinside(lx1, ly2, cx1, cy1, cx2, cy2)){
        corners++; 
    }
    if(cornerinside(lx1, ly1, cx1, cy1, cx2, cy2)){
        corners++; 
    }

    if(corners == 1 || corners == 0){
        ans = abs((lx2-lx1) * (ly2-ly1));
    }
    else if(corners == 2){
        if(lx1 <= cx1){
            ans = abs((cx1-lx1) * (ly2-ly1));
        }
        else if(lx2 >= cx2){
            ans = abs((lx2-cx2) * (ly2-ly1));
        }
        else if(ly1 <= cy1){
            ans = abs((cy1-ly1)*(lx2-lx1));
        }
        else if(ly2 >= cy2){
            ans = abs((ly2-cy2)*(lx2-lx1));
        }
    }
    else{
        ans = 0; 
    }
    fout << ans; 
}
bool cornerinside(int px, int py, int cx1, int cy1, int cx2, int cy2){
    if((px >= cx1 && px <= cx2) && (py >= cy1 && py <= cy2)){
        return true;
    }
    else{
        return false;
    }
}
