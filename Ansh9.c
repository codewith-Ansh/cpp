#include <stdio.h>

int main() {
    int H, L;
    scanf("%d %d", &H, &L);
    printf("%.13f\n", (1.0 * L * L - H * H) / (2.0 * H));
    return 0;
}
