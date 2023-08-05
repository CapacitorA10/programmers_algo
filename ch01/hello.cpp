#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<string> greetings = {"Hello", "Hola", "Bonjour", "Ciao"};

    for (const auto& greeting : greetings) {
        cout << greeting << ", World!" << endl;
    }
    //cout << std::size(greetings) << endl;
    return 0;
}
