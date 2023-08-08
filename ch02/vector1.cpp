#include<iostream>
#include<vector>

int main()
{
    std::vector<int> v1;
    std::vector<int> v2(10); // 10 elements, each initialized to 0
    std::vector<int> v3(10, 1); // 10 elements, each initialized to 1
    std::vector<int> v4{84, 92, 76, 88, 65}; // 3 elements, initialized to 84, 92, 76
    std::vector<int> v5(v4);
    std::vector<int> v6(v4.begin(), v4.begin()+3);
    
    v1.push_back(84);
    v1.push_back(92);
    v1.push_back(76);

    for (int i = 0; i < v6.size(); ++i) {
        std::cout << v6[i] << std::endl;
    }

    // 2차원 이상 벡터 학습
    std::vector<std::vector<int>> mat1(2, std::vector<int>(3, 0)); // 2x3 matrix, each element initialized to 0
    std::vector<std::vector<int>> mat2{{1,2,3},{4,5,6}}; // 2x3 matrix, each row initialized to 1,2,3 and 4,5,6 respectively

    for (int r = 0; r < mat2.size(); r++) {
        for (int c = 0; c < mat2[r].size(); c++) {
            std::cout << mat2[r][c] << ", ";
        }
        std::cout << std::endl;
    }


    return 0;
}