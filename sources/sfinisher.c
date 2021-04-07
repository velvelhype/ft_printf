#include "../includes/ft_printf.h"

int sfinisher(struct flags flag, char *bullet)
{
    char *canvas = NULL;
    int size;
    int sizec;
    int target;
    int sizebullet = ft_strlen(bullet);

    if(flag.prec < 0)
        flag.prec = -1;

    if(flag.prec == -1 && flag.field < 1 && flag.type == 'c' && *bullet == 0)
        flag.field = 1;

    if (flag.zero == 1 && flag.minus == 1)
        return 0;

    if ((flag.prec == -1 && flag.field <= sizebullet) || (flag.prec > sizebullet && flag.prec > flag.field && flag.field != -1 && sizebullet >= flag.field))
        size = ft_strlen(bullet); 

    else if ((flag.field > sizebullet || flag.prec < flag.field) && flag.field != -1)
        size = flag.field;
    else
        size = flag.prec;

    if (!(canvas = (char *)malloc(sizeof(char) * size + 1)))
        return -1;
    canvas[size] = '\0';
    sizec = size;

    while (size > 0)
    {
        if (flag.zero != -1)
            canvas[size - 1] = '0';
        else
            canvas[size - 1] = ' ';
        size--;
    }

    if (flag.prec != -1)
    {
        if (flag.field != -1)
        {
            if (flag.prec < sizebullet)
                sizebullet = flag.prec;
        }
        else
            sizebullet = flag.prec;
    }

    if (flag.minus != -1 && flag.field > 0)
    {
        if (flag.prec != -1 && flag.prec < sizebullet)
            target = flag.prec;
        else
            target = sizebullet;
    }
    else
        target = sizec;

    while (sizebullet > 0)
    {
        canvas[target - 1] = bullet[sizebullet - 1];
        target--;
        sizebullet--;
    }
    int howmanywewrite = ft_strlen(canvas);
    if (flag.type == 'c' && *bullet == 0)
    {
        if (flag.minus != 1)
            canvas[ft_strlen(canvas) - 1] = '\0';
        else
            *canvas = '\0';
    }
    write(1, canvas, howmanywewrite);
    free(canvas);

    return (sizec);
}