#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include "project_google.h"


/*This function accepts directory to search for links, path and word to be searched in links, wordsearch and displays links with that word in descending order
of its occurance in link*/

void main()
{
	DIR *d;
    struct dirent *dir;
    char path[100];
    char wordsearch [100];
    int len;
    int i=0,lin=0;
    struct linkfreq lf[20];
    int* li;
    li=&lin;
    printf("Enter Directory: ");
    scanf("%s",path);
    printf("\nEnter word to be searched: ");
    scanf("%s",wordsearch);
    d=opendir(path);
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {  
        int length = strlen(dir->d_name);//to get all files which ends with .html
     	 if (strncmp(dir->d_name + length - 5, ".html", 5) == 0)
         { 
               	strcpy(lf[*li].linkname,dir->d_name);
                lf[*li].depth=0;
                *li=*li+1;     	
         }

     	}
	}

	for(i=0;i<*li;i++) // to update each link with corresponding word frequency and also to extract additonal links inside these links if any
	{
		wordcount(lf[i].linkname,i,lf,li,wordsearch);
	}

	

	for(i=0;i<*li;i++) // to sort links in descending order based on word frequency
	{
		struct linkfreq temp;
		for(int j=i+1;j<*li;j++)
		{
			if(lf[i].wordfreq<lf[j].wordfreq)
			{
				temp=lf[i];
				lf[i]=lf[j];
				lf[j]=temp;
			}
		}
	}

		for(i=0;i<*li;i++) // displaying links with word frequency greater than 0
	{
		if(lf[i].wordfreq>0)
		{
			printf("%s\n",lf[i].linkname);
		}
		
	} 	


	
}