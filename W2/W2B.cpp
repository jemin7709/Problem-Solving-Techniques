#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int M, N, temp;
        string cmd1, cmd2;
        multiset<int> list;
        cin >> M >> N;
        for (int i = 0; i < M; i++) {
            cin >> temp;
            list.insert(temp);
        }
        for (int i = 0; i < N; i++) {
            cin >> cmd1;
            if (cmd1 == "Delete") {
                cin >> cmd2;
                if (cmd2 == "min") list.erase(list.begin());
                else list.erase(--list.end());
            } else {
                cin >> temp;
                list.insert(temp);
            }
        }
        cout << *list.begin() << ' ' << *--list.end() << endl;
    }
    return 0;
}