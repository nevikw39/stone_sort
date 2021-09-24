#include <iostream>
#include <vector>
#include <random> // for mt19937
#include <chrono> // for steady_clock, ...

using namespace std;
using namespace chrono;

void merge_sort(vector<int>::iterator begin, vector<int>::iterator end)
{
    // 0. recursion boundary
    if (end - begin == 1)
        return;
    // 1. Divide
    auto mid = begin + (end - begin) / 2; // mid = (begin + end) / 2
    vector<int> left(begin, mid), right(mid, end);
    // 2. Conquer
    merge_sort(left.begin(), left.end());
    merge_sort(right.begin(), right.end());
    // 3. Combine
    for (auto itr = left.begin(), jtr = right.begin(); begin != end; begin++)
        if (itr != left.end() && jtr != right.end())
        {
            if (*itr < *jtr)
                *begin = *itr++;
            else
                *begin = *jtr++;
        }
        else if (itr != left.end())
            *begin = *itr++;
        else
            *begin = *jtr++;
    //// shorter version
    // for (auto itr = left.begin(), jtr = right.begin(); begin != end; begin++)
    //     if (itr != left.end() && (jtr == right.end() || *itr < *jtr))
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
    mt19937 _rand((random_device())()); // create an object with random seed that generates random numbers using Mersenne Twister Algo
    for (int &i : v)
        i = _rand();
    cout << "Before sorting:\n";
    for (const int &i : v)
        cout << i << ' ';
    auto start = steady_clock::now();
    merge_sort(v.begin(), v.end());
    auto end = steady_clock::now();
    cout << "\n\nAfter sorting:\n";
    for (const int &i : v)
        cout << i << ' ';
    cout << "\nMerge Sort: "
         << duration<double, std::milli>(end - start).count() << "ms.\n";
    return 0;
}