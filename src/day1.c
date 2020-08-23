#include <stdio.h>
#include <complex.h>

#define abs(x) ({int z;\
                if(x>0) z=x;\
                else z=-x;\
                z;})
#define max(a, b) ((a)>(b)?(a):(b))
#define max_safe(a, b) ({int _a=(a),_b=(b);_a>_b?_a:_b;})
#define O_l(arr)        ({int o_l;o_l=sizeof(arr)/sizeof(*arr);o_l;})
#define R_l(arr)        ({int r_l;r_l=sizeof(arr)/sizeof(*arr);r_l;})
#define C_l(arr)        ({int c_l;c_l=sizeof(*arr)/sizeof(**arr);c_l;})

#define SEARCH(value, array, target, r_l, c_l)          \
do{                                                     \
__label__ found;                                        \
typeof(target) _SEARCH_target=(target);                 \
typeof(*(array)) *_SEARCH_array=(array);                \
int i,j;                                                \
for(i=0;i<r_l;i++)                                      \
        for(j=0;j<c_l;j++)                              \
                if(_SEARCH_array[i][j]==_SEARCH_target) \
                        {(value)=i;goto found;}         \
(value)=-1;                                             \
found:;                                                 \
}while(0)

#define SEARCH_se(array, target, r_l, c_l)              \
({                                                      \
__label__ found;                                        \
typeof(target) _SEARCH_target=(target);                 \
typeof(*(array)) *_SEARCH_array=(array);                \
int i,j;                                                \
int value;                                              \
for(i=0;i<r_l;i++)                                      \
        for(j=0;j<c_l;j++)                              \
                if(_SEARCH_array[i][j]==_SEARCH_target) \
                        {value=i;goto found;}           \
value=-1;                                               \
found:                                                  \
        value;                                          \
})

#define CUSTOM_GENERIC(_var_) _Generic((_var_), \
/*signed char*/                 signed char : printf("type signed char, var:%d\n", _var_),                             \
/*signed short*/                signed short : printf("type signed short, var:%hd\n", _var_),                          \
/*signed int*/                  signed int : printf("type signed int, var:%d\n", _var_),                               \
/*signed long int */            signed long int : printf("type signed long int, var:%ld\n", _var_),                    \
/*signed long long int*/        signed long long int : printf("type signed long long int, var:%lld\n", _var_),         \
/*unsigned char*/               unsigned char : printf("type unsigned char, var:%c\n", _var_),                         \
/*unsigned short*/              unsigned short : printf("type unsigned short, var:%hu\n", _var_),                      \
/*unsigned int*/                unsigned int : printf("type unsigned int, var:%u\n", _var_),                           \
/*unsigned long int*/           unsigned long int : printf("type unsigned long int, var:%lu\n", _var_),                \
/*unsigned long long int*/      unsigned long long int : printf("type unsigned long long int, var:%llu\n", _var_),     \
/*float*/                       float : printf("type float, var:%f\n", _var_),                                         \
/*double*/                      double : printf("type double, var:%lf\n", _var_),                                      \
/*_Bool*/                       _Bool : printf("type _Bool, var:%d\n", _var_),                                         \
/*default*/                     default : printf("type default!")                                                      \
)

int main(int argc, char *argv[])
{
        int b = abs(-12);
        int a;
        a = ({
                int y = -2;
                int z;
                if (y > 0) z = y;
                else z = -y;
                z;
        });
        printf("%d \n", a);
        printf("%d \n", b);


        printf("max(-1,3) %d  \n", max(-1, 3));
        printf("max_safe(-1,3) %d\n", max_safe(-1, 3));

        int arr[3][2] = {123, 456, 789, 123, 457, 765};
        int v1;
        SEARCH(v1, arr, 765, 3, 2);
        printf("%d\n", v1);
        int v2 = SEARCH_se(arr, 789, 3, 2);
        printf("%d\n", v2);

        printf("%d\n", O_l(arr[0]));
        printf("%d\n", R_l(arr));
        printf("%d\n", C_l(arr));
        CUSTOM_GENERIC(12u);
        return 0;
}

