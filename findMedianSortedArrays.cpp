#include <iostream>
#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int i = 0, j = 0;
    int pre_median = nums1[0], median = nums1[0];
    int commom_size = nums1.size() + nums2.size();
    for (int k = 0; k <= commom_size / 2.0; k++) {
        if (nums1[i] <= nums2[j]) {
            pre_median = median;
            median = nums1[i];
            i += 1;
            if (i == nums1.size()) {
                nums1.push_back(nums2[j]);
            }
        }
        else if (nums1[i] > nums2[j]) {
            pre_median = median;
            median = nums2[j];
            j += 1;
            if (j == nums2.size()) {
                nums2.push_back(nums1[i]);
            }
        }
    }
    if (commom_size % 2 != 0) {
        return median;
    }
    else {
        return ((pre_median + median) / 2.0);
    }
}

int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2, 4};
    cout << findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
