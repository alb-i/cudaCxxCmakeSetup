#include <iostream>

int cu_main();

int main() {
    int x;

    std::cout << "Hi from CXX land!" << std::endl;

    x = cu_main();

    return x;
}