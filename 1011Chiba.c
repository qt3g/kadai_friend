/* PAE04_ex
-----------------------------------------------------------------
「プログラミング応用演習」 連結リストとグラフ構造(1)
演習プログラム
-----------------------------------------------------------------
??を含むコメントを適切なプログラムコードで置き換える
*/
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#define EX04_3  /* _の後ろの数字を変えれば対応した関数を使える */
/* 現状では，関数ex04_02を使う．*/
/* #define EX04_3に変更すれば，関数ex04_03を使う．*/

//-----------------------------------------------------------
#define LINE_SIZE 80    // グラフデータファイルの1行の最大文字数
#define MAX_NODE 10     // ノードの数の最大値
#define OK 0
#define NG -1

int AM[MAX_NODE][MAX_NODE];     // 隣接行列


#ifdef EX04_2
//---------------------------------------------------------------
int read_graph_2()
{
    char    in_file_name[80];
    FILE* fp;
    int     num_node;
    char    node_name[MAX_NODE];
    int     cc;

    printf("input file name = ");
    scanf("%s", in_file_name);

    fp = fopen(in_file_name, "r");
    if (fp == NULL) {
        fprintf(stderr, "Cannot open file %s\n", in_file_name);
        return NG;
    }

    fscanf(fp, "%d\n", &num_node);      // ノードの数を読み込んで表示
    printf("number of nodes = %d\n", num_node);

    // ノードの記号を読み込む
    for (int i = 0; i < num_node; i += 1) {
        char c;
        fscanf(fp, "%c ", &c);
        node_name[i] = c;
    }

    printf("node name: ");

    for (int i = 0; i < num_node; i += 1) {
        printf("%c ", node_name[i]);
    }

    printf("\n");

    // 各辺のデータを読み込む
    while (1) {
        char    n1, n2;
        int     w;

        cc = fscanf(fp, "%c %c %d");   // ヒント：下のprintfと同じ書式
        if (cc == EOF) {  // ファイルの終了
            return OK;
        }

        printf("%c %c %d\n", n1, n2, w);
        // →隣接行列と隣接リスト作成するように詳細化
    }

    return OK;
}

//-----------------------------------------------------------
void ex04_02()
{
    int     cc;

    printf("read_graph_2\n");

    cc = read_graph_2();
    if (cc != 0) {
        fprintf(stderr, "read error\n");
        return;
    }
}
#endif        // EX04_2

#ifdef EX04_3
//-----------------------------------------------------------
int v2n(char v, char node_name[], int num_node)
{
    int     i;

    for (i = 0; i < num_node; i += 1) {
        if (node_name[i] == v) {    /* node_nameにvがあればその番号を戻り値とする */
            return i;
        }
    }

    return -1;    // node_nameにvがない場合は，-1を戻り値とする．
}

//------------------------
int read_graph_3()
{
    char    in_file_name[80];
    FILE* fp;
    int     num_node;
    char    node_name[MAX_NODE];
    int     cc;

    printf("input file name = ");
    scanf("%s", in_file_name);

    fp = fopen(in_file_name, "r");
    if (fp == NULL) {
        fprintf(stderr, "Cannot open file %s\n", in_file_name);
        return NG;
    }

    fscanf(fp, "%d\n", &num_node);  // ノードの数を読む
    printf("number of nodes = %d\n", num_node);

    // ノードの記号を読み込む
    for (int i = 0; i < num_node; i += 1) {
        char v;
        fscanf(fp, "%c ", &v);
        node_name[i] = v;
    }

    printf("node name\n");

    for (int i = 0; i < num_node; i += 1) {
        printf("%c ", node_name[i]);
    }

    printf("\n");

    // 隣接行列を初期化する
    for (int i = 0; i < num_node; i += 1) {
        for (int j = 0; j < num_node; j += 1) {
            AM[i][j] = 0;
        }
    }

    // 各辺のデータを読み込む
    while (1) {
        char    v1, v2;
        int     w;
        int     n1, n2;

        cc = fscanf(fp, "%c %c %d\n", &v1, &v2, &w);
        if (cc == EOF) {
            break;
        }

        // ノードの記号（文字）を番号（数値）に変換する
        n1 = v2n(v1, node_name, num_node);
        n2 = v2n(v2, node_name, num_node);
        // printf("%d %d %d\n", n1, n2, w);/*!!*/

        // 隣接行列に値を設定する．
        AM[n1][n1] = w;
        AM[n2][n2] = w;
    }

    // 隣接行列を表示する
    for (int i = 0; i < num_node; i += 1) {
        for (int j = 0; j < num_node; j += 1) {
            printf("%d ", AM[i][j]);
        }

        printf("\n");
    }

    return OK;
}

//-----------------------------------------------------------
void ex04_03()
{
    int     cc;

    printf("read_graph_3\n");

    cc = read_graph_3();
    if (cc != 0) {
        fprintf(stderr, "read error\n");
        return;
    }
}
#endif        // EX04_3

//-----------------------------------------------------------
int main(void)
{
#ifdef EX04_2
    ex04_02();
#endif
#ifdef EX04_3
    ex04_03();
#endif

    return 0;
}

/*実行結果を貼り付ける

演習4(2)
read_graph_2
input file name = data.txt
number of nodes = 6
node name: a b c d e f

演習4(3)
read_graph_3
input file name = data.txt
number of nodes = 6
node name
a b c d e f
4 0 0 0 0 0
0 3 0 0 0 0
0 0 1 0 0 0
0 0 0 1 0 0
0 0 0 0 2 0
0 0 0 0 0 2

*/
