#include <stdio.h>

#define abs(x) ({int z;\
                if(x>0) z=x;\
                else z=-x;\
                z;})
#define max(a, b) ((a)>(b)?(a):(b))
#define max_safe(a, b) ({int _a=(a),_b=(b);_a>_b?_a:_b;})
#define SEARCH(value,array,target, r_l, c_l)                 \
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

#define SEARCH_se(array,target,r_l,c_l)                 \
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

        int arr[3][2]={123,456,789,123,457,765};
        int v1;
        SEARCH(v1,arr,765,3,2);
        printf("%d\n",v1);
        int v2=SEARCH_se(arr,789,3,2);
        printf("%d\n",v2);

        return 0;
}

