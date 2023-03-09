#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool judgeCircle(char * moves){
    //WRITE CODE HERE
    int x=0,y=0;
    for (int it=0;it<strlen(moves);it++){
        if (moves[it]=='L'){
            x--;
        }
        else if (moves[it]=='R'){
            x++;
        }
        else if (moves[it]=='U'){
            y++;
        }
        else if(moves[it]=='D'){
            y--;
        }
    }
    return x==0 && y==0;

}
int main()
{
    char arr[] = {};
    bool result;
    scanf("%s",arr);
    result = judgeCircle(arr);
    (result == 0) ? printf("false") : printf("true");
    return 0;
}


// Given an m x n matrix, return all elements of the matrix in spiral order. First line indicates m(number of rows) and second line indicates n(number of columns). The next m*n lines indicates the elements of the matrix. Print the ouput in one line.

// Path: 1.c

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    //WRITE CODE HERE
    int *result = (int *)malloc(sizeof(int)*matrixSize*(*matrixColSize));
    int i=0,j=0;
    int k=0;
    int m=matrixSize;
    int n=*matrixColSize;
    int count=0;
    while (count<m*n){
        while (j<n && matrix[i][j]!=-101){
            result[k]=matrix[i][j];
            matrix[i][j]=-101;
            j++;
            k++;
            count++;
        }
        j--;
        i++;
        while (i<m && matrix[i][j]!=-101){
            result[k]=matrix[i][j];
            matrix[i][j]=-101;
            i++;
            k++;
            count++;
        }
        i--;
        j--;
        while (j>=0 && matrix[i][j]!=-101){
            result[k]=matrix[i][j];
            matrix[i][j]=-101;
            j--;
            k++;
            count++;
        }
        j++;
        i--;
        while (i>=0 && matrix[i][j]!=-101){
            result[k]=matrix[i][j];
            matrix[i][j]=-101;
            i--;
            k++;
            count++;
        }
        i++;
        j++;
        m--;
        n--;
    }
    *returnSize = k;
    return result;
}

int main()
{
    int m,n;
    scanf("%d",&m);
    scanf("%d",&n);
    int **matrix = (int **)malloc(sizeof(int *)*m);
    for (int i=0;i<m;i++){
        matrix[i] = (int *)malloc(sizeof(int)*n);
    }
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    int returnSize;
    int *result = spiralOrder(matrix,m,&n,&returnSize);
    for (int i=0;i<returnSize;i++){
        printf("%d ",result[i]);
    }
    return 0;
}