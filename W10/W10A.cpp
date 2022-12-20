#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// 함수값 계산

long long Fx(vector<int>& A, int X) {
    long long sum = 0, base = 1;
    for (int i = 0; i < A.size(); i++) {
        if (i > 0) base *= X;
        sum += A[i] * base;
    }
    return sum;
}

int counter(vector<int>& input, int p, int q, int X) {
    int temp, ans = 0;
    sort(input.begin(), input.end());
    do {
        temp = Fx(input, X) % 1013;
        if (p <= temp && temp <= q) ans++;
    } while (next_permutation(input.begin(), input.end()));
    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, p, q, X;
        cin >> N;
        vector<int> input(N, 0);
        for (int i = 0; i < N; i++) cin >> input[i];
        cin >> p >> q >> X;
        cout << counter(input, p, q, X) << endl;
    }
    return 0;
}