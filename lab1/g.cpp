#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n; cin >> n;
    int cnt = 0;

    // int l =  int(sqrt(14));
    // cout << l;
    // return 0;
    
    int i = 2;
    int index_prime = 1;
    
    while(cnt != n){
        i++; // 5
        int cnt_prime = 0;
        for(int j = 1; j <= sqrt(i); j++){
            if(i % j == 0){
                cnt_prime++;
            }
        }
        if(cnt_prime == 1){

            int cnt_prime2 = 0; // 

            index_prime++; // 3

            for (int cnt2 = 1; cnt2 <= sqrt(index_prime);cnt2++){
                if(index_prime % cnt2 == 0){
                    cnt_prime2++;
                }
            }
            if(cnt_prime2 == 1){
                //  cout << i << " " <<   index_prime << endl;
                cnt++;
            }
        }
    }
    cout << i ;
}
