#include <stdio.h>
#include "sem.h"
#define apple 0
#define orange 1
#define mutex 2
#define empty 3

int main(){
    sem_init();
    int apples = 0;
    while(1){
        sem_p(apple);
        sem_p(mutex);
        apples++;
        printf("daughter is eating the orange, and has ate %d oranges\n", apples);
        sem_v(mutex);
        sem_v(empty);
        if(apples >= 20){
            break;
        }
    }
    printf("there is no apples\n");
    return 0;
}
