#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
// 달리기 경주

int main() {
    int T;
    cin >> T;
    while (T--) {
        int to, bi;
        double X, A, B, N;
        cin >> X >> A >> B;
        N = ceil((X - B) / (A - B));
        to = 2 * A * N;
        bi = X + A * N + B * (N - 1);
        while (to != bi) {
            to -= 2;
            bi -= 1;
        }
        cout << to << endl;
    }
    return 0;
}