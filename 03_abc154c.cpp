#include <iostream>
#include <vector>

using namespace std;

bool merge_sort(vector<int>::iterator begin, vector<int>::iterator end)
{
    // 0. recursion boundary
    if (end - begin == 1)
        return true;
    // 1. Divide
    auto mid = begin + ((end - begin) >> 1); // mid = (begin + end) / 2
    vector<int> left(begin, mid), right(mid, end);
    // 2. Conquer
    if (!merge_sort(left.begin(), left.end()) || !merge_sort(right.begin(), right.end()))
        return false;
    // 3. Combine
    for (auto itr = left.begin(), jtr = right.begin(); begin != end; begin++)
        if (itr != left.end() && jtr != right.end())
        {
            if (*itr < *jtr)
                *begin = *itr++;
            else if (*itr == *jtr)
                return false;
            else
                *begin = *jtr++;
        }
        else if (itr != left.end())
            *begin = *itr++;
        else
            *begin = *jtr++;
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    cout << (merge_sort(v.begin(), v.end()) ? "YES\n" : "NO\n");
    return 0;
}