#include <iostream>
#include <vector>

template <typename T, typename F>
T find_if(const std::vector<T>& vec, F pred) {
    for (int i = 0; i < vec.size(); ++i) {
        if (pred(vec[i])) return vec[i];

    }
    return 0;    
}

int main() {
    std::vector<int> v1 = {0, 88, 5, 2, 7, 10};
    std::vector<char> v2 = {'a', 'o', 'a', 'h', 'p' };

    auto even = [](int a) {
        if (a % 2 == 1) return true;
        return false;
    };

    auto uppercase = [](char a) {
        if (a > 'A' && a < 'Z') return true;
        return false;
    };

    std::cout << find_if(v1, even) << std::endl;
    std::cout << find_if(v2, uppercase) << std::endl;


    return 0;
}