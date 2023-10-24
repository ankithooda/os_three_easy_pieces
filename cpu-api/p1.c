#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	printf("Hello World (pid:%d)\n", (int) getpid());
	int rc = fork();
	if (rc < 0) {
		// Error in forking
		fprintf(stderr, "Fork failed\n");
		exit(1);
	} else if (rc == 0) {
		// New Process
		printf("Hello, I am a child process (pid:%d)\n", (int) getpid());
	} else {
		// Original Process

		printf("Hello, I am the parent process of %d (pid:%d)\n", rc, (int) getpid());
	}
	return 0;
}
