/* PAE03_rp (2023)
-----------------------------------------------------------------
「プログラミング応用演習」 乱数を用いたシミュレーション(2)
課題レポートプログラム
-----------------------------------------------------------------
?? を含むコメントの部分を適切なプログラムコードに置き換えてプログラムを完成させること．
プログラムの他の部分は変更しないこと．

マクロ変数IDに各自の学生番号，NAMEに氏名を文字列として定義すること．
例)
#define ID "18A5999"
#define NAME "工大次郎"
*/
#define ID      "99Z9999"
#define NAME    "工大三郎"

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _USE_MATH_DEFINES
#include <math.h>

/* 試行回数 */
#define MAX1 10000000

/* 収束判定定数 */
#define E 0.0000000001

/*---------------------------------------------------------------
シンプソン法により定積分の値を求める
*/
double dabs(double d1, double d2)
{
    // d1とd2の差の絶対値をreturnする
    if (d1 > d2) {
        return d1 - d2;
    }
    else {
        return d2 - d1;
    }
}

/* simpson法の概要は講義資料22ページ以降を参考に... */
double simpson(double(*f)(double), double a, double b, double e)
{
    double d = e + 1.0;     /* 積分値比較用 */
    double s1 = 0.0;        /* 積分値格納用（1つ前） */
    double s2 = 1.0;        /* 積分値格納用 */
    int n = 0;              /* 等分数（実際の等分数は2n） */

    do {
        int i;
        double h;       /* 区間幅 */
        double yo;      /* 奇数番目の分点における関数値 */
        double ye;      /* 偶数番目の分点における関数値 */

        n++;
        s1 = s2;
        h = (b - a) / (2.0 * n);
        ye = 0.0;
        yo = 0.0;

        for (i = 1; i <= 2 * n - 1; i = i + 2) {
            yo = yo + f(a + i * h);
        }

        for (i = 2; i <= 2 * n - 2; i = i + 2) {
            ye = ye + f(a + i * h);
        }

        s2 = (h / 3.0) * (f(a) + f(b) + 4.0 * yo + 2.0 * ye);
        if (n > 1) {
            d = dabs(s1, s2); // s1とs2の差の絶対値
            /* 以下は提出時にはコメントにしておくこと．*/
            /*!!*/ // printf("n=%3d, S1=%12.10f, S2=%12.10f, d=%12.10f\n",n, s1, s2, d);
        }
    } while (d >= e);

    return s2;
}

/*---------------------------------------------------------------
0～1の一様分布乱数
*/
double urnd(void)
{
    return (double)rand() / (double)RAND_MAX;
}

/*---------------------------------------------------------------
単純モンテカルロ法により定積分の値を求める
*/
double def_integral1(double(*f)(double), double a, double b, double T)
{
    double x, y;
    double ya, yb;
    double ymax;
    double S = 0;

    ya = f(a);
    yb = f(b);

    if (ya < yb) ymax = yb;
    else ymax = ya;

    /* a <= x <= b */
    /* 0 <= y <= ymax */

    for (double i = 1; i <= T; i += 1) {
        x = a + urnd() * (b - a);
        y = urnd() * ymax;
        if ((x*x+y*y)<=1) S += 1;
    }

    return 4*S/T;
}

/*---------------------------------------------------------------
定積分の値を求める a<=x<=b を乱数として，f(x)の平均値を積分値とする．
*/
double def_integral2(double(*f)(double), double a, double b, double T)
{
    double x;
    double sum = 0;

    for (double i = 1; i <= T; i += 1) {
        /*?? xに区間[a, b]の乱数の値を代入 */
        x= a + ((double)rand() / RAND_MAX) * (b - a);
        /*?? sumにf(x)の値を加算 */
        sum += f(x);
    }
    /*!!*/ // printf("%lf\n", sum);  /* 提出時にはコメントにしておくこと． */

    return sum / T;
}

/*---------------------------------------------------------------
*/
double f1(double x)
{
    return exp(-x);
}

double f1i(double x)    /* f1の積分 */
{
    return -exp(-x);
}

double f2(double x)
{
    return x;
}

double f2i(double x)    /* f2の積分 */
{
    return x * x / 2;
}

double ff(double x)
{
    return /*?? 1/(1+xの2乗) */1 / (1 + x * x);
}

double ffi(double x)    /* ffの積分 */
{
    return /*?? ff*/ff(x);
}

/*---------------------------------------------------------------
*/
int main(void)
{
    double a, b;
    long   c1, c2;
    double d;

    srand((unsigned)time(NULL));

    a = 0.0;
    b = 1.0;

    /* 例1 ---------------*/
    printf("integral f1\n");
    printf("tval   = %12.10lf\n", f1i(b) - f1i(a));

    c1 = clock();
    d = def_integral1(f1, a, b, MAX1);
    c2 = clock();
    printf("sval_1 = %12.10lf (%ld)\n", d, c2 - c1);

    c1 = clock();
    d = def_integral2(f1, a, b, MAX1);
    c2 = clock();
    printf("sval_2 = %12.10lf (%ld)\n", d, c2 - c1);

    c1 = clock();
    d = simpson(f1, a, b, E);
    c2 = clock();
    printf("sval_s = %12.10lf (%ld)\n", d, c2 - c1);

    /* 例2 ---------------*/
    printf("\nintegral f2\n");
    printf("tval   = %12.10lf\n", f2i(b) - f2i(a));

    c1 = clock();
    d = def_integral1(f2, a, b, MAX1);
    c2 = clock();
    printf("sval_1 = %12.10lf (%ld)\n", d, c2 - c1);

    c1 = clock();
    d = def_integral2(f2, a, b, MAX1);
    c2 = clock();
    printf("sval_2 = %12.10lf (%ld)\n", d, c2 - c1);

    c1 = clock();
    d = simpson(f2, a, b, E);
    c2 = clock();
    printf("sval_s = %12.10lf (%ld)\n", d, c2 - c1);

    /* 課題---------------*/
    printf("\nintegral f3\n");
    printf("tval   = %12.10lf\n", ffi(b) - ffi(a));

    /*??  上の二つの例にしたがって，三つの方法でffの積分値を求める．*/
    c1 = clock();
    d = def_integral1(ff, a, b, MAX1);
    c2 = clock();
    printf("sval_1 = %12.10lf (%ld)\n", d, c2 - c1);

    c1 = clock();
    d = def_integral2(ff, a, b, MAX1);
    c2 = clock();
    printf("sval_2 = %12.10lf (%ld)\n", d, c2 - c1);

    c1 = clock();
    d = simpson(ff, a, b, E);
    c2 = clock();
    printf("sval_s = %12.10lf (%ld)\n", d, c2 - c1);




    printf("\nPAE03_rp: %s, %s\n", ID, NAME);

    return 0;
}


/*実行結果を貼り付ける

integral f1
tval   = 0.6321205588
sval_1 = 3.1407700000 (617)
sval_2 = 0.6321010530 (367)
sval_s = 0.6321205594 (0)

integral f2
tval   = 0.5000000000
sval_1 = 3.1418328000 (543)
sval_2 = 0.5000048277 (280)
sval_s = 0.5000000000 (0)

integral f3
tval   = -0.5000000000
sval_1 = 3.1408904000 (543)
sval_2 = 0.7853668675 (287)
sval_s = 0.7853981633 (0)

PAE03_rp: 99Z9999, 工大三郎

*/

/*---------------------------------------------------------------
シンプソン法とモンテカルロ法の実行時間と精度を比較した考察
*/
