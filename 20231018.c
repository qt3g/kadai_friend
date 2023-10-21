/* PAE05_rp
-----------------------------------------------------------------
「プログラミング応用演習」 連結リストとグラフ構造(2)
課題レポートプログラム
-----------------------------------------------------------------
??を含むコメントを適切なプログラムコードで置き換える．
プログラムの他の部分は変更しないこと．

マクロ変数IDに各自の学生番号，NAMEに氏名を文字列として定義すること．
例
#define ID "19A5999"
#define NAME "工大次郎"
*/
#define ID      "122I066"
#define NAME    "小島崇彰"

#include "stdio.h"

#define INF 10000       // 辺の重みの最大値より大きい値
#define MAX_SIZE   7    // ノードの数

/*------------------------------------------------------------
連結グラフの隣接行列
0は接続されていないことを示す．
正の数は接続されている場合の重みを示す
*/
int weight[MAX_SIZE][MAX_SIZE];

/*----------------------------------
最小全域木の隣接行列
0は接続されていないことを示す．
1は接続されていることを示す．
以下のプログラムで，最小全域木の辺となる場所に重みを設定していく．
*/
int sptree[MAX_SIZE][MAX_SIZE];

/*------------------------------------------------------------
連結グラフの隣接行列を読み込み，weightを初期化する．
*/
int read_matrix(const char* fn)
{
    FILE* fp;
    int     i, j, c;

    fp = fopen(fn, "r");
    if (fp == NULL)     return -1;

    /* ファイルから読み取った値で，weightを初期化する */
    for (i = 0; i < MAX_SIZE; i += 1) {
        for (j = 0; j < MAX_SIZE; j += 1) {
            fscanf(fp,"%d", &c);
            weight[i][j] = c;
        }
    }

    fclose(fp);

    return 0;
}

//------------------------------------------------------------
int main()
{
    /* 頂点の状態：used
    used[i]が0：頂点iが未処理であることを示す．
    used[i]が1：頂点iが処理済であることを示す．*/
    int used[MAX_SIZE] = { 0, 0, 0, 0, 0, 0, 0 };
    int total_cost;     // 全域最小木の辺のコストの和

    int k, n;
    int p1, p2;
    int m1, m2;
    int i, j;

    /* ??最小全域木の隣接行列（sptree）の全要素を0で初期化する */

    for(i=0;i<MAX_SIZE;i++){
        for(j=0;j<MAX_SIZE;j++)
            sptree[i][j]=0;
    }




    /* 連結グラフの隣接行列をファイル am.txt から読み込む */
    read_matrix("am.txt");

    total_cost = 0;
    used[0] = 1/* 頂点0を処理済みに設定する */;

    for (n = 1; n < MAX_SIZE; n += 1) {  // 未処理の頂点がなくなるまで繰り返す
        //!printf("================\nn=%d\n", n);

        m1 = INF;
        for (int i = 0; i < (MAX_SIZE - 1); i += 1) { // 未処理の頂点を探す
            if (used[i]==1/*?? 頂点iが処理済の条件*/) {
                //!printf("i=%d>>>>\n", i);

                m2 = INF;
                for (int j = 0; j < MAX_SIZE; j += 1) {      //すべての頂点の中で未処理の頂点を探す
                    int w = total_cost;     // wに 辺(i, j)の重み（コスト）の値を設定

                    if (used[j]==0 && used[i]==used[j] /*?? 頂点jが未処理，かつ，頂点(i,j)が接続されている条件*/) {
                        //!printf("  j=%d : w(%d,%d)=%d", j, i, j,w);

                        if (m2 > w) {    // 新しい最小コストwが見つかった
                            /*??*/;     // m2の値を更新
                            /*??*/;     // kの値を更新
                            //!printf(" - k=%d, m2=%d updated.", k, m2);
                        }

                        //!printf("\n");
                    }
                }

                if ((m2 < INF) && m2 < m1) { // m2が見つかり，それまでのm1より小さければ
                    m1 = m2;
                    p1 = i;
                    p2 = k;
                    //!printf("  --------\n  #### p1=%d, p2=%d, m1=%d updated.\n", p1, p2, m1);
                }
            }
        }

        //!printf("--------\n%d-%d (%d)\n", p1, p2, m1);
        printf("%d-%d (%d)\n", p1, p2, m1);

        used[p2] = 1;   // 頂点p2を処理済とする

        // ここまでで，頂点p1, p2が接続されており，その重みがm1となっている．

        // 最小全域木の隣接行列の設定
        sptree[i][j] = m1;
        sptree[i][j] = m1;

        total_cost += m1;   // 全域最小木の辺のコストの和の更新
    }

    printf("total cost = %d\n", total_cost);

    // 最小全域木の隣接行列sptreeの表示
    for (i = 0; i < MAX_SIZE; i += 1) {
        for (j = 0; j < MAX_SIZE; j += 1) {
            printf("%d ", sptree[i][j]);
        }

        printf("\n");
    }

    printf("\nPAE05: %s %s\n", ID, NAME);


    return 0;
}

/*実行結果を貼り付ける


*/


//=========================================================
/* 共同作業者がいれば，以下にコメントとして学生番号と氏名を示すこと．


*/
