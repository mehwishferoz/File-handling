#include<stdio.h>
int main()
{
    FILE *fp;
    char article[1000];
    fp = fopen("strings.txt", "w+");

    printf("Enter the article: (enter ~ to exit)\n");
    scanf("%[^~]s", article);

    fputs(article,fp);

    rewind(fp);

    while(!feof(fp))
    {
    fgets(article,10,fp);
    printf("%s", article);
    }


    return 0;
}