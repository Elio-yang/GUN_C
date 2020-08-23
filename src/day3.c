#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int pass();
int func();

#define max(a,b)                  \
        ({                        \
                typeof(a) _a=(a); \
                typeof(b) _b=(b); \
                _a>_b?_a:_b;      \
        })

#define pointer(T) typeof(T*)
#define array(T,N) typeof(T[N])

#define __offsetof__(type,member) ((size_t)&((type*)0)->member)
#define __container_of__(ptr,type,member)                  \
({                                                         \
        const typeof(((type*)0)->member) *__mptr=(ptr);    \
        (type*)((char*)__mptr - __offsetof__(type,member));\
})

struct line{
        int length;
        char contents[0];
};

FILE *concat_fopen(char *s1,char *s2,char *mode);
int main(int argc , char *argv[])
{
//        int result;
//        result=pass(1,7,10);
//        printf("result=%d\n",result);
        char A='a';
        char B='a';
        char C='a';
        char D='a';
        array(pointer(char),4) y={&A,&B,&C,&D};

        struct line * thisline2=(struct line*)malloc(sizeof(struct line));
        thisline2->length=0;

        int this_length=10;
        struct line * thisline1=(struct line*)malloc(sizeof(struct line) + this_length);
        thisline1->length=this_length;
        *(thisline1->contents)='b';
        printf("%c",thisline1->contents[0]);
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
FILE *concat_fopen(char *s1,char *s2,char *mode)
{
        char str[strlen(s1)+strlen(s2)+1];
        strcpy(str,s1);
        strcat(str,s2);
        return fopen(str,mode);
}

