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

	// We will print a lot of integers from both processes.
	// the print statements should be interleaved demonstrating the
	// OS scheduler.
	for (int i = 0; i < 100; i++) {
		printf("(%d) - %d\n", (int) getpid(), i);
	}
	return 0;
}
