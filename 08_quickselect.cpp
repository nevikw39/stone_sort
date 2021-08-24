#include <iostream>
#include <vector>
#include <random> // for mt19937

using namespace std;

int quickselect(vector<int>::iterator begin, vector<int>::iterator end, int k)
{
    if (end - begin <= 1)
        return *begin;
    auto itr = begin, pivot = end - 1;
    for (auto jtr = begin; jtr != pivot; jtr++)
        if (*jtr < *pivot)
            swap(*itr++, *jtr);
    swap(*itr, *pivot);
    if (k < itr - begin)
        return quickselect(begin, itr, k);
    else if (k == itr - begin)
        return *itr;
    else                                                         // the size of less aprt is (itr - begin) ans pivot alse counts
        return quickselect(itr + 1, end, k - (itr - begin) - 1); // so the k-th in origin is (k - (itr - begin) - 1) in greater part
}

int main()
{
    vector<int> v = {8, 27, 2021, 110, 20};
    cout << "v:";
    for (const int &i : v)
        cout << ' ' << i;
    cout << '\n'
         << quickselect(v.begin(), v.end(), 2) << '\n';
    
    int n, k;
    cin >> n >> k;
    v.resize(n);
    mt19937 _rand((random_device())()); // create an object with random seed that generates random numbers using Mersenne Twister Algo
    for (int &i : v)
        i = _rand();
    cout << "v:";
    for (const int &i : v)
        cout << ' ' << i;
    cout << '\n'
         << quickselect(v.begin(), v.end(), k) << '\n';
    return 0;
}