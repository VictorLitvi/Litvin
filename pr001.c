#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
	 uid_t userid;
	gid_t groupid;
	pid_t procid, parentid;
	userid = getuid();
	groupid = getgid();
	procid = getpid();
	parentid = getppid();
	printf ("Ид. пользователь: %d\n" , userid);
	printf ("Ид. группы пользователя: %d\n",groupid);
	printf ("Ид. текущего процесса: %d\n",procid);
	printf ("Ид. родительского контроля: %d\n", parentid );
	return 0;
}
