#include <bits/stdc++.h>
using namespace std;

// pass by reference
void foo(vector<int> &vec) {
    vec.push_back(50);
}

int main() {

    // Method 01    
    vector<int> v1 = {11, 23, 45, 89};

    // Method 02
    vector<int> v2;
    v2.push_back(11);
    v2.push_back(23);
    v2.push_back(45);
    v2.push_back(89);

    // printing...
    for (auto i : v1)
        cout << i << " ";

    // passing as a parameter
    foo(v1);

    // printing...
    for (auto i : v1)
        cout << i << " ";

    // size of array
    cout << v2.size();

    // sorting (ascending)
    stable_sort(v1.begin(), v1.end());

    return 0;
}
