#include <stdio.h>

int main() {
    int n, tmp;
    scanf("%d", &n);
    while (n--) { scanf("%d", &tmp), printf("%d ", tmp); }
    scanf("%d", &n);
    while (n--) { scanf("%d", &tmp), printf("%d ", tmp); }

    return 0;
}