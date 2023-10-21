#define ID      "19A5999"  // 学生番号
#define NAME    "工大次郎" // 氏名

#include "stdio.h"

#define INF 10000       // 辺の重みの最大値より大きい値
#define MAX_SIZE   7    // ノードの数

int weight[MAX_SIZE][MAX_SIZE];
int sptree[MAX_SIZE][MAX_SIZE];

int read_matrix(const char *fn )
{
    FILE    *fp;
    int     i, j, c;

    fp = fopen(fn, "r");
    if (fp == NULL)     return -1;

    // ファイルから読み取った値で，weightを初期化する
    for(i = 0; i < MAX_SIZE; i += 1) {
        for(j = 0; j < MAX_SIZE; j += 1) {
            fscanf(fp, "%d", &c); // 値を読み取り
            weight[i][j] = c;    // weight配列に格納
        }
    }

    fclose(fp);

    return 0;
}

int main()
{
    int used[MAX_SIZE] = { 1, 0, 0, 0, 0, 0, 0 };
    int total_cost;

    int k,  n;
    int p1, p2;
    int m1, m2;
    int i, j;

    for(i = 0; i < MAX_SIZE; i += 1) {
        for(j = 0; j < MAX_SIZE; j += 1) {
            sptree[i][j] = 0; // 最小全域木の隣接行列を0で初期化
        }
    }

    read_matrix("am.txt");

    total_cost = 0;
    used[0] = 1;

    for(n = 1; n < MAX_SIZE; n += 1) {
        m1 = INF;
        for(i = 0; i < (MAX_SIZE-1); i += 1) {
            if(used[i]) {
                m2 = INF;
                for(j = 0; j < MAX_SIZE; j += 1) {
                    int w = weight[i][j];

                    if (!used[j] && w > 0) {
                        if(m2 > w) {
                            m2 = w;
                            k = j;
                        }
                    }
                }

                if((m2 < INF) && m1 > m2) {
                    m1 = m2;
                    p1 = i;
                    p2 = k;
                }
            }
        }

        printf("%d-%d (%d)\n", p1, p2, m1);
        used[p2] = 1;

        sptree[p1][p2] = m1;
        sptree[p2][p1] = m1;

        total_cost += m1;
    }

    printf("total cost = %d\n", total_cost);

    for(i = 0; i < MAX_SIZE; i += 1) {
        for(j = 0; j < MAX_SIZE; j += 1) {
            printf("%d ", sptree[i][j]);
        }

        printf("\n");
    }

    printf("\nPAE05: %s %s\n", ID, NAME);

    return 0;
}
