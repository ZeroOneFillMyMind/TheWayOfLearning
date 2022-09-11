#include <iostream>
#include <array>

using namespace std;

constexpr unsigned int MAX_SIZE = 10;

#pragma region
void JudgeTri(const array<int, MAX_SIZE> &arr)
{
    int res{};

    for(auto i = 0; i < MAX_SIZE; ++i) {
        for (auto j = i + 1; j < MAX_SIZE; ++j) {
            for (auto k = j + 1; k < MAX_SIZE; ++k) {
                int len = arr[i] + arr[j] + arr[k];
                int ma = max(arr[i], max(arr[j], arr[k]));
                if (ma < len - ma) {
                    res = max(res, len);
                }
            }
        }
    }

    cout << "result: " << res << endl;
}


#pragma endregion

int main()
{
    int n{};
    array<int, MAX_SIZE> arr{};

    cin >> n;
    int i{};
    while (n--) {
        cin >> arr[i++];
    }

    JudgeTri(arr);

    return 0;
}