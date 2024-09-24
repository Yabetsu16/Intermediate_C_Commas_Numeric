#include <stdio.h>
#include <string.h>

void commify(char *s, int v)
{
	char temp[15];
	int len,c,t;

	sprintf(temp,"%d",v);

	len = strlen(temp);
	c = t = 0;
	while(temp[t]!='\0')
	{
		if( len % 3 )
		{
			*(s+c) = temp[t];
		}
		else
		{
			if( t != 0 )
			{
				*(s+c) = ',';
				c++;
			}
			*(s+c) = temp[t];
		}
		c++;
		t++;
		len--;
	}
	*(s+c) = '\0';
}

int main()
{
	int values[10] = {
		123, 1899, 48266, 123456, 9876543,
		10100100, 5, 500000, 99000111, 83
	};
	char withcomma[15];
	int x;

	for( x=0; x<10; x++ )
	{
		commify(withcomma,values[x]);
		printf("%10d:%15s\n", values[x], withcomma);
	}

	return(0);
}
