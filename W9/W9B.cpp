#include <iostream>
#include <string>
#include <vector>
#define STRMAX 1001
using namespace std;
// 편집거리

vector<vector<int>> memo(STRMAX, vector<int>(STRMAX, 0));

int edit_dist(string X, string Y, int xlen, int ylen) {
    for (int i = 1; i <= xlen; i++) memo[i][0] = i;
    for (int i = 1; i <= ylen; i++) memo[0][i] = i;
    for (int i = 1; i <= xlen; i++) {
        for (int j = 1; j <= ylen; j++) {
            if (X[i - 1] == Y[j - 1]) memo[i][j] = memo[i - 1][j - 1];
            else {
                memo[i][j] = min(memo[i - 1][j - 1],
                                 min(memo[i - 1][j], memo[i][j - 1])) +
                             1;
            }
        }
    }
    return memo[xlen][ylen];
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string X, Y;
        cin >> X >> Y;
        cout << edit_dist(X, Y, X.size(), Y.size()) << endl;
    }
    return 0;
}