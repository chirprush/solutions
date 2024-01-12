#include <cstdio>
#include <cstring>

int main() {
    constexpr int N = 15;

    int g[N][N] = {0};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            g[i][j] = 1;
        }
    }
    
    g[0][0] = 0;
    
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int min = 1;

            if (g[i - 1][j] == 0) {
                min = 0;
            }

            for (int a = 0; a <= i; a++) {
                for (int b = 0; b <= j; b++) {
                    if (!(a == 0 && b == 0) && j - b + a < N && g[i - a][j - b + a] == 0) {
                        min = 0;
                        break;
                    }
                }

                if (min == 0) {
                    break;
                }
            }

            g[i][j] = 1 - min;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", g[i][j]);
        }

        printf("\n");
    }

    return 0;
}
