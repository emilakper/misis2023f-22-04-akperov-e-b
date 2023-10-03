#include <iostream>

int main() {
    int n = 0;
    int k = 0;
    std::cin >> n >> k;

    int evenCities = 0;
    int oddCities = 0;
    int population = 0;

    for (int i = 0; i < n; i++) {
        std::cin >> population;
        if (population % 2 == 0) {
            evenCities++;
        }
        else {
            oddCities++;
        }
    }

    if (k == n) {
        if (oddCities % 2 == 0) {
            std::cout << "Daenerys";
        }
        else {
            std::cout << "Stannis";
        }
    }
    else {
        if ((n - k) % 2 != 0) {
            if (k % 2 == 0) {
                if ((n - k) / 2 >= oddCities || (n - k) / 2 >= evenCities) {
                    std::cout << "Daenerys";
                }
                else {
                    std::cout << "Stannis";
                }
            }
            else {
                if ((n - k) / 2 >= oddCities) {
                    std::cout << "Daenerys";
                }
                else {
                    std::cout << "Stannis";
                }
            }
        }
        else {
            if (k % 2 == 0) {
                std::cout << "Daenerys";
            }
            else {
                if ((n - k) / 2 >= evenCities) {
                    std::cout << "Stannis";
                }
                else {
                    std::cout << "Daenerys";
                }
            }
        }
    }
}