#include <iostream>
#include <cmath>
using namespace std;


int main(){
    int n; cin >> n;

    if(n == 1){
        cout << 2;
        return 0;
    }
    else if(n == 2) {
        cout << 3;
        return 0;
    }
    int  cnt = 2;

    for(int i = 5 ; i < 1000000; i++){
        int l = sqrt(i);
        int j = 2;
        bool flag  = false;
        while (j <= l){
            if (i % j == 0){
                flag = true;
                break;
            }j++;
        }
        if(flag == false ){
            cnt++;
        }
        if(cnt == n){
            cout << i;
            return 0;
        }
    }
}
