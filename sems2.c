#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

int main () {
	int semid;//IPC - дескриптор для массива семафоров 
        char pathname [] = "for_ipc.ipc"//Имя файла, с помощью которого генерируется ipc-ключ
        key_t key;// Переменная для хранения ipc-ключа
        struct sembuf mybuf;//Структура данных, задающая операцмм над определенным семафором
        //Процесс генерации ipc-ключа
        if ((key = ftok(pathname, 0 )) < 0) {
                printf ("Не удалось сгенерировать ключ ipc\n");
                exit (-1) ;
        }
        //Процесс полученния доступа к массиву семафоров для конкретного  ipc-ключа
        //Если массива семафоров не существует, то пытаемся его создать 
        if ((semid = semget (key, 1 , 0666 | IPC_CREAT)) <0 ) {
                printf ("Не удалось получить дескриптор массива семафоров\n");  
                exit (-1);

	}
	mybuf.sem_op = 1;
	mybuf.sem_flg = 0;
	mybuf.sem_num = 0;
	printf (" разблокировка процесса запущенного ранее\n ");
	if (semop(semid, &mybuf, 1) <0) {
		printf ("Не удалось выполнить операцию над семафором\n");
		exit (-1);
	}
	printf ("Значение семафора установлено в единицу\n");
	return 0;
}
