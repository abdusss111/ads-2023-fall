#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue <int> b;
    queue <int> n;
    // for(int i = 0 ; i < 10; i++){
    //     if (i <= 4){
    //         int a; cin >> a;
    //         b.push(a);
    //     }else{
    //         int k; cin >> k;
    //         n.push(k);
    //     }
    // }
    for(int i = 0; i< 5; i++){
        int a; cin >> a;
        b.push(a);
    }
    for(int i = 0; i< 5; i++){
        int o; cin >> o;
        n.push(o);
    }
    int cnt = 0;

    while(b.empty() != true && n.empty() != true ){
        int bo = b.front(); int nu = n.front();

        if (b.front() == 0 && n.front() == 9){
            b.pop(); n.pop();
            b.push(bo); b.push(nu);

        }
        else if(b.front() == 9 && n.front() == 0){
            b.pop(); n.pop();
            n.push(bo); n.push(nu);

        }
        else if(b.front() > n.front()){
            b.pop(); n.pop();
            b.push(bo); b.push(nu);
        }else{
            b.pop(); n.pop();
            n.push(bo); n.push(nu);
        }
        cnt++;
    }
    
    if(n.empty()){
        cout << "Boris" << " " << cnt;
    }else if(b.empty()){
        cout << "Nursik" << " " << cnt;
    }
}

