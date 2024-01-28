#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n; cin >> n;
    int l = n;

    if(n == 2){
        cout << "YES";
        return 0;
    }
    if(n == 1){
        cout << "NO";
        return 0;
    }

    int p = sqrt(n);

    int i = 2;

    while(i < p){
        if(n % i == 0){
            cout << "NO";
            return 0;
        }
        i++;
    }
    cout << "YES";
}

