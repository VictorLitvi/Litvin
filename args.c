#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[], char *envp[] ) {
	if (argc>1) {
		printf ("kolihestvo parametrof programm: %d\n", argc);
		for (int i=0; i<argc; i++){
			printf ("Parametri %d: %s\n ", i, argv[i]);
		}
	}
	else {
		int j=0;
		while (envp[j]!=NULL){
			printf("Znahenie parametra %d: %s\n", j, envp[j]);
			j++;
	}
	}
	return 0;
}
