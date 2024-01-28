#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    string l;
    string h;
    bool processingL = true; 

    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '#' && s[i] != ' ') {
            if (processingL) {
                l += s[i];
            } else {
                h += s[i];
            }
        } else if (s[i] == ' ') {
            processingL = false; 
        } else if (s[i] == '#') {
            if (processingL) {
                l.erase(l.end() - 1); 
            } else {
                h.erase(h.end() - 1);
            }
        }
    }
    if(l == h){
        cout << "Yes";
    }else{
        cout<< "No";
    }


    return 0;
}
