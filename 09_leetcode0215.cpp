#include <iostream>
#include <vector>
#include <random> // for mt19937
using namespace std;

#include "09_leetcode0215.hpp"

int main()
{
    vector<int> a = {3, 2, 1, 5, 6, 4}, b = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    Solution sln;
    cout << sln.findKthLargest(a, 2) << '\n'
         << sln.findKthLargest(b, 4) << '\n';
    return 0;
}
