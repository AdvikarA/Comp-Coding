#include <fstream>
#include <vector>
#include <set>
#include <iterator>
#include <iostream>
using namespace std;
set<int> answers;
void friday(int barn1, vector <int> buckets1, vector<int> buckets2){
    //cout << "enter Fri ";
    for(int i = 0; i < buckets2.size(); i++){
        int test = barn1 + buckets2[i];
        answers.insert(test);
        //cout << "fri "<< test << " ";
    }
    //cout << "exit Fri ";
}
void thursday(int barn1, vector <int> buckets1, vector<int> buckets2){
    //cout << "enter Thurs";
    for(int i = 0; i < buckets1.size(); i++){
        vector<int> newbucket1 = buckets1; 
        vector<int> newbucket2 = buckets2;
        newbucket2.push_back(buckets1[i]);
        newbucket1.erase(newbucket1.begin()+i);
        int test = barn1 - buckets1[i];
        //cout << i <<"thurs "<< test << " ";
        friday(test, newbucket1, newbucket2); 
    }
    //cout << "exit Thurs ";
}
void wednesday(int barn1, vector <int> buckets1, vector<int> buckets2){
    //cout << "enter WEd " << "\n";
    for(int i = 0; i < buckets2.size(); i++){
        vector<int> newbucket1 = buckets1; 
        vector<int> newbucket2 = buckets2;
        newbucket1.push_back(buckets2[i]);
        newbucket2.erase(newbucket2.begin()+i);
        int test = barn1 + buckets2[i];
        //cout << i <<"wed " << test << " ";
        thursday(test, newbucket1, newbucket2); 
    }
    //cout << "Exit Wed " << "\n";
}
void tuesday(int barn1, vector <int> buckets1, vector<int> buckets2){
    //cout << "enter Tues ";
    for(int i = 0; i < buckets1.size(); i++){
        vector<int> newbucket1 = buckets1; 
        vector<int> newbucket2 = buckets2;
        newbucket2.push_back(buckets1[i]);
        newbucket1.erase(newbucket1.begin()+i);
        int test = barn1 - buckets1[i];
        //cout << i << "tues " << test << " "; 
        wednesday(test, newbucket1, newbucket2); 
    }
    //cout << "Exit Tues "; 
}
int main(){
    ifstream fin("backforth.in");
    ofstream fout("backforth.out");

    int barn1 = 1000;
    int barn2 = 1000;
    vector <int> buckets1;
    vector <int> buckets2;
    for(int i = 0; i<10; i++){
        int a;
        fin >> a;
        buckets1.push_back(a);
    }
    for(int i = 0; i<10; i++){
        int a;
        fin >> a;
        buckets2.push_back(a);    
    }
    cout << "beforefunc" << "\n"; 
    tuesday(barn1, buckets1, buckets2); 
    cout << "afterfunc" << "\n";
    for(auto it: answers){
	    cout << it << endl;
    }   
    fout << answers.size();
}