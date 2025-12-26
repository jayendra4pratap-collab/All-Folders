#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<vector<int>> pos(k + 1);
        for (int i = 1; i <= n; i++) {
            int c;
            cin >> c;
            pos[c].push_back(i);
        }

        int answer = n; 

        for (int color = 1; color <= k; color++) {
            if (pos[color].empty()) continue;

            int max_gap = 0, second_max = 0;

           
            int prev = 0;
            for (int p : pos[color]) {
                int gap = p - prev - 1;
                if (gap > max_gap) {
                    second_max = max_gap;
                    max_gap = gap;
                } else if (gap > second_max) {
                    second_max = gap;
                }
                prev = p;
            }

            
            int gap = n - prev;
            if (gap > max_gap) {
                second_max = max_gap;
                max_gap = gap;
            } else if (gap > second_max) {
                second_max = gap;
            }

            int best_with_repaint = max(second_max, max_gap / 2);
            int best_for_color = min(max_gap, best_with_repaint);

            answer = min(answer, best_for_color);
        }

        cout << answer << "\n";
    }
    return 0;
}