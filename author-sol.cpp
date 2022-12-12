#include <bits/stdc++.h>
using namespace std;

/*



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
