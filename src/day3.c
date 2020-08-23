#include <stdio.h>
int pass();
int func();

int main(int argc , char *argv[])
{
        int result;
        result=pass(1,7,10);
        printf("result=%d\n",result);
        return 0;
}

int pass(int a, int b, int c)
{
        void *record;
        void *back;
        void (*fn)()=(void(*)())func();

        record=__builtin_apply_args();
        back=__builtin_apply(fn,record,128);
        __builtin_return(back);
}
int func(int a,int b, int c)
{
        return ((a+b+c)/3);
}