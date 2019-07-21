#include<stdio.h>
#define FUN(arg) do\
                 {\
                    if(arg)\
                        printf("IndiaBIX...", "\n");\
                  }while(--i)

int main()
{
    int i=2;
    FUN(i<3);
    return 0;
}
