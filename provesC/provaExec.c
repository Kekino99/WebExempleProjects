#include <unistd.h>
#include <stdio.h>


int main() {
    execlp("ls", "ls", (char*) NULL);
    return -1;
}

