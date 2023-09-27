/* PAE02_ex�i2023�j
-----------------------------------------------------------------
�u�v���O���~���O���p���K�v ������p�����V�~�����[�V����(1)
���K�v���O����
-----------------------------------------------------------------
??���܂ރR�����g���C�K�؂ȃv���O�����R�[�h�Œu��������
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EX02_7  /* _�̌��̐�����ς���ΑΉ������֐����g���� */
/* ����ł́C�֐�ex02_06���g���D*/
/* #define EX02_7�ɕύX����΁C�֐�ex02_07���g���D*/

/*-----------------------------------------------------------------*/
int dice()
{
    /* �T�C�R���̖�(1�`6)�������_���ɐ������� */
    return /*??*/;
}

#ifdef EX02_6
void ex02_06()  /* ���K2(6) */
{
    int i;

    printf("\n<<ex02_06>>\n");

    srand((unsigned)time(NULL));

    /*?? �����_���ȃT�C�R���̖ڂ�100��\������ */



    printf("\n");
}
#endif

/*-----------------------------------------------------------------*/
#ifdef EX02_7
void ex02_07(int trial)     /* ���K2(7) */
{
    int count[7];   /* �T�C�R���̖ڂ�i�̏ꍇ�̉񐔂�count[i]�Ɋi�[���� */
    int i;

    printf("\n<<ex02_07>>\n");
    printf("trial: %d\n", trial);

    srand((unsigned)time(NULL));

    /*?? count[i] (i=1�`6)������������ */




    for (i = 1; i <= trial; i += 1) {
        count[i] = rand() % trial + 1;     /* �T�C�R���̖�(dice())�ɑ΂���count[]�̍X�V */
    }

    for (i = 1; i <= 6; i += 1) {
        printf("count[%d] = %d\n", i, count[i]);
    }
}
#endif

/*-----------------------------------------------------------------*/
#ifdef EX02_8
void ex02_08(int trial)     /* ���K2(8) */
{   /* trial: ���s�� */
    double tval[13];    /* ���_�I�m�� */
    int count[13];      /* 2�̃T�C�R���̖ڂ̘a��i�̏ꍇ�̉񐔂�count[i]�Ɋi�[���� */
    int i;

    printf("\n<<ex02_08>>\n");
    printf("trial: %d\n\n", trial);

    /*?? ���_�I�m��(tval[i])������������ */
    /* tval[2]�́C��̃T�C�R���̖ڂ�2�ɂȂ�m���C
       tval[3]�́C��̃T�C�R���̖ڂ�3�ɂȂ�m���C
       tval[4]�́C��̃T�C�R���̖ڂ�4�ɂȂ�m���C
       �D�D�D�D�D�C�ł���D�u�`����16,17�y�[�W���Q�l�ɂȂ�D*/

    srand((unsigned)time(NULL));

    for (i = 2; i <= 12; i += 1) {
        count[i] = 0;  /* �T�C�R���̖�(i)���o���񐔂̏����� */
    }

    for (i = 1; i <= trial; i += 1) {
        ;     /* count[i]�̍X�V */
    }

    for (i = 2; i <= 12; i += 1) {
        double r = (double)count[i] / (double)trial;
        printf("ratio[%d] = %8f (%f)\n", i, r, r / tval[i]);
        /* r/tval[i]�̓V�~�����[�V�����ɂ��l�Ɨ��_�l�Ƃ̔� */
    }

    printf("\n");
}
#endif

/*-----------------------------------------------------------------*/
#ifdef EX02_9
double rnums(double a, double b)
{
    /* ���[a, b]�̈�l�����𐶐�����D */
    return /*??*/;
}

void ex02_09(double a, double b, int trial)     /* ���K2(9) */
{
    double min, max;
    int i;

    printf("\n<<ex02_09>>\n");
    printf("trial: %d\n", trial);

    min = /*?? �ŏ��l�̏����ݒ� */;
    max = /*?? �ő�l�̏����ݒ� */;

    srand((unsigned)time(NULL));

    for (i = 1; i <= trial; i += 1) {
        double r = rnums(a, b);
        if (/*??*/)     min = r;      /* �ŏ��l�̍X�V */
        if (/*??*/)     max = r;      /* �ő�l�̍X�V */
    }

    printf("[%f, %f]\nmin = %f, max = %f", a, b, min, max);
    printf("\n");
}
#endif

/*-----------------------------------------------------------------*/
int main()
{
#ifdef EX02_6
    /* ���K2(6) */
    ex02_06();
#endif
#ifdef EX02_7
    /* ���K2(7) */
    ex02_07(60);
    ex02_07(600);
    ex02_07(6000);
    ex02_07(60000);
#endif
#ifdef EX02_8
    /* ���K2(8) */
    ex02_08(100);
    ex02_08(1000);
    ex02_08(10000);
#endif
#ifdef EX02_9
    /* ���K2(9) */
    ex02_09(0, 100, 100);
    ex02_09(0, 100, 1000);
    ex02_09(0, 100, 10000);
#endif

    return 0;
}


/* ���s���ʂ�\��t����

���K2(6)


���K2(7)


���K2(8)


���K2(9)


*/