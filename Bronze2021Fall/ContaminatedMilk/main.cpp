#include <fstream>
#include <vector>
using namespace std;
int main(){
    ifstream fin("badmilk.in");
    ofstream fout("badmilk.out");
    int N, M, D, S;
    int doses_needed = 0; 
    fin >> N >> M >> D >> S; 
    vector <int> event_person; 
    vector <int> event_milk_type;
    vector <int> event_time; 
    vector <int> sick_person_arr;
    vector <int> sick_time_arr; 
    for(int i = 0; i < D; i++){
        int a, b, c;
        fin >> a >> b >> c;
        event_person.push_back(a); 
        event_milk_type.push_back(b);
        event_time.push_back(c); 
    }
    for(int i = 0; i < S; i++){
        int a, b;
        fin >> a >> b; 
        sick_person_arr.push_back(a);
        sick_time_arr.push_back(b); 
    }
    for(int i = 0; i < M; i++){
        bool possibly_bad_milk = true; 
        for(int j = 0; j < S; j++){
            int sick_person = sick_person_arr[j]; 
            int sick_time = sick_time_arr[j]; 
            bool drank_milk_before_sick = false; 
            for(int k = 0; k < D; k++){
                //fout << event_person[k] << " " << sick_person << " " << event_milk_type[k] << " " << i+1 << " " << event_time[k] << " " << sick_time << "\n";
                if(event_person[k] == sick_person && event_milk_type[k] == i+1 && event_time[k] < sick_time){
                    //fout << i << "\n";
                    drank_milk_before_sick = true;  
                }
            }
            if(drank_milk_before_sick == false){
                possibly_bad_milk = false; 
            }
        }
        if(possibly_bad_milk){
            int counter = 0; 
            for(int j = 0; j < N; j++){
                bool drank_milk = false; 
                for(int k = 0; k < D; k++){
                    //fout << event_person[k] << " " << j+1 << " " << event_milk_type[k] << " " << i+1  << "\n";

                    if(j+1 == event_person[k]){
                        if(i+1 == event_milk_type[k]){
                            drank_milk = true;
                        }
                         
                    }
                }
                if(drank_milk){
                    counter++; 
                    //fout << counter << "\n";
                }
            }
            //fout << i+1 << " " << counter << "\n"; 
            doses_needed = max(doses_needed, counter); 
        }
    }
    fout << doses_needed; 
}