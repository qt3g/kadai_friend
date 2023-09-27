/* PAE02_ex（2023）
-----------------------------------------------------------------
「プログラミング応用演習」 乱数を用いたシミュレーション(1)
演習プログラム
-----------------------------------------------------------------
??を含むコメントを，適切なプログラムコードで置き換える
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EX02_7  /* _の後ろの数字を変えれば対応した関数を使える */
/* 現状では，関数ex02_06を使う．*/
/* #define EX02_7に変更すれば，関数ex02_07を使う．*/

/*-----------------------------------------------------------------*/
int dice()
{
    /* サイコロの目(1～6)をランダムに生成する */
    return /*??*/;
}

#ifdef EX02_6
void ex02_06()  /* 演習2(6) */
{
    int i;

    printf("\n<<ex02_06>>\n");

    srand((unsigned)time(NULL));

    /*?? ランダムなサイコロの目を100回表示する */



    printf("\n");
}
#endif

/*-----------------------------------------------------------------*/
#ifdef EX02_7
void ex02_07(int trial)     /* 演習2(7) */
{
    int count[7];   /* サイコロの目がiの場合の回数をcount[i]に格納する */
    int i;

    printf("\n<<ex02_07>>\n");
    printf("trial: %d\n", trial);

    srand((unsigned)time(NULL));

    /*?? count[i] (i=1～6)を初期化する */




    for (i = 1; i <= trial; i += 1) {
        count[i] = rand() % trial + 1;     /* サイコロの目(dice())に対するcount[]の更新 */
    }

    for (i = 1; i <= 6; i += 1) {
        printf("count[%d] = %d\n", i, count[i]);
    }
}
#endif

/*-----------------------------------------------------------------*/
#ifdef EX02_8
void ex02_08(int trial)     /* 演習2(8) */
{   /* trial: 試行回数 */
    double tval[13];    /* 理論的確率 */
    int count[13];      /* 2つのサイコロの目の和がiの場合の回数をcount[i]に格納する */
    int i;

    printf("\n<<ex02_08>>\n");
    printf("trial: %d\n\n", trial);

    /*?? 理論的確率(tval[i])を初期化する */
    /* tval[2]は，二つのサイコロの目が2になる確率，
       tval[3]は，二つのサイコロの目が3になる確率，
       tval[4]は，二つのサイコロの目が4になる確率，
       ．．．．．，である．講義資料16,17ページが参考になる．*/

    srand((unsigned)time(NULL));

    for (i = 2; i <= 12; i += 1) {
        count[i] = 0;  /* サイコロの目(i)が出た回数の初期化 */
    }

    for (i = 1; i <= trial; i += 1) {
        ;     /* count[i]の更新 */
    }

    for (i = 2; i <= 12; i += 1) {
        double r = (double)count[i] / (double)trial;
        printf("ratio[%d] = %8f (%f)\n", i, r, r / tval[i]);
        /* r/tval[i]はシミュレーションによる値と理論値との比 */
    }

    printf("\n");
}
#endif

/*-----------------------------------------------------------------*/
#ifdef EX02_9
double rnums(double a, double b)
{
    /* 区間[a, b]の一様乱数を生成する． */
    return /*??*/;
}

void ex02_09(double a, double b, int trial)     /* 演習2(9) */
{
    double min, max;
    int i;

    printf("\n<<ex02_09>>\n");
    printf("trial: %d\n", trial);

    min = /*?? 最小値の初期設定 */;
    max = /*?? 最大値の初期設定 */;

    srand((unsigned)time(NULL));

    for (i = 1; i <= trial; i += 1) {
        double r = rnums(a, b);
        if (/*??*/)     min = r;      /* 最小値の更新 */
        if (/*??*/)     max = r;      /* 最大値の更新 */
    }

    printf("[%f, %f]\nmin = %f, max = %f", a, b, min, max);
    printf("\n");
}
#endif

/*-----------------------------------------------------------------*/
int main()
{
#ifdef EX02_6
    /* 演習2(6) */
    ex02_06();
#endif
#ifdef EX02_7
    /* 演習2(7) */
    ex02_07(60);
    ex02_07(600);
    ex02_07(6000);
    ex02_07(60000);
#endif
#ifdef EX02_8
    /* 演習2(8) */
    ex02_08(100);
    ex02_08(1000);
    ex02_08(10000);
#endif
#ifdef EX02_9
    /* 演習2(9) */
    ex02_09(0, 100, 100);
    ex02_09(0, 100, 1000);
    ex02_09(0, 100, 10000);
#endif

    return 0;
}


/* 実行結果を貼り付ける

演習2(6)


演習2(7)


演習2(8)


演習2(9)


*/