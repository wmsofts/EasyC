#include<stdio.h>
#include<stdlib.h>
 
int main()
{
	for (size_t i = 1; i < 1000; i++)
	{
		int count = 1;
		for (size_t j = 2; j < i; j++)
		{
			if (i % j == 0) 
			{
				count = 0;
			}
		}
		if (i < 100 && count && i/10 == i%10)
		{
			printf("%d\n", i);
		}
		else if (i > 100 && count && i / 100 == i % 10)
		{
			printf("%d\n", i);
		}
	}

	getch();
	return 0;
}
