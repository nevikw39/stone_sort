#include <iostream>
#include <vector>
#include <random>    // for mt19937
#include <algorithm> // for merge(), partition(), nth_element(), sort(), ...

using namespace std;

void merge_sort(vector<int>::iterator begin, vector<int>::iterator end)
{
    // 0. recursion boundary
    if (end - begin == 1)
        return;
    // 1. Divide
    auto mid = begin + ((end - begin) >> 1); // equal to `begin+(end-begin)/2'
    vector<int> left(begin, mid), right(mid, end);
    // 2. Conquer
    merge_sort(left.begin(), left.end());
    merge_sort(right.begin(), right.end());
    // 3. Combine
    merge(left.begin(), left.end(), right.begin(), right.end(), begin);
}

int pivot;
bool cmp_partition(int x) { return x < pivot; }
void quicksort(vector<int>::iterator begin, vector<int>::iterator end)
{
    // 0. recursion boundary
    if (end - begin <= 1)
        return;
    // 1. Divide
    pivot = *(end - 1);
    auto itr = partition(begin, end - 1, cmp_partition);
    swap(*itr, *(end - 1));
    // 2. Conquer
    quicksort(begin, itr);
    quicksort(itr + 1, end);
    // 3. Combine
    // Nothing to do
}

bool cmp_sort(int lhs, int rhs) // result be like: {1, 3, 5, 4, 2, 0}
{
    if (lhs & 1 ^ rhs & 1) // if l%2 != r%2
        return lhs & 1;    // return true if l is odd otherwise return false
    else
        return lhs & 1 ? lhs < rhs : lhs > rhs; // if l, r are both odd then return l<r else return l>r
}

int main()
{
    vector<int> v = {8, 27, 2021, 110, 20};
    cout << "v:";
    for (const int &i : v)
        cout << ' ' << i;
    cout << "\nMerge Sort.\nv:";
    merge_sort(v.begin(), v.end());
    for (const int &i : v)
        cout << ' ' << i;

    mt19937 _rand((random_device())()); // create an object with random seed that generates random numbers using Mersenne Twister Algo
    shuffle(v.begin(), v.end(), _rand);
    cout << "\n\nv:";
    for (const int &i : v)
        cout << ' ' << i;
    cout << "\nQuicksort.\nv:";
    quicksort(v.begin(), v.end());
    for (const int &i : v)
        cout << ' ' << i;

    shuffle(v.begin(), v.end(), _rand);
    cout << "\n\nv:";
    for (const int &i : v)
        cout << ' ' << i;
    nth_element(v.begin(), v.begin() + 2, v.end());
    cout << "\n2-nd element (0-indexed) is " << *(v.begin() + 2) << '\n';
    shuffle(v.begin(), v.end(), _rand);

    shuffle(v.begin(), v.end(), _rand);
    cout << "\n\nv:";
    for (const int &i : v)
        cout << ' ' << i;
    cout << "\nstd::sort().\nv:";
    sort(v.begin(), v.end());
    for (const int &i : v)
        cout << ' ' << i;

    string s = "hello world QWERTY QAZ QSC QQ wasd";
    cout << '\n' + s << '\n';
    sort(s.begin(), s.end());
    cout << s << '\n';

    shuffle(v.begin(), v.end(), _rand);
    cout << "\n\nv:";
    for (const int &i : v)
        cout << ' ' << i;
    cout << "\nstd::sort() using custom cmp.\nv:";
    sort(v.begin(), v.end(), cmp_sort);
    for (const int &i : v)
        cout << ' ' << i;
    return 0;
}
