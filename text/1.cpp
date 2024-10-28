#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        // ����м�Ԫ�ر��ұߵ�Ԫ�ش����ֵ���������
        if (nums[mid] > nums[mid + 1]) {
            right = mid;
        } else { // �����ֵ���ұ�
            left = mid + 1;
        }
    }
    // left �� right �������ڷ�ֵ��
    return left;
}

int main() {
    vector<int> nums1 = {2, 4, 1, 2, 7, 8, 4};
    vector<int> nums2 = {1, 2, 3, 1};

    cout << "Peak index in nums1: " << findPeakElement(nums1) << endl;
    cout << "Peak index in nums2: " << findPeakElement(nums2) << endl;

    return 0;
}
