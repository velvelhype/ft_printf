#include "../includes/ft_printf.h"

int xfinisher(char *bullet, struct s_fls s_fls)
{
    char *canvas;
    char *copy_bullet;
    int size;
    int sizec;
    int target;
    int copy_bullet_size;
    int countpre = s_fls.prec;    
    int bulletsize = strlen(bullet);

    if(s_fls.field <= 1 && s_fls.prec == 0 && bulletsize == 1 && *bullet  == '0')
    {
        write(1,NULL,1);
        return 0;
    }

   if(s_fls.prec == 0 && *bullet == '0' && *(bullet + 1) == '\0')
        bullet[strlen(bullet) - 1] = ' ';

    if(s_fls.prec > bulletsize)
        {

            if(!(copy_bullet = (char*)malloc(sizeof(char) * s_fls.prec + 1)))
                return -1;
            copy_bullet[s_fls.prec] = '\0';

            while(countpre > 0)
            {
                copy_bullet[countpre - 1] = '0';
                countpre--;
            }
            strcpy(&copy_bullet[s_fls.prec - bulletsize ] , bullet);
        }
    else
        copy_bullet = strdup(bullet);
    if(s_fls.zero == 1 && s_fls.minus == 1)
        return -1;

    if(s_fls.prec == -1)
        size = strlen(copy_bullet);
 
    copy_bullet_size = strlen(copy_bullet);

    if(s_fls.field > copy_bullet_size || s_fls.prec < s_fls.field )
        size = s_fls.field;
    else
        size = strlen(copy_bullet);
    
    if(!(canvas = (char*)malloc(sizeof(char)* size + 1)))
        return -1;
    canvas[size] = '\0';
    sizec = size;

    int second_precount = s_fls.prec;
    while (size > 0)
    {  
        if(s_fls.zero != -1 && second_precount)
        {
            canvas[size - 1] = '0';
            second_precount--;
        }
        else
            canvas[size - 1] = ' ';
        size--;
    }
    
    //if(flagman.prec > strlen(zbullet))
    s_fls.prec = strlen(copy_bullet);

    if(s_fls.minus != -1)
        target =  s_fls.prec;
    else
        target  = sizec;
    // printf("target %d flagman.prec %d\n",target,flagman.prec);
    if(s_fls.prec == -1)
        s_fls.prec = strlen(bullet);
   // printf("size %d target %d fp %d\n",size,target, flagman.prec);
    while(s_fls.prec != 0)
    {
        canvas[target - 1] = copy_bullet[s_fls.prec - 1];
        target--;
        s_fls.prec--;
    }
    // char mes[40] = "\nthis is what we write\nmin_ver:";
    // write(1,mes,40);
    write(1,canvas,strlen(canvas));
    free(canvas);
    free(copy_bullet);
    //printf("ori:%*.*s",flagman.field , flagman.prec, zbullet);
    return (sizec);
}