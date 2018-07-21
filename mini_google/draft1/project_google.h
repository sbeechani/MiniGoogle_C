#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct words
{
	char word[100];
};

struct links
{
	char link[200];
};


void get_words(struct words w[],FILE *f,int count)
{
	for (int i=0;i<count;i++)
	{
		fscanf(f,"%s",w[i].word);
	}
}

void get_links(struct words w[], int i, struct links l[], int *li)
{
		char linky[100];
			int j=0;
			int k=0;
			int len= strlen(w[i].word);
			while(j<len)
			{
				if(w[i].word[j]=='"')
				{
						j++;
						while(w[i].word[j]!='"')
						{
								linky[k]=w[i].word[j];
								k++;
								j++;
						}
						linky[k]='\0';
				strcpy(l[li].link,linky);
				*li++;

				}
				j++;
			}
}

void filter_words(struct words w[],struct links l[],int count, int *li)
{
	int i=0;
	int k=0;
	while(i<count)
	{

		while((strcmp(w[i].word,"<body>")!=0))
			{
				if(i>=count)
				{
					break;
				}
				
				w[i].word[0]='\0';
				
				i++;
	
			}
		if(i>=count)
				{
					break;
				}

			
			if((strcmp(w[i].word,"<body>")==0))
			{
				w[i].word[0]='\0';
				i++;

				while((strcmp(w[i].word,"</body>"))!=0)
						{
							if(w[i].word[0]=='<')
							{
								w[i].word[0]='\0';
							}

							if(w[i].word[0]=='h' && w[i].word[1]=='r' && w[i].word[2]=='e' && w[i].word[3]=='f')
							{
								get_links(w,i,l,li);
								w[i].word[0]='\0';
							}
						
						i++;
						}
			}
					if(w[i].word[0]=='<')
							{
								w[i].word[0]='\0';
							}
							i++;
			if(i>=count)
				{
					break;
				}
	
		}
	}
	
	int get_wordfreq(struct words w[], char wordsearch[100],int count)
	{
			int res=0;
			int i=0;
			for(i;i<count;i++)
			{
				if(strcmp(w[i].word,wordsearch)==0)
				{
					res++;
				}
			}

			return res;
	}


int wordcount(FILE *html,Struct links l[], int *li)
{
	struct words *warr;
	char c;
	int i=0;
	int count = 0;
	int res;


	// ***************** to count number of words
	while((c=fgetc(html))!=EOF)
	{
		if(c=='\n' || c== ' ')
		{
			count++;
		}
	}
	count++;//for last word


	warr = malloc(count*sizeof(struct words));
	fseek(html,0,SEEK_SET);

	get_words(warr,html,count);
	filter_words(warr,l,count);
	res=get_wordfreq(warr,wordsearch,count);

	return res;
}