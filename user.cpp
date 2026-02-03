#include <iostream>
#include <string>
#include <unistd.h>   // getpid, getppid, sleep

using namespace std;

static int parseIterations(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " iterations\n";
        return -1;
    }

    try {
        size_t pos = 0;
        int iters = stoi(argv[1], &pos);

        // Reject junk like "10abc"
        if (pos != string(argv[1]).size()) {
            cerr << "Error: iterations must be an integer.\n";
            return -1;
        }

        if (iters < 0) {
            cerr << "Error: iterations must be >= 0.\n";
            return -1;
        }

        return iters;
    } catch (...) {
        cerr << "Error: iterations must be an integer.\n";
        return -1;
    }
}

int main(int argc, char* argv[]) {
    int iterations = parseIterations(argc, argv);
    if (iterations < 0) return 1;

    pid_t pid = getpid();
    pid_t ppid = getppid();

    for (int i = 1; i <= iterations; i++) {
        cout << "USER PID:" << pid
             << " PPID:" << ppid
             << " Iteration:" << i
             << " before sleeping\n";
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

