#include <iostream>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int a, b, n;
        std::cin >> a >> b >> n;

        switch (n % 3) {
        case 0:
            std::cout << a << std::endl;
            break;
        case 1:
            std::cout << b << std::endl;
            break;
        default:
            std::cout << (a ^ b) << std::endl;
        }
    }

}