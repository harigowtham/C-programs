#include<stdio.h>
#include<stdlib.h>

int main() {
  int n=0, count =1, r = 0, c = 0;
  //printf("enter nxn 's n value:");
  printf("enter row and col of mat\n");
  scanf("%d %d", &r , &c);
  int *mat = (int *)malloc(r*c*(sizeof(int)));

  //geneerating matrix 1:
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      *(mat + i*c + j) = count++;
    }
  }
    printf("\n");

  int r1 = 0, c1 = 0;
  printf("enter row and col of mat1\n");
  scanf("%d %d", &r1 , &c1);
  count = 1;
  int *mat1 = (int *)malloc(r1*c1*(sizeof(int)));

  //geneerating matrix 1:
  for (int i = 0; i < r1; i++) {
    for (int j = 0; j < c1; j++) {
      *(mat1 + i*c1 + j) = count++;
    }
  }

    printf("\n");
  //printfing
  printf("mat\n");
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      printf("%d\t", *(mat + i*c + j));
    }
    printf("\n");
  }

    printf("\n");
  //printfing
  printf("mat1\n");
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      printf("%d\t", *(mat1 + i*c + j));
    }
    printf("\n");
  }

    printf("\n");
  //transpose
  printf("trans\n");
  for (int i = 0; i < c; i++) {
    for (int j = 0; j < r; j++) {
      printf("%d\t", *(mat + j*r + i));
    }
    printf("\n");
  }
    printf("\n");

  //multiplication doesnt work:
  int row = 0, col = 0, t = 0;
  if (c == r1){
    row = r1;
    col = c1;
  } else if (c1 == r) {
    row = r;
    col = c;
    int *tmp = mat1;
    mat1 = mat;
    mat = tmp;
  } else {
    printf("not possible\n");
    return 1;
  }
  printf("mul\n");
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      for (int k = 0; j < c1; k++) {
        //printf("%d\t", (*(mat + i*col + j) * *(mat1 + j*row  + i)));
        *(mat + i*col + j) += (*(mat + i + k) * *(mat1 + i*col +j  + k));
      }
      printf("%d \n", *(mat + i*col + j));
    }
    printf("\n");
  }
    return 1;

}
