#include <iostream>

#include <vector>

// feature first

using namespace std;
// release 02
// second feature

// hotfix 02

// release 02
// release 03
// second feature

int main() {

    // bugfix

    int n;
    cin >> n;
    int a;
    vector <int> arr;
    for (int i = 0; i < n; i++)  {
        cin >> a;
        arr.push_back(a);
    }
    int num;
    cin >> num;
    for (int i = 0; i < n; i++) {
        arr.at(i) = arr.at(i) - num;

    }
    int min = arr.at(0);
    for (int i = 0; i < n; i++) {
        if (abs(min) > abs(arr.at(i)))
            min = arr.at(i);
    }
    cout << min + num;
