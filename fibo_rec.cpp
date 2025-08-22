#include <iostream>

int main() {
    auto fibo = [](int num, auto p) {
        if (num == 0 || num == 1) return num;
        return p(num - 1, p) + p(num - 2, p);
    };

    std::cout << "6rd fibonachi value is: " << fibo (6, fibo) << std::endl;

    return 0;
}