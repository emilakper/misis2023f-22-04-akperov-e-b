#include <iostream>

int main() {
    int a1, b1, c1, a2, b2, c2;
    std::cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;

    int result = 1;

    if ((a1 == 0 && b1 == 0) && (a2 == 0 && b2 == 0) && c1 != c2) {
        result = 0;
    }
    else if ((a1 == 0 && b1 == 0 && c1 == 0) || (a2 == 0 && b2 == 0 && c2 == 0)) {
        result = -1;
    }
    else if ((a1 == 0 && b1 == 0 && c1 != 0) || (a2 == 0 && b2 == 0 && c2 != 0) && (c1 == c2)) {
        result = 0;
    }
    else if (a1 * b2 == b1 * a2 && b2 * c1 == c2 * b1 && c1 * a2 == c2 * a1) {
        result = -1;
    }
    else if (((a1 * b2) - (a2 * b1)) == 0) {
        result = 0;
    }

    std::cout << result << std::endl;
}