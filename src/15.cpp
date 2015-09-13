#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> > ans;
        if (n <= 2) return ans;

        quicksort(nums, 0, n - 1);

        vector<int> temp(3);
        int i, j, k, sum;
        for(k = 0; k < n && nums[k] <= 0; k++) {
            i = k + 1, j = n - 1;
            while (i < j) {
                sum = 0 - nums[k];
                if (nums[i] + nums[j] == sum) {
                    temp[0] = nums[k];
                    temp[1] = nums[i];
                    temp[2] = nums[j];
                    ans.push_back(temp);

                    do {
                        j--;
                    } while (i < j && nums[j] == nums[j + 1]);
                    do {
                        i++;
                    } while (i < j && nums[i - 1] == nums[i]);
                }
                else if (nums[i] + nums[j] > sum) {
                    j--;
                }
                else {
                    i++;
                }
            }
            while(k < n && nums[k] == nums[k + 1]) k++;
        }

        return ans;
    }

    void quicksort(vector<int> &nums, int start, int end) {
        if (start >= end) return;

        int i = start;
        int j = end;
        int sentinal = nums[start];

        while (i < j) {
            while (i < j && nums[j] >= sentinal) {
                j--;
            }
            nums[i] = nums[j];
            while (i < j && nums[i] <= sentinal) {
                i++;
            }
            nums[j] = nums[i];
        }

        nums[i] = sentinal;

        quicksort(nums, start, i - 1);
        quicksort(nums, i + 1, end);
    }
};

int main() {

    //vector<int> nums = {-1, 0, 1, 2, -1, -4};
    //vector<int> nums = {0, 0, 0, 0};
    //vector<int> nums = {-2, 0, 1, 1, 2};
    vector<int> nums = {-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6};
    Solution s;

    auto ans = s.threeSum(nums);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }

    return 0;
}
