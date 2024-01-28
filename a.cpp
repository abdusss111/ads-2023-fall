#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr;
    for (int i = n; i <= m; i++) {
        arr.push_back(i);
    }

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int x;
    while (cin >> x) {
        arr.erase(remove(arr.begin(), arr.end(), x), arr.end());
    }

    sort(arr.begin(), arr.end());


    
    cout << endl;

    return 0;
}
