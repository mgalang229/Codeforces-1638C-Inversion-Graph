#include <bits/stdc++.h>
using namespace std;

/*

sample input:
1
9
2 1 6 7 5 8 9 3 4

process:
largest = 2
to remove:

max elements:
2 

largest = 2
to remove:
2 
max elements:
2 

largest = 6
to remove:
none
max elements:
2 6 

largest = 7
to remove:
none
max elements:
2 6 7 

largest = 7
to remove:
6 7 
max elements:
2 7 

largest = 8
to remove:
none
max elements:
2 7 8 

largest = 9
to remove:
none
max elements:
2 7 8 9 

largest = 9
to remove:
7 8 9 
max elements:
2 9 

largest = 9
to remove:
9 
max elements:
2 9

answer = 2

*/

void perform_test() {
    int n;
    cin >> n;
    set<int> max_elements;
    int largest = 0;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        largest = max(largest, p);
        auto it = max_elements.lower_bound(p);
        vector<int> to_remove;
        while (it != max_elements.end()) {
            int value = *it;
            to_remove.push_back(value);
            it++;
        }
        for (auto it : to_remove) {
            max_elements.erase(it);
        }
        max_elements.insert(largest);
    }
    cout << (int) max_elements.size() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        perform_test();
    }
}
