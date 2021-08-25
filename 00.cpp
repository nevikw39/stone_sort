#include <iostream>
#include <vector>

using namespace std;

void our_swap(int &lhs, int &rhs)
{
    int tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}

int main()
{
    vector<int> v = {8, 27, 2021, 110, 20};
    cout << "Before SWAP: v[0] = " << v[0] << ", v[1] = " << v[1];
    our_swap(v[0], v[1]);
    cout << "\nAfter SWAP: v[0] = " << v[0] << ", v[1] = " << v[1]
         << "\nIn fact, C++ has built-in function `std::swap()` can also perform this process.\n";
    swap(v[0], v[1]);
    cout << "After SWAP twice: v[0] = " << v[0] << ", v[1] = " << v[1] << '\n';

    cout << "\nRANGED-BSAED LOOP is a C++11 featur enable us to traverse through containers such as array, vector like this:\n";
    for (const int &i : v)
        cout << '\t' << i << '\n';
    cout << "If you'd like to modified the value, you should use `for (int &i : v)`.\n";
    for (int &i : v)
        i += 10000;
    cout << "Otherwise use `for (const int &i : v)` instead:\n";
    for (const int &i : v)
        cout << '\t' << i << '\n';
    
    cout << "\nITERATORS could be considered to be the place container to store values.\n"
         << "A vector w/ 3 elems would have 3+1 itrs v.begin(), v.begin()+1, v.begin()+2 & v.begin()+3 i.e. v.end() point to v[0], v[1], v[2] & NULL.\n"
         << "For an ITERATOR `itr`, we can use `*itr` to get the value it point to.\n"
         << "Moreover, ITERATOR itself can do arthmetic operation, which means forward or backward its postion.\n";
    cout << "The value of `v.begin()+2` is " << *(v.begin() + 2) << ".\n\n"
         << "We can use `auto` to let compiler deduce the type of variables.\n\n";
    vector<int>::iterator itr = v.begin() + 1;
    auto jtr = v.begin() + 4;
    cout << "In programming, a HALF-OPEN INTERVAL [a, b) oft represents a range or sequence.\n"
         << "There are many adventages, one of which is that the length is b-a.\n"
         << "Furthermore, [a, b) can be divided into [a, m) and [m, b).\n";
    vector<int> a(v.begin(), itr), b(itr, jtr), c(jtr, v.end());
    cout << "a:";
    for (const int &i : a)
        cout << ' ' << i;
    cout << "\nb:";
    for (const int &i : b)
        cout << ' ' << i;
    cout << "\nc:";
    for (const int &i : c)
        cout << ' ' << i;
    cout << '\n';
    return 0;
}