#include <iostream>
#include <queue>

using namespace std;

int main(){
    bool flag = true;
    deque <int> deq;
    while(flag){
        char l; cin >> l;
        if(l == '!'){
            flag = false;//
        }
        if(l == '*'){
            if(deq.empty() == true){
                cout << "error" << endl;
            }
            if(deq.size() == 1){
                cout <<  deq.front() * 2 << endl;
                deq.pop_front();
            }
            if(deq.size() > 1){
            cout <<  deq.front() + deq.back() << endl; //  + 216  12 
            deq.pop_back();
            deq.pop_front();
            }

        }
        if(l == '+' || l == '-'){
            int a; cin >> a;
            if(l == '+'){
                deq.push_front(a);
            }else{
                deq.push_back(a);
            }
        }
    }

}
