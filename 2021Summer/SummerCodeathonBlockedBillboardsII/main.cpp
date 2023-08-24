#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("billboard.in");
    ofstream fout("billboard.out");
    int badx1, badx2, bady1, bady2;
    int goodx1, goodx2, goody1, goody2;
    fin >> badx1 >> bady1 >> badx2 >> bady2;
    fin >> goodx1 >> goody1 >> goodx2 >> goody2;

    //case with 1 corner covered
    if(goodx1 <= badx2 && goodx1 >= badx1 && goody1 <= bady2 && goody1 >= bady1){
        fout << abs(bady2-bady1) * abs(badx2-badx1); 
    }
    else if(goodx1 <= badx2 && goodx1 >= badx1 && goody2 <= bady2 && goody2 >= bady1){
        fout << abs(bady2-bady1) * abs(badx2-badx1); 
    }
    else if(goodx2 <= badx2 && goodx2 >= badx1 && goody2 <= bady2 && goody2 >= bady1){
        fout << abs(bady2-bady1) * abs(badx2-badx1); 
    }
    else if(goodx2 <= badx2 && goodx2 >= badx1 && goody1 <= bady2 && goody1 >= bady1){
        fout << abs(bady2-bady1) * abs(badx2-badx1); 
    }
    else if(goodx1 <= badx2 && goodx1 >= badx1 && goodx2 >= badx2 && goody1 <= bady1 && goody2 >= bady2){
        fout << abs(bady2-bady1) * abs(goodx1 - badx1); 
    }
    else if(goodx1 <= badx1 && goodx2 >= badx2 && goody1 <= bady2 && goody1 >= bady1 && goody2 >= bady2){
        fout << abs(bady2-bady1) * abs(goody1 - bady1); 
    }
    else if(goody1 <= bady1 && goody2 >= bady2 && goodx2 >= badx1 && goodx2 <= badx2 && goodx1 <= badx1){
        fout << abs(bady2 - bady1) * abs(badx2 - goodx2);
    }
    else if(goodx1 <= badx1 && goodx2 >= badx2 && goody2 >= bady1 && goody2 <= bady2 && goody1 <= bady1){
        fout << abs(badx2 - badx1) * abs(bady2 - goody2); 
    }
    


    //case with all corners covered
    else if(goodx1 <= badx1 && goody1 <= bady1 && goodx2 >= badx2 && goody2 >= bady2){
        fout << 0; 
    }
    else{
        fout << abs(bady2-bady1) * abs(badx2-badx1); 
    }

    //case with 0 corners covered
}