#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
static int teamc[4];
static int cow[12];
static int skillarr[12];
static int ans = 1000000;
void recurse(int playa){
    int teamskill[4] = {0, 0, 0, 0};
    if(playa == 12){
        for(int i = 0; i < 12; i++){
            teamskill[cow[i]]+=skillarr[i];
        }
        int big = max(teamskill[0], max(teamskill[1], max(teamskill[2], teamskill[3])));
        int small = min(teamskill[0], min(teamskill[1], min(teamskill[2], teamskill[3])));
        ans = min(ans, big-small);
    }
    for(int i = 0; i < 4; i++){
        if(teamc[i]<3){
            cow[playa] = i;
            teamc[i]++;
            recurse(playa+1);
            teamc[i]--;
        }
    }
}
int main(){
    ifstream fin ("bteams.in");
    for(int i = 0; i < 12; i++){
        int a;
        fin >> a;
        skillarr[i] = a;
    }
    recurse(0);
    ofstream fout ("bteams.out");
    fout<<ans;

}