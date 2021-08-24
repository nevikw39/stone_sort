#include <iostream>
#include <vector>
#include <random> // for mt19937

using namespace std;

long long merge_sort_and_inversion(vector<int>::iterator begin, vector<int>::iterator end)
{
    if (end - begin == 1)
        return 0;
    auto mid = begin + ((end - begin) >> 1);
    vector<int> left(begin, mid), right(mid, end);
    long long inversions = merge_sort_and_inversion(left.begin(), left.end()) + merge_sort_and_inversion(right.begin(), right.end());
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
    vector<int> v = {8, 27, 2021, 110, 20};
    cout << merge_sort_and_inversion(v.begin(), v.end()) << '\n';
    
    int n;
    cin >> n;
    v.resize(n);
    mt19937 _rand((random_device())()); // create an object with random seed that generates random numbers using Mersenne Twister Algo
    for (int &i : v)
    {
        i = _rand();
        cout << i << ' ';
    }
    cout << '\n' << merge_sort_and_inversion(v.begin(), v.end()) << '\n';
    return 0;
}