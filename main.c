#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i, j, x;
    double pow_n;
    int a[2]={0};
    int figure=0;
    int tf_figure[2]={0};
    int number=0, num369[2]={0}, result_num369=0;
    int whole_num[8]; // whole_num[0]: number of 3,6,9 in 1~9 ; whole_num[1]:number of 3,6,9 in 1~99; whole_num[5]: number of 3,6,9 in 1~999999
    whole_num[0]=3;

    //scanf("%d%d", &a[0], &a[1]);
    a[0]=1; a[1]=99999999;  // whole_num[1]: shi wei   whole_num[7]: qian wan wei
    for(i=1; i<8; i++)
    {
        pow_n = pow(10, i);
        whole_num[i] = 6*whole_num[i-1] + 3*(int)pow_n + whole_num[i-1];
    }

    for(i=0; i<2; i++)
    {
        x = a[i]; number=0;
        do{
            number++;
            x/= 10;
        }while(x>0);

        while(number>0)
        {
            number--;
            pow_n = pow(10, number);
            figure = a[i]/(int)pow_n%10; printf("%d: number=%d, pow_n = %f, figure = %d\n", i, number, pow_n, figure);

            if(figure>0)
            {
                if(tf_figure[i]==0)
                {
                    if(number>0)
                    {
                        num369[i] = num369[i] + (figure-1)/3*(whole_num[number-1]*2+(int)pow_n) + (figure-1)%3*whole_num[number-1] + whole_num[number-1];
                        //figure = 8, if 100wei  then 0~799, 7/3 -> 369 mode, 7%3 -> 369 mode
                        if(figure%3 == 0)
                            num369[i]++;
                    }
                    else
                        num369[i] = num369[i] + figure/3;
                    printf("1 - num369[%d] = %d\n", i, num369[i]);
                }
                else
                {
                    num369[i] = num369[i] + figure*(int)pow_n;  printf("2 - num369[%d] = %d\n", i, num369[i]);
                }
                if(figure%3==0)
                {
                    tf_figure[i] = 1;
                }

            }

        }printf("*** num369[%d] = %d\n", i, num369[i]);
    }

    if(tf_figure[0]==1)
    {
        result_num369 = num369[1] - num369[0] + 1;
    }
    else
    {
        result_num369 = num369[1] - num369[0];
    }
    printf("%d", result_num369);

    return 0;
}
