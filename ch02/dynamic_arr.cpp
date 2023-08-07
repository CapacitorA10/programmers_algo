#include <iostream>

class DynamicArray
{
private:
    unsigned int size_arr;
    int* arr;

public:
    DynamicArray(int n) : size_arr(n) {
        arr = new int[size_arr] {};
    }
    
    ~DynamicArray() {
        delete[] arr;
    }

    unsigned int size() {
        return size_arr;
    }

    int& operator[](const int i) {
        return arr[i];
    }

    const int& operator[](const int i) const {
        return arr[i];
    }
};

    int main()
    {
            DynamicArray scores(5);
            scores[0] = 84;
            scores[1] = 92;
            scores[2] = 76;

            for (int i = 0; i < scores.size(); ++i) {
                std::cout << scores[i] << std::endl;
            }
    }
