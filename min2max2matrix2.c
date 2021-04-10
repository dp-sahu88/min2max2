//Author:DEADPOOL
//User@DEADPOOL
//Device name:LAPTOP-MGJPSU5N
//***************************
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
//defining isinteger
int isinteger(char s[10]){
    int i;
    for (i=0;s[i]!='\0';i++)
        if (isdigit(s[i])==0)
            return 0;
    return 1;
}
//min_max() definition
void min_max(int **matrix,int matrix_row,int matrix_col){
    struct position{
    int x;
    int y;
    }mnp1,mnp2,mxp1,mxp2;
    int min1,min2,max2,max1,count_i,count_j;
    min1=min2=max1=max2=matrix[0][0];
    mnp1.x=mnp1.y=mnp2.x=mnp2.y=0;
    mxp1.x=mxp1.y=mxp2.x=mxp2.y=0;
    for (count_i=0;count_i<matrix_row;count_i++){
        for(count_j=0;count_j<matrix_col;count_j++){
            if(max1<matrix[count_i][count_j]){
                max2=max1;
                mxp2.x=mxp1.x;
                mxp2.y=mxp1.y;
                max1=matrix[count_i][count_j];
                mxp1.x=count_i;
                mxp1.y=count_j;
            }
            else if ((matrix[count_i][count_j] > max2)&&(matrix[count_i][count_j] != max1)){
                max2=(matrix[count_i][count_j]);
                mxp2.x=count_i;
                mxp2.y=count_j;
            }
        }

    }
    printf("\n Largest number in matrix is %d \n position is [%d,%d]",max1,mxp1.x,mxp1.y);
    printf("\n Second Largest number in matrix is %d \n position is [%d,%d]",max2,mxp2.x,mxp2.y);

    for (count_i=0;count_i<matrix_row;count_i++){
        for(count_j=0;count_j<matrix_col;count_j++){
            if(min1>matrix[count_i][count_j]){
                min2=min1;
                mnp2.x=mnp1.x;
                mnp2.y=mnp1.y;
                min1=matrix[count_i][count_j];
                mnp1.x=count_i;
                mnp1.y=count_j;
            }
            else if ((matrix[count_i][count_j] < max2)&&(matrix[count_i][count_j] != max1)){
                min2=matrix[count_i][count_j];
                mnp2.x=count_i;
                mnp2.y=count_j;
            }
        }

    }
    printf("\n  Smallest number in matrix is %d \n position is [%d,%d]",min1,mnp1.x,mnp1.y);
    printf("\n  Second Smallest number in matrix is %d \n position is [%d,%d]",min2,mnp2.x,mnp2.y);
    return ;
}
// main function
int main(){
    // variable declaration
    int matrix_row,matrix_col,counter,i_flag,count_i,count_j,k;
    char str[10];
    // taking the dimension as input
m_row: // getting row
        printf("\n Enter the number of rows in the matrix: ");
        fflush(stdin);
        scanf("%s",str);
        i_flag=isinteger(str);
            if (i_flag)
                matrix_row=atoi(str);
            else
                goto m_row;
m_col:  //getting column
        printf("\n Enter the number of column in the matrix: ");
        fflush(stdin);
        scanf("%s",str);
        i_flag=isinteger(str);
            if (i_flag)
                matrix_col=atoi(str);
            else
                goto m_col;

         //considering that user may give 1*1 or  0*1 or 0*1 matrix which is.... (`~`)
        if ((matrix_row==1&&matrix_col==1)||matrix_row==0||matrix_col==0){
             printf("you should enter the proper dimension of a matrix...\t try again........ ");
             goto m_row;
        }
    //declaring a 2-d array dynamically   with dimension matrix_row * matrix_col
    int **matrix = (int **)malloc(matrix_row * sizeof(int *));
    for (counter=0; counter<matrix_row; counter++)
         matrix[counter] = (int *)malloc(matrix_col * sizeof(int));

    printf("\n Enter the element of matrix...\n");

    for(count_i=0;count_i<matrix_row;count_i++){
        for(count_j=0;count_j<matrix_col;count_j++){
            elmt:
                printf("[%d][%d] : ",count_i+1,count_j+1);
                scanf("%s",str);
                i_flag=isinteger(str);
            if (i_flag)
                matrix[count_i][count_j]=atoi(str);
            else{
                printf("\nyou entered a character at [%d][%d] position ,enter that again..\n ",count_i+1,count_j+1);
                goto elmt;
            }
        }

    }
   min_max(matrix,matrix_row,matrix_col);



return 0;
}
