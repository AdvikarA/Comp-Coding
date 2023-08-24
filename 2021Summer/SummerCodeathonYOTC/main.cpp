#include <iostream>
#include <string>
#include <map>
using namespace std; 
int main() {
    string years[12] = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
    int n;
    string words[8]; 
    cin >> n;
    int yearindex = 0; 
    string cowa, born, in, relation, animal, year, from, cowb; 
    map<string,int> whenborn;  
    whenborn["Bessie"] = 1000; 
    int cowplace = 0; 
    for (int t = 0; t < n; t++){
        cin >> cowa >> born >> in >> relation >> animal >> year >> from >> cowb;
        whenborn[cowa] = whenborn[cowb]; 
        cowplace = yearindex; 
        for(int i = 0; i < 12; i++){
            //cout << animal << " " << years[i] << " " << yearindex << "\n";
            if(animal == years[i]){
                yearindex = i; 
            }
            
        }  
        if(relation == "previous"){
            if((cowplace - (12-abs(cowplace - yearindex)) <= 0)){
                whenborn[cowa] -= (12 - abs(cowplace - yearindex));
            }
            else{
                whenborn[cowa] -= yearindex; 
            }
            //cout << "\n" << "MATH " << (12 - abs(cowplace - yearindex));
        }
        if(relation == "next"){
            if((cowplace + (12 - abs(cowplace - yearindex)) >= 11)){
                whenborn[cowa] += (12 - abs(cowplace - yearindex)); 
            }
            else{
                whenborn[cowa] += yearindex; 
            }
        }
        
        //cout << whenborn[cowa] << " " << "yearindex " << yearindex << "\n";
        if(cowa == "Elsie"){
            cout << abs(1000-(whenborn["Elsie"]));
        }
    }
}

//Abc born in previous Pig year from Bessie
//Okso born in next Ox year from Abc
//Kookw born in  next Dragon year from Okso
//Elsie born in previous Snake year from Kookw
