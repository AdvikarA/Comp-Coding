#include <iostream>
#include <map>
using namespace std;
string animals[12] =  {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
string get_year(int y){
    int a = 0; 
    int year = 2021; 
    while(year < y){a++; year++; if(a == 12){a = 0;}}
    while(year > y){a--; year--; if(a == -1){a = 11;}}
    return animals[a]; 
}
int main() {
    int n; 
    cin >> n;
    map<string, int> m;
    m["Bessie"] = 2021; 
    for(int i = 0; i < n; i++){
        string s; 
        string born, inn, when, year, from, cow, yea; 
        cin >> s >> born >> inn >> when >> year >> yea>> from >> cow; 
        m[s] = m[cow];
        if(when == "next"){
            do{
                m[s]++; 
            }while(get_year(m[s]) != year);
        }
        if(when == "previous"){
            do{
                m[s]--; 
            }while(get_year(m[s]) != year);
        }
        if(s == "Elsie"){
            cout << abs(2021-m["Elsie"]);
        }
    }
}