//Parallel Downloader
//1. The parent forks off n children, where n is the number of URLs in urls.txt.
//2. Each child executes execlp("/usr/bin/wget", "wget", <URL STRING>, NULL) system
//call where each <URL STRING> is a distinct URL in urls.txt.
//3. The parent calls wait() (n times in a row) and waits for all children to terminate.
//4. The parent exits.
//while the parallel downloader executes, the outputs from different children may
//intermingle. This is acceptable.

#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
    char url[250];
    ifstream inFile;
    pid_t pid;
    
    inFile.open("URLS for Assignment - 1.txt");
    if(!inFile.is_open())
    {
        cout << "Failed to open file!\n";
    }
    
    //fork off 7 times because there are 7 urls
    //typing pid = fork(); 7 times doesn't work
    //Are the processes colliding while accessing the file? How do I manage it?
    pid = fork(); 
    pid = fork();
    if(pid == 0) /* Child process*/
    {
        inFile >> url;
        execlp("/usr/bin/wget", "wget",url , NULL);
    }
    wait(NULL);
        
    return 0;
}
