#include <iostream>

int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            std::cout << (i * j / n) * 10 + (i * j % n) << " ";
        }
        std::cout << std::endl;
    }
}
