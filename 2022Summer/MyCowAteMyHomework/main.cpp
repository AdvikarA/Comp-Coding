#include <iostream>
#include <fstream>
#include <set>
#include <vector>
using namespace std;
 
int main(){
    ifstream infile("homework.in");
    ofstream outfile;
    outfile.open("homework.out");
    int n;
    infile >> n;
    int questions[n];
    long long total = 0;
    multiset<int> stage;
    vector<int> indices;
    for(int i=0; i<n; i++)
    {
        infile >> questions[i];
        total+=questions[i];
        stage.insert(questions[i]);
    }
    total-=(*stage.begin());
    //cout << total << endl;
    double maxscore = 0.0;
    for(int k=1; k<n-1; k++)
    {
        if((*stage.begin()==questions[k-1]))
        {
            stage.erase(questions[k-1]);
            total-=(*stage.begin());
        }
        else
        {
            total-=(questions[k-1]);
            stage.erase(questions[k-1]);
        }
        if(total*1.0/(n-k-1)>maxscore)
        {
            maxscore = total*1.0/(n-k-1);
            indices.clear();
            indices.push_back(k);
        }
        else if(total*1.0/(n-k-1)==maxscore)
            indices.push_back(k);
    }
    //cout << maxscore << endl;
    for(int i=0; i<indices.size(); i++)
    {
        outfile << indices[i] << endl;
    }
    outfile.close();
    infile.close();
}