#include <iostream>
#include <string>
#include <map>

int main()
{
    int n;
    std::string s, t;
    std::map<std::string, int> mp;
    std::cin >> s;
    n = s.length();

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i + j <= n)
            {
                t = s.substr(i, j);
                mp[t]++;
            }
        }
    }

    int ans = 0;
    auto itr = mp.begin();
    while (itr != mp.end())
    {
        t = itr->first;
        if (itr->second >= 2)
            ans = std::max(ans, static_cast<int>(t.length()));

        itr++;
    }

    std::cout << ans << std::endl;
}