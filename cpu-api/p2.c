#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	printf("(%d)Hello World\n", (int) getpid());

	int rc = fork();

	if (rc < 0) {
		fprintf(stderr, "For Failed\n");
		exit(1);
	} else if (rc == 0) {
		printf("(%d) I am child\n", (int) getpid());
		sleep(10);
	} else {
		int wc = wait(NULL);
		printf("(%d) I am parent of %d (wc:%d)\n", (int) getpid(), rc, wc);
	}
	// We will print integers from both processes.
	// the print statements should not be interleaved and child's print
	// should appear before the parent.
	for (int i = 0; i < 100; i++) {
		printf("(%d) - %d\n", (int) getpid(), i);
	}
	return 0;
}

