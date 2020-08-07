#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solveWordWrap (char **words,int l[], int n, int M)
{
    int space[n+1][n+1];
    int spaceCost[n+1][n+1];
    int cost[n+1];
    int lineAdr[n+1];
    int i, j;
    for(i = 0;i<n;i++){
        for(j = 0;j<n ;j++){
            space[i][j] = -1;
            spaceCost[i][j] = -1;
        }
    }

    for (i = 1; i <= n; i++){
        space[i][i] = M - l[i-1];
        for (j = i+1; j <= n; j++)
            space[i][j] = space[i][j-1] - l[j-1] - 1;
    }

    for (i = 1; i <= n; i++){
        for (j = i; j <= n; j++){
            if (space[i][j] < 0)
                spaceCost[i][j] = 999999;
            else if (j == n && space[i][j] >= 0)
                spaceCost[i][j] = 0;
            else
                spaceCost[i][j] = space[i][j]*space[i][j]*space[i][j];
        }
    }

    cost[0] = 0;
    for (j = 1; j <= n; j++){
        cost[j] = 999999;
        for (i = 1; i <= j; i++){
            if (cost[i-1] != 999999 && spaceCost[i][j] != 999999 && (cost[i-1] + spaceCost[i][j] < cost[j])){
                cost[j] = cost[i-1] + spaceCost[i][j];
                lineAdr[j] = i;
            }
        }
    }
    printAddress(lineAdr,n);
    printf("\n");
    printSolution(words,lineAdr, n);
    printf("\n Space Matris\n");

    for(i = 0;i<n;i++){
        for(j = 0;j<n ;j++){
            printf("%d ",space[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n SpaceCost Matris\n");

    for(i = 0;i<n;i++){
        for(j = 0;j<n ;j++){
            printf("%d ",spaceCost[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n Cost Array: \n");

    for(i = 0;i<n;i++){
        printf("%d ",cost[i]);
    }
}

int printAddress(int lineAdr[], int n) {
    int lineNumber;
    if (lineAdr[n] == 1)
        lineNumber = 1;
    else
        lineNumber = printAddress (lineAdr, lineAdr[n]-1) + 1;
    printf ("Line number %d: From word no. %d to %d \n", lineNumber, lineAdr[n], n);
    return lineNumber;
}

int printSolution (char **words,int lineAdr[], int n)
{
    int lineNumber,i;
    if (lineAdr[n] == 1)
        lineNumber = 1;
    else
        lineNumber = printSolution (words,lineAdr, lineAdr[n]-1) + 1;
    //printf ("Line number %d: From word no. %d to %d \n", lineNumber, lineAdr[n], n);
    for(i = lineAdr[n]-1;i<n;i++){
        printf("%s ",words[i]);
    }
    printf("\n");
    return lineNumber;
}

int main()
{
    FILE *fp1;
    char **words;
    int count,i,wLength[50],n,m;
    count = 0;
    words = (char**)malloc(9999*sizeof(char*));
    for(i=0;i<50;i++){
        words[i] = (char*)malloc(50*sizeof(char));
    }
    fp1 = fopen("deneme2.txt","r");
    while (!feof(fp1))  {
        fscanf(fp1,"%s",words[count]); /* dosyadan bir kelime okuyalim */
        wLength[count] = strlen(words[count]);
        printf("%s %d\n",words[count],wLength[count]);       /* ekrana yazalim               */
        count++;
    }              /* ta ki EOF olana kadar          */
    printf("\n Words count:%d",count);
    printf("%s\n",words[count]);
    fclose(fp1);
    n = 41;
    m = 25;
    solveWordWrap(words,wLength,n,m);
}
