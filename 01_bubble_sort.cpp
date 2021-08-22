#include <iostream>
#include <vector>
#include <random> // for mt19937

using namespace std;

void bubble_sort(vector<int> &v)
{
    for (int i = 0, n = v.size(); i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
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
    bubble_sort(v);
    cout << "\n\nAfter sorting:\n";
    for (const int &i : v)
        cout << i << ' ';
    cout << '\n';
    return 0;
}