/* PAE04_smp (2022)
-----------------------------------------------------------------
「プログラミング応用演習」 連結リストとグラフ構造(1)
サンプルプログラム
-----------------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//-----------------------------------------------------------
#define LINE_SIZE 80    // グラフデータファイルの1行の最大文字数
#define OK 0
#define NG -1


//---------------------------------------------------------------
// 1行ずつ読んでファイルの内容を確認する
int read_graph_1()
{
    char    in_file_name[80];
    char    line[LINE_SIZE];
    FILE    *fp;

    printf("input file name = ");
    scanf("%s", in_file_name);

    fp = fopen(in_file_name, "r");
    if (fp == NULL) {
        fprintf(stderr, "Cannot open file %s\n", in_file_name);
        return NG;
    }

    while (fgets(line, LINE_SIZE, fp) != NULL) {
        puts(line);     // 読み込んだ行をそのまま表示
    }
    // →グラフ構造のデータを読めるように詳細化

    return OK;
}

//-----------------------------------------------------------
void ex04_01()        // 演習4(1)
{
    int     cc;

    printf("read_graph_1\n");

    cc = read_graph_1();
    if (cc != 0) {
        fprintf(stderr, "read error\n");
        return;
    }
}

//-----------------------------------------------------------
int main(void)
{
    ex04_01();

    return 0;
}

/*実行結果を貼り付ける
演習4(1)


*/
