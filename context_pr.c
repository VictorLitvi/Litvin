#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[], char *envp[]) {
	pid_t procid, parentid, result;
	printf ("Порождаем дочерний процесс/n");
	result =fork();
	if (result<0) {
		printf("Ошибка при выполнении fork()/n");
		exit (-1);
	}
	else if (result==0){
		procid = getpid();
		parentid = getppid();
		printf("Ид. текущего процесса :%d/n",procid);
		printf("Ид. родительского процесса :%d/n",parentid);
		printf("Значение переменной result :%d/n",result);
		execle("./args.out", "./args.out","args.c", 0, envp);
		printf("Ошибка при выполнении системног вызова exec()/n");
		exit(-1);
		}
	else {
		procid =getpid();
		parentid = getppid();
		printf("Ид. текущего процесса :%d/n",procid);
                printf("Ид. родительского процесса :%d/n",parentid);
                printf("Значение переменной result :%d/n",result);
	}
	return 0;
}
