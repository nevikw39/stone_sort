class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size() + nums2.size();
        vector<int> v(n / 2 + 1);
        auto itr = nums1.begin(), jtr = nums2.begin();
        for (int &k : v)
            if (itr != nums1.end() && jtr != nums2.end())
            {
                if (*itr < *jtr)
                    k = *itr++;
                else
                    k = *jtr++;
            }
            else if (itr != nums1.end())
                k = *itr++;
            else
                k = *jtr++;
        return n % 2 ? v[n / 2] : (v[n / 2] + v[n / 2 - 1]) / 2.0;
    }
};