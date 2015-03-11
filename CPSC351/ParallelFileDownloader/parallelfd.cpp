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
    int numOfUrls = 0;
    ifstream inFile;
    pid_t pid;
    
    inFile.open("URLS for Assignment - 1.txt");
    if(!inFile.is_open())
    {
        cout << "Failed to open file!\n";
    }
    
    while(!inFile.eof())
    {
        inFile >> url;
        ++numOfUrls;
        pid = fork();
   
        if(pid == 0) /* Child process*/
        {
            execlp("/usr/bin/wget", "child",url , NULL);
        }
    }
    
    for(int i = 0; i < numOfUrls; i++)
    {
        wait(NULL);
    }
        
    return 0;
}



