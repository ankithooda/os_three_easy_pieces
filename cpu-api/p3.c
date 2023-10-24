#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	printf("(pid:%d) Hello World\n", (int) getpid());

	int rc = fork();

	if (rc < 0) {
		fprintf(stderr, "Fork Failed.\n");
	} else if (rc == 0) {
		printf("(pid:%d) I am child process", (int) getpid());
		char *myargs[3];
		myargs[0] = strdup("wc");
		myargs[1] = strdup("p3.c");
		myargs[2] = NULL;
		
		execvp(myargs[0], myargs);
		printf("THIS WILL NOT PRINT\n");
	} else {
		int wc = wait(NULL);
		printf("(pid:%d) Parent process\n", (int) getpid());
	}
	return 0;
}
