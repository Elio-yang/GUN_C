#include <stdio.h>

__attribute__((__noinline__,__noclone__)) void switch_eg(long x,long n,long *dest)
{
        long val=x;
        switch (n) {
                case 100:
                        val *=3;
                        break;
                case 102:
                        val +=10;
                        /*go through*/
                case 103:
                        val +=11;
                        break;
                case 104:
                case 106:
                        val *=val;
                        break;
                default:
                        val=0;
        }
        *dest=val;
}
void switch_eg_jp(long x,long n,long *dest)
{
        static void *jt[7]={
                &&loc_A,        /*case 100*/
                &&local_def,    /*case 101--->default*/
                &&loc_B,        /*case 102*/
                &&loc_C,        /*case 103*/
                &&loc_D,        /*case 104*/
                &&local_def,    /*case 105--->default*/
                &&loc_D         /*case 106*/
        };
        unsigned long index=n-100;
        long val;
        if (index>6){
                goto local_def;
        }
        goto *jt[index];

        loc_A:  /*case 100*/
                val=x*13;
                goto done;
        loc_B:  /*case 102*/
                x=x+10;
                /*go through*/
        loc_C:  /*case 103*/
                val=x+11;
                goto done;
        loc_D:  /*case 104 & 106*/
                val=x*x;
                goto done;
        local_def:
                val=0;
        done:
                *dest=val;

}
double foo(double a,double b)
{
        double square(double z){
                return z*z;
        }
        return square(a)+square(b);
}

int main(int argc , char *argv[])
{
        long x=10;
        long n=103;
        long dest1=10;
        long dest2=20;
        switch_eg(x,n,&dest1);
        switch_eg_jp(x,n+3,&dest2);
        printf("%ld \n",dest1);
        printf("%ld \n",dest2);
        printf("%lf",foo(3,4));
        return 0;
}