#include <fstream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ifstream fin("herding.in");
    ofstream fout("herding.out");
    vector<int> cows;
    for(int i = 0; i < 3; i++){
        int a;
        fin>>a;
        cows.push_back(a);
    }
    //min
    sort(cows.begin(), cows.end());
    int dist1 = cows[1] - cows[0];
    int dist2 = cows[2] - cows[1];
    if(dist1 == 2 || dist2 == 2){
        fout << 1 << endl; 
    }
    else if(dist1 == 1 && dist2 == 1){
        fout << 0 << endl;
    }
    else{
        fout << 2 << endl;
    }
    bool rightmost = false;
    if(dist2 > dist1){
        rightmost = true;
    }
    int steps = 0; 
    bool sorted = false;
    /**while(!sorted){
        //fout << "starting cows: " << cows[0] << " " << cows[1] << " " << cows[2] << endl;
        if(rightmost){
            int tempcow = cows[0];
            cows[0] = cows[1];
            cows[1] = cows[2]-1;
            rightmost = false;
            steps++; 
        }
        else{
            cows[2] = cows[1];
            cows[1] = cows[0]+1;
            rightmost = true;
            steps++; 
        }
        //fout << "ending cows: " << cows[0] << " " << cows[1] << " " << cows[2] << endl;

        dist1 = cows[1] - cows[0];
        dist2 = cows[2] - cows[1];
        if(dist1 == 1 && dist2 == 1){
            sorted = true; 
        }
    }**/
    fout << max(dist1, dist2) - 1;

}