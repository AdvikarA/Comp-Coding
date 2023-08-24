#include <fstream>
using namespace std;
int main(){
    ifstream fin("mixmilk.in");
    ofstream fout("mixmilk.out"); 
    int max[3];
    int milk[3];
    for(int i = 0; i < 3; i++){
        fin >> max[i] >> milk[i];
    }
    for(int i = 0; i < 100; i++){
        
        if(milk[i%3]+milk[(i+1)%3] <= max[(i+1)%3]){
            milk[(i+1)%3] += milk[i%3];
            milk[i%3] = 0; 
        }
        else{
            milk[i%3] -= (max[(i+1)%3] - milk[(i+1)%3]); 
            milk[(i+1)%3] = max[(i+1)%3];
        }
    }

    for(int i = 0; i < 3; i++){
        fout << milk[i] << "\n"; 
    }

}
