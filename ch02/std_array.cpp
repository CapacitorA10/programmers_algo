#include <array>
#include <iostream>

int main()
{
    std::array<int, 5> scores = {84,92,76,81,56};
    int sz = scores.size();
    int s = 0;

    for (int i = 0; i < sz; ++i) {
        s += scores[i];
    }
    float avg = (float) s / sz;
    std::cout << "(using std:array)Average score is " << avg << std::endl;

    return 0;
}