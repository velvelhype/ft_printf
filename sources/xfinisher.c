#include "../includes/ft_printf.h"

int xfinisher(char *bullet, struct flags flags)
{
    char *canvas;
    char *copy_bullet;
    int size;
    int sizec;
    int target;
    int copy_bullet_size;
    int countpre = flags.prec;    
    int bulletsize = strlen(bullet);

    if(flags.field <= 1 && flags.prec == 0 && bulletsize == 1 && *bullet  == '0')
    {
        write(1,NULL,1);
        return 0;
    }

   if(flags.prec == 0 && *bullet == '0' && *(bullet + 1) == '\0')
        bullet[strlen(bullet) - 1] = ' ';

    if(flags.prec > bulletsize)
        {

            if(!(copy_bullet = (char*)malloc(sizeof(char) * flags.prec + 1)))
                return -1;
            copy_bullet[flags.prec] = '\0';

            while(countpre > 0)
            {
                copy_bullet[countpre - 1] = '0';
                countpre--;
            }
            strcpy(&copy_bullet[flags.prec - bulletsize ] , bullet);
        }
    else
        copy_bullet = strdup(bullet);
    if(flags.zero == 1 && flags.minus == 1)
        return -1;

    if(flags.prec == -1)
        size = strlen(copy_bullet);
 
    copy_bullet_size = strlen(copy_bullet);

    if(flags.field > copy_bullet_size || flags.prec < flags.field )
        size = flags.field;
    else
        size = strlen(copy_bullet);
    
    if(!(canvas = (char*)malloc(sizeof(char)* size + 1)))
        return -1;
    canvas[size] = '\0';
    sizec = size;

    int second_precount = flags.prec;
    while (size > 0)
    {  
        if(flags.zero != -1 && second_precount)
        {
            canvas[size - 1] = '0';
            second_precount--;
        }
        else
            canvas[size - 1] = ' ';
        size--;
    }
    
    //if(flagman.prec > strlen(zbullet))
    flags.prec = strlen(copy_bullet);

    if(flags.minus != -1)
        target =  flags.prec;
    else
        target  = sizec;
    // printf("target %d flagman.prec %d\n",target,flagman.prec);
    if(flags.prec == -1)
        flags.prec = strlen(bullet);
   // printf("size %d target %d fp %d\n",size,target, flagman.prec);
    while(flags.prec != 0)
    {
        canvas[target - 1] = copy_bullet[flags.prec - 1];
        target--;
        flags.prec--;
    }
    // char mes[40] = "\nthis is what we write\nmin_ver:";
    // write(1,mes,40);
    write(1,canvas,strlen(canvas));
    free(canvas);
    free(copy_bullet);
    //printf("ori:%*.*s",flagman.field , flagman.prec, zbullet);
    return (sizec);
}