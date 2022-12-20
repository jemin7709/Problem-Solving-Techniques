#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int M, N, L, min, index;
        string bit;
        vector<string> bits;
        cin >> M >> N;
        for (int i = 0; i < M; i++) {
            cin >> bit;
            bits.push_back(bit);
        }
        cin >> L >> bit;
        for (int i = 0; i < (L / N); i++) {
            vector<int> distance(M, 0);
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < M; k++) {
                    if (bit[N * i + j] != bits[k][j]) distance[k]++;
                }
            }
            min = distance[0];
            index = 0;
            for (int j = 1; j < M; j++) {
                if (min > distance[j]) {
                    min = distance[j];
                    index = j;
                }
            }
            cout << (char) ('A' + index);
        }
        cout << endl;
    }
    return 0;
}