#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct words
{
	char word[100];
};

struct linkfreq
{
	char linkname [150];
	int wordfreq;
	int depth;
};

void get_words(struct words w[],FILE *f,int count)
{
	for (int i=0;i<count;i++)
	{
		fscanf(f,"%s",w[i].word);
	}
}

void get_links(struct words w[], int i, struct linkfreq l[], int *li)
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
				strcpy(l[*li].linkname,linky);
				*li=*li+1;

				}
				j++;
			}
}

void filter_words(struct words w[],struct linkfreq l[],int count, int *li,int ln)
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
								if(l[ln].depth<10)
								{
									l[*li].depth=l[ln].depth+1;
									get_links(w,i,l,li);
								}
								
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
	
	

	void get_freq (char wordsearch[], int i, struct linkfreq lf[],struct words w[],int count)
	{
		lf[i].wordfreq=0;
		for(int j=0; j<count;j++)
		{
			if((strcmp(wordsearch,w[j].word))==0)
			{
				lf[i].wordfreq=lf[i].wordfreq+1;
			}
		}

	}

void wordcount(char name[],int ln,struct linkfreq lf[], int *li,char wordsearch[])
{
	struct words *warr;
	char c;
	int i=0;
	int count = 0;
	FILE *html;
	html = fopen(name,"r");
	fseek(html,0,SEEK_SET);

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
	filter_words(warr,lf,count,li,ln);
	get_freq(wordsearch,ln,lf,warr,count);

	
}