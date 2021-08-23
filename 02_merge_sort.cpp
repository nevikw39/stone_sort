#include <iostream>
#include <vector>
#include <random> // for mt19937

using namespace std;

void merge_sort(vector<int>::iterator begin, vector<int>::iterator end)
{
    // 0. recursion boundary
    if (end - begin == 1)
        return;
    // 1. Divide
    auto mid = begin + ((end - begin) >> 1); // mid = (begin + end) / 2
    vector<int> a(begin, mid), b(mid, end);
    // 2. Conquer
    merge_sort(a.begin(), a.end());
    merge_sort(b.begin(), b.end());
    // 3. Combine
    for (auto itr = a.begin(), jtr = b.begin(); begin != end; begin++)
        if (itr != a.end() && jtr != b.end())
        {
            if (*itr < *jtr)
                *begin = *itr++;
            else
                *begin = *jtr++;
        }
        else if (itr != a.end())
            *begin = *itr++;
        else
            *begin = *jtr++;
    //// shorter version
    // for (auto itr = a.begin(), jtr = b.begin(); begin != end; begin++)
    //     if (itr != a.end() && (jtr == b.end() || *itr < *jtr))
    //         *begin = *itr++;
    //     else
    //         *begin = *jtr++;
}

int main()
{
    vector<int> v = {8, 27, 2021, 110, 20};
    cout << "Before sorting:\n";
    for (const int &i : v)
        cout << i << ' ';
    merge_sort(v.begin(), v.end());
    cout << "\n\nAfter sorting:\n";
    for (const int &i : v)
        cout << i << ' ';
    cout << "\n\n";
    int n;
    cin >> n;
    v.resize(n);
    mt19937 rand((random_device())()); // create an object with random seed that generates random numbers using Mersenne Twister Algo
    for (int &i : v)
        i = rand();
    cout << "Before sorting:\n";
    for (const int &i : v)
        cout << i << ' ';
    merge_sort(v.begin(), v.end());
    cout << "\n\nAfter sorting:\n";
    for (const int &i : v)
        cout << i << ' ';
    cout << '\n';
    return 0;
}