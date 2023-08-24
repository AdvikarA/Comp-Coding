#include <iostream>
using namespace std;
float beats(int arr1[], int arr2[]){
    float chance = 0;
    float totals = 0;
    for(int j = 0; j < 4; j++){
        float a = 0; 
        int total = 4;
        for(int i = 0; i < 4; i++){
            //cout << arr1[j] << " " << arr2[i] << "\n";
            if(arr1[j] == arr2[i]){
                total--; 
            }
            if(arr1[j]> arr2[i]){
                a++; 
            }
        }
        //cout << "A: " << a << "\n";
        chance += a; 
        totals += total;
    }
    //cout << chance <<"/"<<totals<<"\n";
    return (chance/totals); 
}
int main(){
    int n; cin >> n;
    for(int ii = 0; ii < n; ii++){
        bool solved = false;
        while(!solved){
            int arr1[4]; int arr2[4];
            for(int i = 0; i < 4; i++){
                cin >> arr1[i];
            }
            for(int i = 0; i < 4; i++){
                cin >> arr2[i];
            }
            if(beats(arr1, arr2) > beats(arr2, arr1)){
                int arr3[4];
                for(int i = 1; i < 11; i++){
                    arr3[0] = i; 
                    for(int j = 1; j < 11; j++){
                        arr3[1] = j; 
                        for(int l = 1; l < 11; l++){
                            arr3[2] = l;
                            for(int k = 1; k < 11; k++){
                                arr3[3] = k;
                                if((beats(arr2, arr3) > beats(arr3, arr2)) && (beats(arr3, arr1) > beats(arr1, arr3))){
                                    
                                    cout << "yes\n"; 
                                    solved = true;
                                    goto END;
                                }
                            } 
                        }
                    
                    }
                }
            }
            else if (beats(arr2, arr1) > beats(arr1, arr2)){
                int arr3[4];
                for(int i = 1; i < 11; i++){
                    arr3[0] = i; 
                    for(int j = 1; j < 11; j++){
                        arr3[1] = j; 
                        for(int l = 1; l < 11; l++){
                            arr3[2] = l;
                            for(int k = 1; k < 11; k++){
                                arr3[3] = k;
                                if((beats(arr1, arr3) > beats(arr3, arr1)) && (beats(arr3, arr2) > beats(arr2, arr3))){
                                    cout << "yes\n"; 
                                    solved = true;
                                    goto END;
                                }
                            } 
                        }
                    
                    }
                }
            }
            cout << "no\n";
            solved = true;
            END: 
            ;
        }    
    }   
}