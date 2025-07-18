#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        int count[26] = {0};
        for (char c : a) count[c - 'a']++;
        for (char c : b) count[c - 'a']--;
        
        bool ok = true;
        for (int i = 0; i < 26; ++i) {
            if (count[i] != 0) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "Possible" : "Impossible") << '\n';
    }
}
