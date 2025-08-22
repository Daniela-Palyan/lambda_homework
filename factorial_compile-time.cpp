#include <iostream>

int main() {
    auto fact = [](int num) constexpr {
        int ret = 1;
        while (num) {
            ret *= num;
            --num;
        }
        return ret;
    };

    std::cout << "factorial of 3: " << fact(3) << std::endl;
    std::cout << "factorial of 5: " << fact(5) << std::endl;

    return 0;
}