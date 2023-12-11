#include <iostream>

int main() {
    long n;
    std::cin >> n;
    long long total = 0, 
    long long minRounds = 0;
    for (long p = 0; p < n; p++) {
        long temp;
        std::cin >> temp;
        total += temp;
        if (temp > minRounds) {
            minRounds = temp;
        }
    }

    long long rounds = total / (n - 1);
    if (total % (n - 1) > 0) {
        rounds++;
    }
    if (rounds < minRounds) {
        rounds = minRounds;
    }
    std::cout << rounds << std::endl;
}
