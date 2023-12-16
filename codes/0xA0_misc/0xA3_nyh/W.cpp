#include <stdio.h>

int reverse(int num) {
    int ans = 0;
    //for(ans=0;num!=0;num/=10)
    //  ans = ans * 10 + num % 10;
    while (num) {
        ans = ans * 10 + num % 10;
        num /= 10;
    }
    return ans;
}

int main() {
    int n, num;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &num);
        printf("%d ", reverse(num));
    }
    //print n
    return 0;
}