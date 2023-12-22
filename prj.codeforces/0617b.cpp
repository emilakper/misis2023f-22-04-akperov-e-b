#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int prev = -1;
    long long result = 0;
    for (int i = 0; i < n; i++) {
        int v;
        std::cin >> v;
        if (v == 1) {
            if (prev == -1) {
                result = 1;
            }
            else {
                result *= i - prev;
            }
            prev = i;
        }
    }

    std::cout << result << std::endl;
}