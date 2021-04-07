#include "../includes/ft_printf.h"

char    *ft_itoa(size_t e)
{
    int neg = 0;
    long len = 0;
    char *slot;
    long ruler = 1;
    long d = e;

    if(d < 0)
    {
        neg = 1;
        d = -d;
    }
    if(d < 10)
        len = 1;
    while(ruler <= d && d >= 10)
    {
        ruler *= 10;
        len++;
    }
    if(!(slot = (char*)malloc(sizeof(char)* len + neg + 1)))
         return (NULL);
    slot[len + neg] = '\0';
    while(len > 0)
    {
        slot[--len + neg] = d % 10 + 48;
        d /= 10;
    }
    slot[0] = neg == 1 ? '-' : slot[0];
    return (slot);
}

char hexmaker(unsigned long x, int flag)
    {
        if(x > 9 && flag == 'X')
            return (x + 55);
        if(x > 9)
            return (x + 87);
        return (x + 48);
    }

int hexdigit(unsigned long d)
{
    int count = 0;

    if (d < 0)
        return 9;
    if(d == 0)
        count++;
    while(d)
    {
        d /= 16;
        count++;
    }
    count = count + 1;
    return count;
}

char    *x_con(unsigned long d, int flag)
{
    long    amari;
    int     len;
    char    *slot;

    amari = 0;
    len =  0;
    len = hexdigit(d);            
    if(!(slot = (char*)malloc(sizeof(char)* len)))
        return NULL;
    len--;
    slot[len] = '\0';
    len--;
    while (len >= 0)
    {
        amari = d % 16;
        slot[len] = hexmaker(amari, flag);
        d = d / 16;
        len --;
    }
    return (slot);
}
