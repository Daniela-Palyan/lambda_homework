#include <iostream>
#include <vector>

template <typename T, typename F>
bool any_of(const std::vector<T>& vec, F pred) {
    for (int i = 0; i < vec.size(); ++i) {
        if (pred(vec[i])) return true;
    }

        return false;
}

int main() {
    std::vector<std::pair<int, int>> v1 = {{1, 2}, {30, 3}, {-4, -4}};
    std::vector<std::string> v2 = {"hallo", "world", "goodbye"};

    auto same_pair = [](const std::pair<int, int>& p) {
        if (p.first == p.second) return true;
        return false;
    };

    auto begin_uppercase = [](const std::string& str) {
        if (str[0] < 'Z' && str[0] > 'A') return true;
        return false;
    };

    std::cout << std::boolalpha;
    std::cout << any_of(v1, same_pair) << std::endl;
    std::cout << any_of(v2, begin_uppercase) << std::endl;

    return 0;
}