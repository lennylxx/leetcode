#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2);
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int mid;
        bool found = false;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                found = true;
                break;
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        if (found) {
            low = high = mid;
            while (low >= 0 && nums[low] == target) low--;
            while (high <= n - 1 && nums[high] == target) high++;

            ans[0] = low + 1;
            ans[1] = high - 1;
        }
        else {
            ans[0] = ans[1] = -1;
        }

        return ans;
    }
};

int main () {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    Solution s;

    vector<int> ans = s.searchRange(nums, target);

    for (int i = 0; i < ans.size(); i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    return 0;
}
