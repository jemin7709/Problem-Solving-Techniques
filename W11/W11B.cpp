#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// 복싱 대회

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m, r, ans = 0;
        cin >> n >> m;

        vector<int> team(n + 1, 0);
        vector<pair<int, int>> score(m + 1, {0, 0});
        vector<int> num(m + 1, 0);

        for (int i = 1; i <= n; i++) {
            cin >> team[i];
            score[team[i]].first = n - i + 1;
            score[team[i]].second = team[i];
            if (i != 1 && team[i] == 1 && team[i - 1] != team[i]) {
                num[i]++;
                r++;
            }
        }

        while (sort(score.begin(), score.end(), greater<>()), r) {
            if (score[0].second == 1) break;
            bool match = false;
            for (int i = 0; i < m; i++) {
                if (!match && num[score[i].second] > 0) {
                    num[score[i].second]--;
                    score[i].first--;
                    match = true;
                }
                if (score[i].second == 1) {
                    score[i].first++;
                    r--;
                    ans++;
                    break;
                }
            }
        }
        if (score[0].second != 1) cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}