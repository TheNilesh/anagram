#include<stdio.h>
#include<string.h>
#define SUCCESS 1
#define FAILURE 0
#define TRUE 1
#define FALSE 0

int checkIfAnagram(char *s1,char *s2);
int deleteChar(char a,char *s);
void xstrcpy(char *s1,char *s2);

int main(int argc,char *argv[])
{
	if(argc==3)
	{
		printf("String1 = %s\nString2 = %s\n",argv[1],argv[2]);
		if(strlen(argv[1])==strlen(argv[2]))
		{
			if(checkIfAnagram(argv[1],argv[2]))
				printf("They are anagrams.");
			else
				printf("They are not anagrams");
		}
		else
		{
			printf("Strings are not anagram since their length differs.");
		}
	}
	else
	{
		printf("Usage: %s <string1> <string2> ",argv[0]);
	}
printf("\n");
return 0;
}

int checkIfAnagram(char *s1,char *s2)
{
	for(;*s1!='\0';s1++)
	{
		if(deleteChar(*s1,s2)==SUCCESS)
			continue;
		//printf("%c not found in set 2",*s1);
		return FALSE;
	}
	return TRUE;
}

int deleteChar(char a,char *str)
{
//deletes given char from string
char *s=str;
	while(*s!='\0')
	{
		if(*s==a)
		{
			xstrcpy(s,s+1);
			return SUCCESS;
		}
		s++;
	}
	return FAILURE;
}
void xstrcpy(char *s1,char *s2)
{
//strcpy(s1,s2);
	while(*s2=='\0')
	{
		*s1=*s2;
		s1++;s2++;
	}
}