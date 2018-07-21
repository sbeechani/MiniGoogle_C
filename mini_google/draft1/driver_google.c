#include <stdio.h>
#include <dirent.h>
#include <project_google.h>

struct linkfreq
{
	char linkname [150];
	int wordfreq;
}

void main()
{
	DIR *d;
    struct dirent *dir;
    char path[100];
    char wordsearch [100];
    char links[20][100];
    int len;
    int i=0;
    struct linkfreq lf[20];
    int *li;

    printf("Enter Directory: ");
    scanf("%s",path);
    printf("\nEnter word to be searched: ");
    scanf("%s",wordsearch);
    d=opendir(path);
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {  
        int length = strlen(dir->d_name);
     	 if (strncmp(dir->d_name + length - 5, ".html", 5) == 0)
         { 
            if(strcmp("stop_words.txt",dir->d_name) && strcmp("logfile.txt",dir->d_name))
            {
                strcpy(links[i],dir->d_name);
                i++;
            }     	
        	
         }
     	}
	}

	//call fun in projgoogle, decide how to send that pointer,add all links in struct linkfreq one by one at the same time update it with its freq.else instead of 
	//using links directlt from dirent add to structure and run the loop till its size, which is pointer and gets updated constantly.

}