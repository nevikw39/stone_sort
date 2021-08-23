#if !__clang__ || __clang_major__ >= 12
#include <iostream>
#include <vector>
using namespace std;
#endif

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

#if !__clang__ || __clang_major__ >= 12
int main()
{
    vector<int> a1 = {1, 3}, a2 = {2}, b1 = {1, 2}, b2 = {3, 4}, c1 = {0, 0}, c2 = {0, 0}, d1, d2 = {1}, e1 = {2}, e2;
    Solution sln;
    cout << sln.findMedianSortedArrays(a1, a2) << '\n'
         << sln.findMedianSortedArrays(b1, b2) << '\n'
         << sln.findMedianSortedArrays(c1, c2) << '\n'
         << sln.findMedianSortedArrays(d1, d2) << '\n'
         << sln.findMedianSortedArrays(e1, e2) << '\n';
    return 0;
}
#endif
