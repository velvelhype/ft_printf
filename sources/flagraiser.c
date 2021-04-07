#include "../includes/ft_printf.h"

int typefinder(char s)
{
    if (s == 'c' || s == 's' || s == 'p' || s == 'd')
        return s;
    if (s == 'i' || s == 'u' || s == 'x' || s == 'X' || s == '%')
        return s;
    return 0;
}


void flag_init(struct flags *flag)
{
    flag->minus = -1;
    flag->zero = -1;
    flag->field = -1;
    flag->prec = -1;
    flag->type = -1;
    flag->flagsize = -1;
}

char *pre_field(char *string, struct flags *flag)
{
    while(*string == '-')
    {
        flag->minus = 1;
        string++;
    }
    while (*string == '0')
    {
        if (flag->minus != 1)
            flag->zero = 1;
        string++;
    }
    while (*string == '-')
    {
        flag->minus = 1;
        string++;
    }
    return string;
}

struct flags flagmaker(struct flags flag, char *string, va_list ap)
{
    int digitsize = 0;
    char *opoint;

    opoint = string;
    flag_init(&flag);
    string = pre_field(string, &flag);

    if ('0' <= *string && *string <= '9')
    {
        flag.field = 0;
        while (typefinder(*(string + digitsize)) == 0 && *(string + digitsize) != '.')
            digitsize++;
        while (digitsize > 0)
        {
            flag.field = (flag.field * 10 + (*string - 48));
            string++;
            digitsize--;
        }
    }
    else if (*string == '*')
    {
        flag.field = va_arg(ap, int);
        
        if (flag.field < 0)
        {
            flag.field *= -1;
            flag.minus = 1;
        }
        string++;
    }
    else
        flag.field = -1;


    if (*string == '.')
    {
        string++;
        if (*string == '*')
        {
            flag.prec = va_arg(ap, int);
            string++;
        }
        else
        {
            flag.prec = 0;
            digitsize = 0;
            while (typefinder(*(string + digitsize)) == 0 && *(string + digitsize) != '.')
            {
                flag.prec = (flag.prec * 10) + *(string + digitsize) - '0';
                digitsize++;
            }
            while (digitsize > 0)
            {
                string++;
                digitsize--;
            }
        }
    }
    else
        flag.prec = -1;

    flag.type = typefinder(*string);
    flag.flagsize = string - opoint;

    if(flag.zero == 1 && flag.minus == 1 )
        flag.zero = -1;
    return flag;
}