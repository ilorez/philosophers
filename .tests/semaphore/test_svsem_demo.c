
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/stat.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <stdarg.h>

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

void errExit(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void usageErr(const char *format, ...) {
    va_list argList;
    va_start(argList, format);
    vfprintf(stderr, format, argList);
    va_end(argList);
    exit(EXIT_FAILURE);
}

int getInt(const char *arg, int flags, const char *name) {
    char *endptr;
    int val = strtol(arg, &endptr, 10);

    if (*endptr != '\0' || errno == ERANGE)
        errExit(name);
    return val;
}

char *currTime(const char *format) {
    static char buf[64];
    time_t t = time(NULL);
    strftime(buf, sizeof(buf), format, localtime(&t));
    return buf;
}

int main(int argc, char *argv[]) {
    int semid;

    if (argc < 2 || argc > 3 || strcmp(argv[1], "--help") == 0)
        usageErr("%s init-value\n   or: %s semid operation\n", argv[0], argv[0]);

    if (argc == 2) { // Create and initialize semaphore
        union semun arg;

        semid = semget(IPC_PRIVATE, 1, S_IRUSR | S_IWUSR);
        if (semid == -1)
            errExit("semget");

        arg.val = getInt(argv[1], 0, "init-value");
        if (semctl(semid, 0, SETVAL, arg) == -1)
            errExit("semctl");

        printf("Semaphore ID = %d\n", semid);
    } else { // Perform an operation on first semaphore
        struct sembuf sop;
        semid = getInt(argv[1], 0, "semid");

        sop.sem_num = 0;
        sop.sem_op = getInt(argv[2], 0, "operation");
        sop.sem_flg = 0;

        printf("%ld: about to semop at  %s\n", (long)getpid(), currTime("%T"));
        if (semop(semid, &sop, 1) == -1)
            errExit("semop");

        printf("%ld: semop completed at %s\n", (long)getpid(), currTime("%T"));
    }

    exit(EXIT_SUCCESS);
}
