#include <iostream>

using namespace std;

constexpr int MAX_N = 50;

int n;
int a[MAX_N];


void solve()
{
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int len = a[i] + a[j] + a[k];
                int ma = max(a[i], max(a[j], a[k]));
                int rest = len - ma;

                if (ma < rest) {
                    ans = max(ans, len);
                    cout << "ans = " << ans << endl;
                }
            }
        }
    }

    cout << ans << endl;
}

int main()
{
    cin >> n;
    cout << "n = " << n << endl;
    int tmp;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        a[i] = tmp;
    }

    solve();

    return 0;
}