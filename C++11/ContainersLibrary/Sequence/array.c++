//https://en.cppreference.com/w/cpp/container/array

#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int main()
{
    array<int, 3> ia1{{1, 2, 3}};

    array<int, 3> ia2 = {10, 20, 30};
    array<string, 2> sa3 = {"Shree Ram", "Jai Shree Ram"};

    sort(ia1.begin(), ia1.end());
    reverse_copy(ia2.begin(), ia2.end(), ostream_iterator<int>(cout, " "));

    cout << "\n";

    for (const auto& s: sa3)
        cout << s << ' ';

    //[[maybe_unused]] array fa{3.0, 1.0, 4.0};
}