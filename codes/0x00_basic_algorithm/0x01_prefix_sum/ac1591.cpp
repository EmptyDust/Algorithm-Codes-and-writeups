#include <vector>
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<bool> a(n, false);
    vector<int> ans;
    int mx, mn;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        if (i == 0)mx = nums[0];
        if (nums[i] >= mx) {
            mx = nums[i];
            a[i] = true;
        }
    }
    mn = nums[n - 1];
    for (int i = n - 1; i >= 0; --i) {
        if (nums[i] <= mn) {
            mn = nums[i];
            if (a[i])ans.push_back(nums[i]);
        }
    }
    cout << ans.size() << endl;
    for (int i=ans.size()-1;i>=0;--i)cout << ans[i] << " ";
    if(ans.size()==0)cout<<" ";
    return 0;
}