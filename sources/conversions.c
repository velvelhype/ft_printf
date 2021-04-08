#include "../includes/ft_printf.h"
char *itoa_make(long len, int neg, long d)
{
	char *slot;
	if (!(slot = (char*)malloc(sizeof(char) * len + neg + 1)))
		return (NULL);
	slot[len + neg] = '\0';
	while (len > 0)
	{
		slot[--len + neg] = d % 10 + 48;
		d /= 10;
	}
	slot[0] = neg == 1 ? '-' : slot[0];

	return slot;
}

char	*ft_itoa(size_t e)
{
	int		neg;
	long 	len;
	long 	ruler;
	long 	d;
	
	ruler = 1;
	d = e;
	neg = d < 0 ? 1:0;
	if(neg == 1)
		d = -d;
	len = d < 10 ? 1:0;
	while (ruler <= d && d >= 10)
	{
		ruler *= 10;
		len++;
	}
	return (itoa_make(len, neg, d));
}

char	hexmaker(unsigned long x, int flag)
{
	if (x > 9 && flag == 'X')
		return (x + 55);
	if (x > 9)
		return (x + 87);
	return (x + 48);
}

int		hexdigit(unsigned long d)
{
	int count;

	count = 0;
	if (d < 0)
		return (9);
	if (d == 0)
		count++;
	while (d)
	{
		d /= 16;
		count++;
	}
	count = count + 1;
	return (count);
}

char	*x_con(unsigned long d, int flag)
{
	long	amari;
	int		len;
	char	*slot;

	amari = 0;
	len = 0;
	len = hexdigit(d);
	if (!(slot = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	len--;
	slot[len] = '\0';
	len--;
	while (len >= 0)
	{
		amari = d % 16;
		slot[len] = hexmaker(amari, flag);
		d = d / 16;
		len--;
	}
	return (slot);
}
