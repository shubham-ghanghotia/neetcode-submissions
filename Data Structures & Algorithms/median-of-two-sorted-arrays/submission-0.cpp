class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();

        vector<int>& smaller = m <= n ? nums1 : nums2;
        vector<int>& bigger  = m <= n ? nums2 : nums1;

        int total = m + n;
        int start = 0, end = smaller.size();

        while (start <= end) {
            int ps = start + (end - start) / 2;
            int pb = (total + 1) / 2 - ps;

            int l1 = ps == 0              ? INT_MIN : smaller[ps - 1];
            int r1 = ps == (int)smaller.size() ? INT_MAX : smaller[ps];
            int l2 = pb == 0              ? INT_MIN : bigger[pb - 1];
            int r2 = pb == (int)bigger.size()  ? INT_MAX : bigger[pb];

            if (l1 <= r2 && l2 <= r1) {
                if (total % 2 == 1)
                    return max(l1, l2);
                else
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
            }

            if (l1 > r2) end = ps - 1;
            else         start = ps + 1;
        }

        return 0;
    }
};