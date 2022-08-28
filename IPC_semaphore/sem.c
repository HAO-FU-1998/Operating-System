#include "sem.h"

static int semid = 0;

void sem_init() {
    key_t ipckey;
    ipckey = ftok(".", 1);

    semid = semget(ipckey,4,IPC_CREAT | IPC_EXCL| 0666);
    if(semid == -1) {
        semid = semget(ipckey,4,IPC_CREAT | 0666);
        if(semid == -1) {
            printf("semget error");
        }
    }
    else {
        if(semctl(semid,0,SETVAL,0)== -1)
        {
            perror("semctl init error");
        }
        if(semctl(semid, 1, SETVAL, 0) == -1){
            perror("semctl init error");
        }
        if(semctl(semid, 2, SETVAL, 1) == -1){
            perror("semctl init error");
        }
        if(semctl(semid, 3, SETVAL, 2) == -1){
            perror("semid init error");
        }
    }
}
void sem_p(int sem_num) {
    struct sembuf buf;
    buf.sem_num = sem_num;
    buf.sem_op = -1;
    buf.sem_flg = SEM_UNDO;
    if(semop(semid,&buf,1)==-1) {
        perror("p error");
    }
}
void sem_v(int sem_num) {
    struct sembuf buf;
    buf.sem_num = sem_num;
    buf.sem_op = 1;
    buf.sem_flg = SEM_UNDO;
    if(semop(semid,&buf,1)==-1)
    {
        perror("v error");
    }
}
void sem_destroy(int sem_num) {
    if(semctl(semid,sem_num,IPC_RMID)==-1)
    {
        perror("semctl destroy error");
    }
}

