#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, d, mid1, mid2, c, count, median, alert = 0;
        bool odd;
        vector<int> calories(201, 0);
        queue<int> q;
        cin >> n >> d;

        if ((odd = d % 2)) mid1 = d / 2 + 1;
        else {
            mid1 = d / 2;
            mid2 = mid1 + 1;
        }

        for (int i = 1; i <= n; i++) {
            cin >> c;
            if (i <= d) {
                calories[c]++;
                q.push(c);
            } else {
                median = 0;
                count = 0;
                for (int j = 0; j <= 200; j++) {
                    if (calories[j] != 0) {
                        count += calories[j];
                        if (odd) {
                            if (count >= mid1) {
                                median = j;
                                break;
                            }
                        } else {
                            if (median == 0 && count >= mid1) median = j;
                            if (count >= mid2) {
                                median += j;
                                break;
                            }
                        }
                    }
                }
                if (odd && c >= 2 * median) alert++;
                else if (!odd && c >= median) alert++;
                calories[q.front()]--;
                calories[c]++;
                q.push(c);
                q.pop();
            }
        }
        cout << alert << endl;
    }
    return 0;
}