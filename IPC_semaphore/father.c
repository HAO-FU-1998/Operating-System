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
        sem_p(empty);
        sem_p(mutex);
        apples++;
        printf("father sets one apple and %d apple(s), it is time for apples, my daughters\n", apples);
        sem_v(mutex);
        sem_v(apple);
        if(apples >= 20){
            break;
        }
    }
    printf("father have no apples\n");
    return 0;
}
