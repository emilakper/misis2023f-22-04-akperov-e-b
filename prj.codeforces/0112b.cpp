#include <iostream>

int main() {
    int n, x, y;
    std::cin >> n >> x >> y;

    n /= 2;

    if ((x == n || x == n + 1) && (y == n || y == n + 1)) {
        std::cout << "NO\n";
    }
    else {
        std::cout << "YES\n";
    }
}