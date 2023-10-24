#include <iostream>

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

long long range_sum(long long l, long long r) {
    if (l > r) {
        return 0;
    }
    return (l + r) * (r - l + 1) / 2;
}

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        long long n, x, y;
        std::cin >> n >> x >> y;

        long long l = lcm(x, y);
        long long plus = n / x - n / l;
        long long minus = n / y - n / l;

        long long result = range_sum(n - plus + 1, n) - range_sum(1, minus);
        std::cout << result << std::endl;
    }
}