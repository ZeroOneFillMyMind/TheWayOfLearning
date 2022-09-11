#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    static bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = pushed.size();
        for (int i = 0, j = 0; i < n; i++) {
            st.emplace(pushed[i]);
            while (!st.empty() && st.top() == popped[j]) { // 非空 且当前栈顶元素等于目前popped栈元素 -> 出栈，popped当前元素递增
                st.pop();
                j++;
            }
        }
        return st.empty();
    }
};

void test1()
{
    vector<int> pushed{1, 2, 3, 4, 5};
    vector<int> popped{4, 5, 3, 2, 1};

    if (Solution::validateStackSequences(pushed, popped)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}

int main()
{
    test1();

    return 1;
}
