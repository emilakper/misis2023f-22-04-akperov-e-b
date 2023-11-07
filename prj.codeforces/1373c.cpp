#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    for (int j = 0; j < n; j++) {
        std::string s;
        std::cin >> s;
        long long cur = 0;
        long long m = 0;
        long long res = s.length();
        for (int i = 0; i < s.length(); i++) {
            cur += (s[i] == '+') ? 1 : -1;
            if (cur < m) {
                m = cur;
                res += i + 1;
            }
        }
        std::cout << res << std::endl;
    }
}