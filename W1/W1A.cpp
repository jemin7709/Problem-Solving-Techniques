#include <iostream>
#include <vector>

using namespace std;

int GCD(int a, int b) {
    int c;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m, temp, ians, bans;
        vector<int> in, bi;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            cin >> temp;
            in.push_back(temp);
            if (i == 0) bans = temp;
            else bans = GCD(bans, temp);
        }
        for (int i = 0; i < m; i++) {
            cin >> temp;
            bi.push_back(temp);
            if (i == 0) ians = temp;
            else ians = GCD(ians, temp);
        }
        for (int i = 0; i < n; i++) {
            if (!(in[i] % ians)) ians = -1;
        }
        for (int i = 0; i < m; i++) {
            if (!(bi[i] % bans)) bans = -1;
        }
        cout << ians << ' ' << bans << endl;
    }
    return 0;
}