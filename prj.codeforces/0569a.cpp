#include <iostream>

int main() {
    int T, S, q;
    std::cin >> T >> S >> q;

    int count = 0;
    while (S < T) {
        S *= q;
        count++;
    }

    std::cout << count << std::endl;
}
