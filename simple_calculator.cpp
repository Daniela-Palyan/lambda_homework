#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string exp;

    std::cin >> exp;

    std::vector<int> nums;
    std::vector<char> op;

    for (int i = 0; i < exp.size(); ) {
        if (exp[i] >= '0' && exp[i] <= '9') {
            int num = 0;
            while (i < exp.size() && exp[i] >= '0' && exp[i] <= '9') {
                num = num * 10 + (exp[i] - '0');
                ++i;
            }
            nums.push_back(num);
        }

        else {
            op.push_back(exp[i]);
            ++i;
        }
    }

    auto mul = [](int num1, int num2) {return num1 * num2;};
    auto div = [](int num1, int num2) {return num1 / num2;};
    auto add = [](int num1, int num2) {return num1 + num2;};
    auto sub = [](int num1, int num2) {return num1 - num2;};

    for (int i = 0; i < op.size(); ) {
        if (op[i] == '*') {
            nums[i] = mul(nums[i], nums[i + 1]);
            nums.erase(nums.begin() + (i + 1));
            op.erase(op.begin() + i);
        }
        else if (op[i] == '/') {
            nums[i] = div(nums[i], nums[i + 1]);
            nums.erase(nums.begin() + (i + 1));
            op.erase(op.begin() + i);
        }
        else {
            ++i;
        }
    }

    for (int i = 0; i < op.size(); ) {
        if (op[i] == '+') {
            nums[i] = add(nums[i], nums[i + 1]);
            nums.erase(nums.begin() + (i + 1));
            op.erase(op.begin() + i);
        }
        else {
            nums[i] = sub(nums[i], nums[i + 1]);
            nums.erase(nums.begin() + (i + 1));
            op.erase(op.begin() + i);
        }
    }

    std::cout << "= " << nums[0] << std::endl;

    return 0;

}