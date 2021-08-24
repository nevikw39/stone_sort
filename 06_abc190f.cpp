#include <iostream>
#include <vector>

using namespace std;

long long merge_sort_and_inversion(vector<long long>::iterator begin, vector<long long>::iterator end)
{
    if (end - begin == 1)
        return 0;
    auto mid = begin + ((end - begin) >> 1);
    vector<long long> left(begin, mid), right(mid, end);
    long long inversions = merge_sort_and_inversion(left.begin(), left.end());
    inversions += merge_sort_and_inversion(right.begin(), right.end());
    for (auto itr = left.begin(), jtr = right.begin(); begin != end; begin++)
        if (itr != left.end() && jtr != right.end())
        {
            if (*itr < *jtr)
                *begin = *itr++;
            else
            {
                inversions += left.end() - itr; // if *itr > *jtr, then there would be (left.size() - i) inversions
                *begin = *jtr++;
            }
        }
        else if (itr != left.end())
            *begin = *itr++;
        else
            *begin = *jtr++;
    return inversions;
}

int main()
{
    long long n, r;
    cin >> n;
    vector<long long> origin(n), sorted;
    for (auto &i : origin)
        cin >> i;
    sorted = origin;
    r = merge_sort_and_inversion(sorted.begin(), sorted.end());
    for (const auto &i : origin)
    {
        cout << r << '\n';
        r += n - 1 - i * 2;
    }
    return 0;
}