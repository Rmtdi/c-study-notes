#include <stdio.h>
#include <math.h>
int main()
{
/*
计算原理：
先计算1分角的sin与cos，然后将其赋值给sin1与cos1,
利用公式 sin(a+b)=sin a * cos b + cos a * sin b.
即可得到sin(1'+1')，即sin(2')的值
继续运行下去，计算每个多1分角的正余弦。
*/
    double s0,c0,s,c,t;//s0为一分教正弦值，c0为其余弦值。
    int option;//option用于选择要进行的操作
    int alpha;//alpha为所求角度数
    int n=1;//n用于判断计算到哪个角

    // printf("输入sin1分的近似值(0.0002908882046)：");
    // scanf("%lf",&s0);
    s0=0.0002908882046;
    c0= pow((1 - pow(s0,2)),0.5);

    s=s0;
    c=c0;

    //选择要进行的操作
    printf("选择要进行的操作：\n");
    printf("1.输入角度求三角函数值\n2.遍历0-pi的三角函数值\n");
    scanf("%d",&option);
    if(option==1)
    {
        printf("输入所求角度数：");
        scanf("%d",&alpha);
        alpha*=60;
        for(;n<alpha;)
        {
            n++;
            s=s*c0+c*s0;
            c= pow((1 - pow(s,2)),0.5);
        }
        if(c!=0)
        {
            double tmp=s/c;
            t += tmp;
        }
        else if(c==0)
        {
            t = -1;
        }
        printf("n=%d度%d分,",n/60,n%60);
        printf("sin=%g,cos=%g,tan=%g\n",s,c,t);
    }
    else if(option==2)
    {
        printf("输入遍历结束的角度数：");
        scanf("%d",&alpha);
        alpha*=60;

        printf("n=0度1分,");
        printf("sin=%g,cos=%g\n",s0,c0);
        for(;n<alpha;)
        {
            n++;
            s= s*c0+c*s0;
            c= pow((1 - pow(s,2)),0.5);
            printf("n=%d度%d分,",n/60,n%60);
            printf("sin=%g,cos=%g,\n",s,c);
        }
    }
}