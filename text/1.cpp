#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        // 如果中间元素比右边的元素大，则峰值可能在左边
        if (nums[mid] > nums[mid + 1]) {
            right = mid;
        } else { // 否则峰值在右边
            left = mid + 1;
        }
    }
    // left 和 right 会相遇在峰值点
    return left;
}

int main() {
    vector<int> nums1 = {2, 4, 1, 2, 7, 8, 4};
    vector<int> nums2 = {1, 2, 3, 1};

    cout << "Peak index in nums1: " << findPeakElement(nums1) << endl;
    cout << "Peak index in nums2: " << findPeakElement(nums2) << endl;

    return 0;
}
