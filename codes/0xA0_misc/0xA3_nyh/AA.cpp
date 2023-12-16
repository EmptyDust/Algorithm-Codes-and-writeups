#include <stdio.h>

int main() {
    int n, tmp, sumo = 0, sume = 0;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &tmp);
        if (tmp & 1)sumo += tmp;
        else sume += tmp;
    }
    printf("%d %d", sumo, sume);
    return 0;
}