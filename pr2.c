#include<stdio.h>
int main()
{
    int no=0;
    FILE *fp, *odd, *even;
    fp=fopen("num.txt", "w+");
    odd=fopen("odd.txt", "w+");
    even=fopen("even.txt", "w+");
    printf("Enter the number (enter -1 to exit): \n");
    while (no!=-1)
    {
        scanf("%d", &no);
        if(no%2==0)
        putw(no,even);
        else
        putw(no,odd);
    }

    rewind(fp);
    rewind(odd);
    rewind(even);

    printf("Odd contents: \n");
    while ((no=getw(odd))!=-1)
    {
        printf("%d ", no);
    }
    
    printf("\n");

    printf("Even contents: \n");
    while ((no=getw(even))!=-1)
    {
        printf("%d ", no);
    }
    
    fclose(fp);
    fclose(even);
    fclose(odd);

    return 0;
}