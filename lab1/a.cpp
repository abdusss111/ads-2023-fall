#include <iostream>
#include <deque>

using namespace std;
int main(){
    int n; 
    cin >> n;
    deque <int> deq;
    string s;
    while(n != 0){
        int a; `
        cin >> a;
        int facto = (a  * (a - 1)) / 2 ;
        deq.push_front(a);
        if(a - 1 != 0){
                deq.push_front(a - 1);
        }
        int k = a - 1; // 43 i = 1 facto = 5
        int i = 0; 
        while(facto != 0){
            if(k == i){// 43 i = 1 facto = 5, 34 i = 2 facto = 4, 43 i = 3 facto = 3 
                i = 0;
                k--; // 2 
                deq.push_front(k);
            }
            int back = deq.back(); // 1. f = 3 
            deq.pop_back();// 4 
            deq.push_front(back);// 43 34 
            i++;
            facto--;
        }
        while(deq.empty() == false){
        cout << deq.front() << " ";
        deq.pop_front();
        }
        cout << endl;
        n--;
    }
} 




