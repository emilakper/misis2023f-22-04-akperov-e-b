#include <iostream>
#include <vector>

int main(){
 int n;
 std::cin >> n;
 std::vector<int>a(n);
 for(int i=0;i<n;i++){
     std::cin >> a[i];
 }
 int ans = 0;
 for (int i=1;i<=30;i++){
     int res = 0;
     for(int j = 0; j < a.size(); j++){
         res += a[j];
         if(a[j]>i)
             res=0;
         res=std::max(res,0);
         ans=std::max(ans,res-i);
     }
 }
 std::cout << ans;
}
