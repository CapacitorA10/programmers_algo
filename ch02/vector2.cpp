#include<iostream>
#include<vector>

int main() 
{
    std::vector<int> vec1 {1,2,3,4};
    std::cout << vec1.capacity() << ":" << vec1.size() << std::endl;
    for (int i = 0; i < vec1.size(); ++i) {
        std::cout << vec1[i] << " ";
    }
    std::cout << std::endl;

    vec1.push_back(5);
    std::cout << vec1.capacity() << ":" << vec1.size() << std::endl;
    for (int i = 0; i < vec1.size(); ++i) {
        std::cout << vec1[i] << " ";
    } std::cout << std::endl;

    vec1.push_back(6);
    std::cout << vec1.capacity() << ":" << vec1.size() << std::endl;
    for (int i = 0; i < vec1.size(); ++i) {
        std::cout << vec1[i] << " ";
    } std::cout << std::endl;

    vec1.insert(vec1.begin(), 0);
    std::cout << vec1.capacity() << ":" << vec1.size() << std::endl;
    for (int i = 0; i < vec1.size(); ++i) {
        std::cout << vec1[i] << " ";
    } std::cout << std::endl;

    vec1.erase(vec1.begin() + 1, vec1.begin() + 3);
    std::cout << vec1.capacity() << ":" << vec1.size() << std::endl;
    for(int i = 0; i < vec1.size(); ++i) {
        std::cout << vec1[i] << " ";
    }
    
}
