#include <stdio.h>
#include <math.h>
int main()
{
    int row, column;                                //row是行，column是列 
    int sign;
    printf("Input the numbers of the UPPER rows:");
	scanf("%d",&sign);
    for (row = -sign;row <= sign;row++)
    {
        for (column = -sign;column <= sign;column++)
            printf((abs(row) + abs(column) <= sign)? "*":" ");
        printf("\n");
    }
    getch();
    getch();
return 0;
}
