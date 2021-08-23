#include <iostream>
#include <vector>
#include <random> // for mt19937

using namespace std;

void selection_sort(vector<int> &v)
{
    for (int i = 0, n = v.size(); i < n - 1; i++)
    {
        int index_of_min = i;
        for (int j = i + 1; j < n; j++)
            if (v[index_of_min] > v[j])
                index_of_min = j;
        swap(v[i], v[index_of_min]);
    }
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
    selection_sort(v);
    cout << "\n\nAfter sorting:\n";
    for (const int &i : v)
        cout << i << ' ';
    cout << '\n';
    return 0;
}