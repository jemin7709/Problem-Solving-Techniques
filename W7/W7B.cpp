#include <iostream>
#include <map>
#include <string>
using namespace std;
// 커플 미팅

int main() {
    int T;
    cin >> T;
    while (T--) {
        int len = 0, max_len = 0, sum = 0;
        map<int, int> hash;
        string S;
        cin >> S;
        S.insert(0, "0");
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '0') sum -= 1;
            else sum += 1;
            if (hash.find(sum) != hash.end()) len = i - hash[sum];
            else hash[sum] = i;
            max_len = max(max_len, len);
        }
        cout << max_len << endl;
    }
}