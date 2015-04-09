#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ans;
        
        for (int i = 0; i < numRows; i++) {
            ans.push_back(vector<int>(i + 1, 0));
            ans[i][0] = 1;
            for (int j = 1; j < i; j++) {
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
            ans[i][i] = 1;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int> > ret;
    ret = s.generate(5);

    for (unsigned i = 0; i < ret.size(); i++) {
        for (unsigned j = 0; j < i + 1; j++) {
            cout << ret[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
