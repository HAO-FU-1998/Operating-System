#include <stdio.h>
#include "sem.h"
#define apple 0
#define orange 1
#define mutex 2
#define empty 3

int main(){
    sem_init();
    int oranges = 0;
    while(1){
        sem_p(orange);
        sem_p(mutex);
        oranges++;
        printf("son is eating the orange, and has ate %d oranges\n", oranges);
        sem_v(mutex);
        sem_v(empty);
        if(oranges >= 20){
            break;
        }
    }
    printf("there is no oranges\n");
    return 0;
}
