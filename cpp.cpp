#include <iostream>

using namespace std;

template <typename T>
void foo(int x, T t) { t(x); }

template <typename T>
void bar(int x, int y, T t) { t(x, y); }

void func(int x) { cout << x << '\n'; }
void func(int x, int y) { cout << x << ' ' << y << '\n'; }

int main()
{
    foo(87, (void(*)(int))func);
    bar(69, 92, (void(*)(int, int))func);
    return 0;
}
