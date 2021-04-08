#include "ft_printf.h"

int main()
{
    printf("%d\n",printf("%-5c", 0));
    printf("%d\n",ft_printf("%-5c", 0));
    return 0;
}