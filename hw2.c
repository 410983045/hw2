#include <stdio.h>

int main(){

    int chess[8][8] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 2, 0, 0, 0},
        {0, 0, 0, 2, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };


    int i,j,color;

    scanf("%d %d %d",&i,&j,&color);



    if (chess[i][j] == 0){
      printf("empty");
    }

    else if (chess[i][j] == 1){
      printf("black");
    }

    else if (chess[i][j] == 2){
      printf("white");
    }






   return 0;
  }
