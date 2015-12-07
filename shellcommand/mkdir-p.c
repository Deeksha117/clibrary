#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include <string.h>
#include <stdio.h>
#include<fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int i;
	char path[30],*temp="",*dest=argv[1];
	struct stat st = {0};
	for(i=0;i<strlen(dest);i++)
	{
	if(dest[i]=='/' && stat(path, &st) == -1) 
				{
    					mkdir(path, 0700);sprintf(path,"%s%c",temp,dest[i]);
				}
	else {	
		sprintf(path,"%s%c",temp,dest[i]);temp=path;}
	}
return 0;}
