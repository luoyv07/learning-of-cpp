#include <iostream>
using namespace std;
#include <iostream>
#include <string>
#include <algorithm>

class HugeInteger {
private:
    std::string number;

public:
    HugeInteger() : number("0") {}

    void input(const std::string& num) {
        number = num;
        std::reverse(number.begin(), number.end());  
    }

    void output() const {
        std::string num = number;
        std::reverse(num.begin(), num.end());
        std::cout << num << std::endl;
    }

    HugeInteger add(const HugeInteger& other) const {
        HugeInteger result;
        int carry = 0;
        int sum = 0;
        int i = 0;

        for (; i < std::max(number.length(), other.number.length()) || carry; ++i) {
            int digit1 = i < number.length() ? number[i] - '0' : 0;
            int digit2 = i < other.number.length() ? other.number[i] - '0' : 0;

            sum = digit1 + digit2 + carry;
            carry = sum / 10;
            result.number += (sum % 10) + '0';
        }

        return result;
    }

    HugeInteger subtract(const HugeInteger& other) const {
        if (this->isLessThan(other)) {
            throw std::invalid_argument("Result would be negative.");
        }

        HugeInteger result;
        int borrow = 0;

        for (size_t i = 0; i < number.length(); ++i) {
            int digit1 = number[i] - '0';
            int digit2 = i < other.number.length() ? other.number[i] - '0' : 0;

            int diff = digit1 - digit2 - borrow;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            }
            else {
                borrow = 0;
            }
            result.number += (diff + '0');
        }

        while (result.number.length() > 1 && result.number.back() == '0') {
            result.number.pop_back();
        }

        return result;
    }

    bool isEqualTo(const HugeInteger& other) const {
        return number == other.number;
    }

    bool isGreaterThan(const HugeInteger& other) const {
        if (number.length() != other.number.length()) {
            return number.length() > other.number.length();
        }
        for (int i = number.length() - 1; i >= 0; --i) {
            if (number[i] != other.number[i]) {
                return number[i] > other.number[i];
            }
        }
        return false;
    }

    bool isLessThan(const HugeInteger& other) const {
        return !isGreaterThan(other) && !isEqualTo(other);
    }

    bool isGreaterThanOrEqualTo(const HugeInteger& other) const {
        return isGreaterThan(other) || isEqualTo(other);
    }

    bool isLessThanOrEqualTo(const HugeInteger& other) const {
        return isLessThan(other) || isEqualTo(other);
    }

    bool isZero() const {
        return number == "0";
    }
};
int main() {
    HugeInteger num1, num2;
    num1.input("9999999999999999999999999999999999999999");
    num2.input("1");

    std::cout << "num1: ";
    num1.output();
    std::cout << "num2: ";
    num2.output();

    HugeInteger sum = num1.add(num2);
    std::cout << "Sum: ";
    sum.output();

    HugeInteger diff;
    try {
        diff = num1.subtract(num2);
        std::cout << "Difference: ";
        diff.output();
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "num1 is equal to num2: " << num1.isEqualTo(num2) << std::endl;
    std::cout << "num1 is greater than num2: " << num1.isGreaterThan(num2) << std::endl;
    std::cout << "num1 is less than num2: " << num1.isLessThan(num2) << std::endl;
    std::cout << "num1 is greater than or equal to num2: " << num1.isGreaterThanOrEqualTo(num2) << std::endl;
    std::cout << "num1 is less than or equal to num2: " << num1.isLessThanOrEqualTo(num2) << std::endl;
    std::cout << "num1 is zero: " << num1.isZero() << std::endl;

    return 0;
}
