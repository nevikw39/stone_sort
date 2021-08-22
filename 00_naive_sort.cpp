#include <iostream>
#include <vector>
#include <random> // for mt19937

using namespace std;

void naive_sort(vector<int> &v)
{
    vector<int> tp(v.size()); // temporarily store our result
    for (int i = 0, n = v.size(); i < n; i++)
    {
        int min = INT_MAX;                        // initialize current minimum to infinity
        for (const int &j : v)                    // for all j in v
            if (min > j && (!i || j > tp[i - 1])) // if minimum > j and (i isn't the first or j > prevois minimum)
                min = j;
        tp[i] = min;
    }
    v = tp;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    mt19937 rand((random_device())()); // create an object with random seed that generates random numbers using Mersenne Twister Algo
    for (int &i : v)
        i = rand();
    cout << "Before sorting:\n";
    for (const int &i : v)
        cout << i << ' ';
    naive_sort(v);
    cout << "\n\nAfter sorting:\n";
    for (const int &i : v)
        cout << i << ' ';
    cout << '\n';
    return 0;
}