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
        sem_p(empty);
        sem_p(mutex);
        oranges++;
        printf("mother sets one orange and %d apple(s), it is time for oranges, my sons\n", oranges);
        sem_v(mutex);
        sem_v(orange);
        if(oranges >= 20){
            break;
        }
    }
    printf("mother have no apples\n");
    return 0;
}
