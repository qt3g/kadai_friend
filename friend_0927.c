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
    return rand() % 6 + 1/*??*/;
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
    for (i = 1; i <= 6; i += 1) {
        count[i] = 0;
    }



    for (i = 1; i <= 6; i += 1) {
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

    /*?? 理論的確率(tval[i])を初期化する
        tval[2]は，二つのサイコロの目が2になる確率，
        tval[3]は，二つのサイコロの目が3になる確率，
/* 理論的確率(tval[i])を初期化する */
    for (i = 2; i <= 12; i += 1) {
        switch (i) {
        case 2: tval[i] = 1 / 36.0; break;
        case 3: tval[i] = 2 / 36.0; break;
        case 4: tval[i] = 3 / 36.0; break;
        case 5: tval[i] = 4 / 36.0; break;
        case 6: tval[i] = 5 / 36.0; break;
        case 7: tval[i] = 6 / 36.0; break;
        case 8: tval[i] = 5 / 36.0; break;
        case 9: tval[i] = 4 / 36.0; break;
        case 10: tval[i] = 3 / 36.0; break;
        case 11: tval[i] = 2 / 36.0; break;
        case 12: tval[i] = 1 / 36.0; break;
        }
    }

    srand((unsigned)time(NULL));

    for (i = 2; i <= 12; i += 1) {
        count[i] = 0;  /* サイコロの目(i)が出た回数の初期化 */
    }

    for (i = 1; i <= trial; i += 1) {
        int result1 = dice();
        int result2 = dice();
        int sum = result1 + result2;
        count[sum]++;     /* 2つのサイコロの目の和に対するcount[]の更新 */
        /* count[i]の更新 */
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
    int n = rand() % 1000000 + 0;
    double f = n / 1000.0;
    return f;
}

void ex02_09(double a, double b, int trial)     /* 演習2(9) */
{
    double min, max;
    int i;

    printf("\n<<ex02_09>>\n");
    printf("trial: %d\n", trial);

    min = b;
    max = a;

    srand((unsigned)time(NULL));

    for (i = 1; i <= trial; i += 1) {
        double r = rnums(a, b);
        if (r < min)     min = r;      /* 最小値の更新 */
        if (r > max)     max = r;      /* 最大値の更新 */
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
    ex02_09(0, 100, 100);
    ex02_09(0, 100, 1000);
    ex02_09(0, 100, 10000);
    /* 演習2(9) */
    
#endif


    return 0;
}


/* 実行結果を貼り付ける

演習2(6)


演習2(7)
<<ex02_07>>
trial: 60
count[1] = 1
count[2] = 39
count[3] = 14
count[4] = 31
count[5] = 36
count[6] = 30

<<ex02_07>>
trial: 600
count[1] = 481
count[2] = 99
count[3] = 554
count[4] = 151
count[5] = 516
count[6] = 450

<<ex02_07>>
trial: 6000
count[1] = 2281
count[2] = 699
count[3] = 4754
count[4] = 3151
count[5] = 1716
count[6] = 3450

<<ex02_07>>
trial: 60000
count[1] = 2281
count[2] = 18699
count[3] = 22754
count[4] = 3151
count[5] = 19716
count[6] = 45450

演習2(8)
<<ex02_08>>
trial: 100

ratio[2] = 0.000000 (0.000000)
ratio[3] = 0.040000 (0.720000)
ratio[4] = 0.060000 (0.720000)
ratio[5] = 0.100000 (0.900000)
ratio[6] = 0.170000 (1.224000)
ratio[7] = 0.210000 (1.260000)
ratio[8] = 0.150000 (1.080000)
ratio[9] = 0.110000 (0.990000)
ratio[10] = 0.090000 (1.080000)
ratio[11] = 0.060000 (1.080000)
ratio[12] = 0.010000 (0.360000)


<<ex02_08>>
trial: 1000

ratio[2] = 0.024000 (0.864000)
ratio[3] = 0.054000 (0.972000)
ratio[4] = 0.072000 (0.864000)
ratio[5] = 0.119000 (1.071000)
ratio[6] = 0.152000 (1.094400)
ratio[7] = 0.180000 (1.080000)
ratio[8] = 0.133000 (0.957600)
ratio[9] = 0.107000 (0.963000)
ratio[10] = 0.066000 (0.792000)
ratio[11] = 0.064000 (1.152000)
ratio[12] = 0.029000 (1.044000)


<<ex02_08>>
trial: 10000

ratio[2] = 0.027900 (1.004400)
ratio[3] = 0.056300 (1.013400)
ratio[4] = 0.082000 (0.984000)
ratio[5] = 0.105600 (0.950400)
ratio[6] = 0.143200 (1.031040)
ratio[7] = 0.171700 (1.030200)
ratio[8] = 0.137500 (0.990000)
ratio[9] = 0.107200 (0.964800)
ratio[10] = 0.084700 (1.016400)
ratio[11] = 0.058000 (1.044000)
ratio[12] = 0.025900 (0.932400)


演習2(9)
<<ex02_09>>
trial: 100
[0.000000, 100.000000]
min = 18.193000, max = 994.429000

<<ex02_09>>
trial: 1000
[0.000000, 100.000000]
min = 0.041000, max = 998.767000

<<ex02_09>>
trial: 10000
[0.000000, 100.000000]
min = 0.041000, max = 999.960000

*/
