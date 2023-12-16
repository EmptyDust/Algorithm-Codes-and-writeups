#include <stdio.h>
#include <math.h>

double distance(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    int x1, y1, x2, y2;
    int n;
    double sum = 0;
    scanf("%d", &n);
    scanf("%d%d", &x2, &y2);
    n--;
    while (n--) {
        x1 = x2, y1 = y2;
        scanf("%d%d", &x2, &y2);
        sum += distance(x1, y1, x2, y2);
    }
    printf("%.2lf", sum);

    return 0;
}