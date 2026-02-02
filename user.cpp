#include <iostream>
#include <cstdlib>
#include <unistd.h>

using namespace std;

int main(int argc, char* argv[]) {
	if(argc != 2) {
		cerr << "Usage: " << argv[0] << " iterations\n";
		return 1;
	}

	int iterations = atoi(argv[1]);
	
	if (iterations < 0) {iterations = 0;

	}

	pid_t pid = getpid();
	pid_t ppdit = getppid();


	for (int i = 1; i <= iterations; i++) {
		cout << "USER PID:" << pid
		     << " PPID: " << ppid
		     << " Iteration: " << i
		     << "before sleeping\n";

		cout.flush();

		sleep(1);

		cout << "USER PID:" << pid
                  << " PPID:" << ppid
                  << " Iteration:" << i
                  << " after sleeping\n";
		cout.flush();
	}

	return 0;

}
