#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double foo(double x);

int main()
{
    double a,b,epsilon,c,n;
    int l=0;
    //输入区间
    printf("输入函数零点的大致区间：");
    scanf("%lf",&a);
    scanf("%lf",&b);

    //输入精度
    printf("输入所需精度：");
    scanf("%lf",&epsilon);

    //开始二分循环，如果区间之间距离大于精度，则一直循环
    while(fabs(a-b)>epsilon)
    {
        l+=1;
        printf("第%d次计算:\n",l);
        c=(a+b)/2;//得到ab的中点
        printf("(%g,%g)的中点为%g\n",a,b,c);
        n=foo(c);//得到c点的函数值
        printf("%g点函数值为%g\n",c,n);
        if(n==0)
        {
            printf("%g刚好为函数零点\n",c);//n为0,c就是零点
            break;
        }
        if(n>0)
        {
            b=c;
            printf("零点区间为(%g,%g)\n",a,b);//n大于0,区间变为（a，n）
            printf("精度为%g\n",fabs(a-b));
        }
        if(n<0)
        {
            a=c;
            printf("零点区间为(%g,%g)\n",a,b);//n小于0,区间变为（n，b）
            printf("精度为%g\n",fabs(a-b));
        }
        printf("-----------\n");
    }
    if(n=0)
    {
        printf("共经%d次计算",l);
        printf("函数在x=%g时有零点",c);
    }
    else
    {
        printf("共经%d次计算",l);
        printf("函数在(%g,%g)间有零点，且符合精度要求\n",a,b);
    }
}

double foo (double x)
{
    //函数
    //double sum = log(x) + 2 * x - 6;
    double sum = pow(2.0,x) + x - 4;
    return sum;
}
