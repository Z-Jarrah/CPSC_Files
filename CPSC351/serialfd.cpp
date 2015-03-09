//The serial downloader shall download files one by one. After the parent process has read and
//parsed the urls.txt file, it shall proceed as follows:
//1. The parent process forks off a child process.
//2. The child uses execlp("/usr/bin/wget", "wget", <URL STRING1>, NULL) system call
//in order to replace its program with wget program that will download the first file in
//urls.txt (i.e. the file at URL <URL STRING1>).
//3. The parent executes a wait() system call until the child exits.
//4. The parent forks off another child process which downloads the next file specified in
//urls.txt.
//5. Repeat the same process until all files are downloaded.

#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    pid_t pid;
    pid = fork();
    if(pid == 0)
    {
        execlp("/usr/bin/wget", "wget","http://www.cisco.com/networkers/nw04/presos/docs/NMS-1N02.pdf", NULL);
    }
    else
        wait(NULL);
    return 0;
}
