#include <fstream>
using namespace std; 
int main(){
    ifstream fin("promote.in");
    ofstream fout("promote.out");
    int bronzebefore, bronzeafter, silverbefore, silverafter, goldbefore, goldafter, platbefore, platafter;
    fin >> bronzebefore >> bronzeafter >> silverbefore >> silverafter >> goldbefore >> goldafter >> platbefore >> platafter;
    int gold = platafter - platbefore; 
    goldbefore -= gold; 
    int silver = goldafter - goldbefore; 
    silverbefore -= silver; 
    int bronze = silverafter - silverbefore; 
    fout << bronze << "\n" << silver << "\n" << gold; 
}