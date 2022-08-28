#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <sys/sem.h>
#include <unistd.h>


struct semun { int val; };


void sem_init();
void sem_p(int sem_num);
void sem_v(int sem_num);
void sem_destroy(int sem_num);
