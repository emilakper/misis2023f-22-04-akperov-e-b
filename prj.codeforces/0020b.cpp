#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    long long A, B, C;
    std::cin >> A >> B >> C;

    if (A == 0) {
        if (B == 0) {
            if (C == 0) {
                std::cout << -1 << std::endl;
            }
            else {
                std::cout << 0 << std::endl;
            }
        }
        else {
            std::cout << 1 << std::endl;
            double x = -static_cast<double>(C) / B;
            std::cout << std::fixed << std::setprecision(5) << x << std::endl;
        }
    }
    else {
        long long D = B * B - 4 * A * C;
        if (D > 0) {
            std::cout << 2 << std::endl;
            double x1 = (-B + std::sqrt(D)) / (2 * A);
            double x2 = (-B - std::sqrt(D)) / (2 * A);
            if (x1 < x2) {
                std::cout << std::fixed << std::setprecision(5) << x1 << std::endl;
                std::cout << std::fixed << std::setprecision(5) << x2 << std::endl;
            }
            else {
                std::cout << std::fixed << std::setprecision(5) << x2 << std::endl;
                std::cout << std::fixed << std::setprecision(5) << x1 << std::endl;
            }
        }
        else if (D == 0) {
            std::cout << 1 << std::endl;
            double x = -static_cast<double>(B) / (2 * A);
            std::cout << std::fixed << std::setprecision(5) << x << std::endl;
        }
        else {
            std::cout << 0 << std::endl;
        }
    }
}