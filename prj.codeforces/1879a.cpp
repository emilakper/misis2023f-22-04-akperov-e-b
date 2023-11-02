#include <iostream>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        long poly_strength;
        int poly_endur;
        long weight;
        long strength;
        int endur;
        std::cin >> n;
        for (int i = 0; i < n; i++) {
            std::cin >> strength >> endur;
            if (i == 0) {
                poly_strength = strength;
                poly_endur = endur;
                weight = strength;
            }
            else {
                if (strength >= poly_strength && endur >= poly_endur) {
                    weight = -1;
                }
            }
        }
        std::cout << weight << std::endl;
    }
}