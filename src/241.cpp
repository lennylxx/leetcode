#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        for (int k = 0; k < input.length(); k++) {
            if (input[k] == '*' || input[k] == '-' || input[k] == '+') {
                vector<int> a = diffWaysToCompute(input.substr(0, k));
                vector<int> b = diffWaysToCompute(input.substr(k + 1));
                for (int i = 0; i < a.size(); i++) {
                    for (int j = 0; j < b.size(); j++) {
                        if (input[k] == '+') {
                            result.push_back(a[i] + b[j]);
                        }
                        else if (input[k] == '-') {
                            result.push_back(a[i] - b[j]);
                        }
                        else {
                            result.push_back(a[i] * b[j]);
                        }
                    }
                }

            }
        }
        if (result.size() == 0) {
            result.push_back(stoi(input));
        }
        return result;
    }
};

int main() {

    Solution s;
    vector<int> ans = s.diffWaysToCompute("2*3-4*5");

    for (int i = 0; i < ans.size(); i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    return 0;
}
