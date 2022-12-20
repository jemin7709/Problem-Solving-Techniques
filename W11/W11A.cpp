#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

pair<int, int> get_01(long long N) {
    int c0 = 0, c1 = 0;

    do {
        if (N & 1) c1++;
        else c0++;
    } while ((N = (unsigned)N >> 1) > 0);

    return {c0, c1};
}

pair<long, long> get_cum_01(long long N) {
    long long start, temp, c0 = 0, c1 = 0;
    double loop;
    pair<int, int> N01;

    start = N;
    while ((N = N >> 1) > 0) {
        temp = start - (N - 1) - 1;
        loop = temp / N;
        c1 += N * ceil(loop / 2);
        c0 += N * trunc(loop / 2);
    }
    N01 = get_01(start);
    c0 += N01.first;
    c1 += N01.second;

    return {c0, c1};
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long N;
        pair<long, long> N01;

        cin >> N;
        N01 = get_cum_01(N);

        cout << N01.first << ' ' << N01.second << endl;
    }
    return 0;
}