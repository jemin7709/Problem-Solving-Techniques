#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        bool flag = true;
        string s1, s2;
        vector<bool> alphabet1(26, false), alphabet2(26, false);

        cin >> s1 >> s2;
        for (char c: s1) alphabet1[c - 'A'] = true;
        for (char c: s2) alphabet2[c - 'A'] = true;
        for (int i = 0; i < 26; i++) {
            if (alphabet1[i] != alphabet2[i]) flag = false;
        }
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}