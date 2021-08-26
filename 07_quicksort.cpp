#include <iostream>
#include <vector>
#include <random> // for mt19937

using namespace std;

void quicksort_in_place(vector<int>::iterator begin, vector<int>::iterator end)
{
    // 0. recursion boundary
    if (end - begin <= 1)
        return;
    // 1. Divide
    auto itr = begin, pivot = end - 1;
    for (auto jtr = begin; jtr != pivot; jtr++)
        if (*jtr < *pivot)
            swap(*itr++, *jtr);
    swap(*itr, *pivot);
    // 2. Conquer
    quicksort_in_place(begin, itr);   // [begin, itr) not include itr!!
    quicksort_in_place(itr + 1, end); // [itr + 1, end) not include itr and end!!
    // 3. Combine
    // Nothing to do
}

void quicksort(vector<int>::iterator begin, vector<int>::iterator end)
{
    // 0. recursion boundary
    if (end - begin <= 1)
        return;
    // 1. Divide
    int pivot = *(end - 1);
    vector<int> less, greater;
    for (auto itr = begin; itr != end - 1; itr++)
        if (*itr < pivot)
            less.push_back(*itr);
        else
            greater.push_back(*itr);
    // 2. Conquer
    quicksort(less.begin(), less.end());
    quicksort(greater.begin(), greater.end());
    // 3. Combine
    for (const int &i : less)
        *begin++ = i;
    *begin++ = pivot;
    for (const int &i : greater)
        *begin++ = i;
}

int main()
{
    vector<int> v = {8, 27, 2021, 110, 20};
    cout << "Before sorting:\n";
    for (const int &i : v)
        cout << i << ' ';
    quicksort_in_place(v.begin(), v.end());
    cout << "\n\nAfter sorting:\n";
    for (const int &i : v)
        cout << i << ' ';
    
    mt19937 _rand((random_device())()); // create an object with random seed that generates random numbers using Mersenne Twister Algo
    shuffle(v.begin(), v.end(), _rand);
    cout << "\n\nBefore sorting:\n";
    for (const int &i : v)
        cout << i << ' ';
    quicksort(v.begin(), v.end());
    cout << "\n\nAfter sorting:\n";
    for (const int &i : v)
        cout << i << ' ';
    cout << '\n';


    int n;
    cin >> n;
    v.resize(n);
    for (int &i : v)
        i = _rand();
    cout << "\nBefore sorting:\n";
    for (const int &i : v)
        cout << i << ' ';
    quicksort_in_place(v.begin(), v.end());
    cout << "\n\nAfter sorting:\n";
    for (const int &i : v)
        cout << i << ' ';
    
    shuffle(v.begin(), v.end(), _rand);
    cout << "\n\nBefore sorting:\n";
    for (const int &i : v)
        cout << i << ' ';
    quicksort(v.begin(), v.end());
    cout << "\n\nAfter sorting:\n";
    for (const int &i : v)
        cout << i << ' ';
    cout << '\n';
    return 0;
}