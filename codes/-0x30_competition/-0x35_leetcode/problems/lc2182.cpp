#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> nums(26, 0);
        for (char ch : s)nums[ch - 'a']++;
        string ans;
        for (int i = 25;i >= 0;--i) {
            int cnt = 0;
            while (nums[i]) {
                cnt++, nums[i]--;
                if (cnt == repeatLimit + 1) {
                    int j;
                    for (j = i - 1;j >= 0;--j)if (nums[j]) {
                        ans += (char)(j + 'a');
                        nums[j]--;
                        break;
                    }
                    cnt = 1;
                    if (j == -1)return ans;
                }
                ans += (char)(i + 'a');
            }
        }
        return ans;
    }
};