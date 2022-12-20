#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long int m;
        int days, ans = 0;
        cin >> m;
        while (m) {
            if (m % 10 > 5) {
                days = 10 - m % 10;
                m += days;
            } else if (m % 10 < 5) {
                days = m % 10;
                m -= days;
            } else {
                days = 5;
                if ((m / 10) % 10 >= 5) {
                    m += days;
                } else {
                    m -= days;
                }
            }
            ans += days;
            m /= 10;
        }
        cout << ans << endl;
    }
    return 0;
}