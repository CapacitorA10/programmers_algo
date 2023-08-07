#include <iostream>

template <typename T>
class DynamicArray
{
private:
    unsigned int size_arr;
    T* arr;

public:
    DynamicArray(int n) : size_arr(n) {
        arr = new T[size_arr] {};
    }
    
    ~DynamicArray() {
        delete[] arr;
    }

    unsigned int size() {
        return size_arr;
    }

    T& operator[](const int i) {
        return arr[i];
    }

    const T& operator[](const int i) const {
        return arr[i];
    }
};

    int main()
    {
            DynamicArray<float> scores(5);
            scores[0] = 8.4;
            scores[1] = 9.2;
            scores[2] = 7.6;

            for (int i = 0; i < scores.size(); ++i) {
                std::cout << scores[i] << std::endl;
            }
    }
