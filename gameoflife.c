//
// Created by Juuso on 6.3.2019.
//
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef enum {
    DEAD,
    ALIVE
} CellStatus;

typedef struct {
    unsigned int x_size, y_size;
    CellStatus **cells;
} GameArea;


GameArea *createGameArea(unsigned int x_size, unsigned int y_size){
    GameArea *a=malloc(sizeof(GameArea));
    a->x_size=x_size;
    a->y_size=y_size;



    CellStatus **arr=malloc(sizeof(CellStatus*)*y_size);
    int i=0;
    while(i<y_size){
        int j=0;
        arr[i]=malloc(sizeof(CellStatus)*x_size);
        while(j<x_size){
            arr[i][j]=DEAD;
            j++;
        }
        i++;
    }
    a->cells=arr;

    return a;

}

void releaseGameArea(GameArea *a){
    int i=0;
    while(i<a->y_size){
        free(a->cells[i]);
        i++;
    }
    free(a->cells);
    free(a);
}

void initGameArea(GameArea *a, unsigned int n){


    srand(20);
    int i;
    int j;
    int count=0;

    while(count<n) {
        i = rand() % a->y_size;
        j = rand() % a->x_size;
        if (a->cells[i][j] == DEAD) {
            a->cells[i][j] = ALIVE;
            count++;
        }

    }

}

void printGameArea(const GameArea *a){
    int i=0;

    while(i < a->y_size){
        int j=0;
        while(j<a->x_size){
            switch(a->cells[i][j]){
                case DEAD:
                    printf(".");
                    break;
                case ALIVE:
                    printf("*");

            }
            j++;
        }
        printf("\n");
        i++;
    }
}

int alive(GameArea *a, int i, int j){
    if(!(i>=0&&i<a->y_size)||!(j>=0&&j<a->x_size)){
        return 0;
    }else{
        if(a->cells[i][j]==ALIVE) {
            return 1;

        }else{
            return 0;

        }
    }

}

void gameTick(GameArea *a){
    GameArea *b;
    b=createGameArea(a->x_size,a->y_size);

    int i=0;

    while(i<a->y_size){
        int j=0;
        int count=0;
        while(j<a->x_size){

            count=0;
            count+=alive(a,i-1,j);
            count+=alive(a,i-1,j-1);
            count+=alive(a,i-1,j+1);
            count+=alive(a,i,j+1);
            count+=alive(a,i,j-1);
            count+=alive(a,i+1,j);
            count+=alive(a,i+1,j+1);
            count+=alive(a,i+1,j-1);


            if(a->cells[i][j]==DEAD){
                if(count==3){
                    b->cells[i][j]=ALIVE;
                } else{
                    b->cells[i][j]=DEAD;
                }
            } else{
                if(count<2||count>3){
                    b->cells[i][j]=DEAD;
                } else{
                    b->cells[i][j]=ALIVE;
                }
            }




            j++;
        }
        i++;
    }

    i=0;
    while(i<a->y_size){
        int j=0;

        while(j<a->x_size){
            a->cells[i][j]=b->cells[i][j];
            j++;
        }
        i++;
    }

    releaseGameArea(b);



}


