#include <iostream>
#include <vector>

int main() {
    int t;
    int n;
    int p;
    std::cin >> t;
    for (int tc = 0; tc < t; tc++) {
        std::cin >> n;
        std::vector<int> p(n);
        for (int i = 0; i < n; i++) {
            std::cin >> p[i];
        }
        int a = 0;
        int b = 0;
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (p[i] != i + 1 && p[i] != n - i) {
                c += 1;
            }
            else if (p[i] != i + 1) {
                a += 1;
            }
            else if (p[i] != n - i) {
                b += 1;
            }
        }
        if (a + c <= b) {
            std::cout << "First" << std::endl;
        }
        else if (b + c < a) {
            std::cout << "Second" << std::endl;
        }
        else {
            std::cout << "Tie" << std::endl;
        }
    }
}
