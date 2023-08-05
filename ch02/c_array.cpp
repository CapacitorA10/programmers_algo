#include <iostream>

int main()
{
    int scores[5]={84,92,76,81,56};
    int sz = sizeof(scores)/sizeof(scores[0]); // sizeof scores=20, sizeof scores[0]=4
    int sz_2 = std::size(scores); // C++17
    int s = 0;

    for (int i = 0; i < sz; ++i) {
        s += scores[i];
    }
    float avg = (float) s / sz;
    std::cout << "Average score is " << avg << std::endl;

    return 0;
}