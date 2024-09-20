#include <iostream>
#include <vector>

bool isPrime(int num) {
    if (num < 2)
        return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}

void findSphenicNumbers(int n, int p, int count, std::vector<int>& factors) {
    if (count == 3) {
        std::cout << factors[0] * factors[1] * factors[2] << std::endl;
        return;
    }

    for (int q = p + 1; q <= n; ++q) {
        if (isPrime(q)) {
            factors[count] = q;
            findSphenicNumbers(n, q, count + 1, factors);
        }
    }
}

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    std::vector<int> factors(3);
    findSphenicNumbers(n, 2, 0, factors);

    return 0;
}