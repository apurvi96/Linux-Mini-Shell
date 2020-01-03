#ifndef PIPEHANDLE_h
#define PIPEHANDLE_h
#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>//getenv
#include<unistd.h>//gethostname getcwd
#include<sys/types.h> 
#include "global.h"
#include<cstring>
#include<sys/stat.h> 
#include<sys/wait.h> 
#include<cstdio>
#include<fcntl.h>
#include "BUILTIN.h"
#include "init_shell.h"
#include "BG_HANDLE.h"
#include<pwd.h>
#include <fstream>
#include <map> 
#include<algorithm>
#include <iterator> 


#define maxi 4096 
#define clearscre() printf("\033[H\033[J") 

using namespace std;

int Check_redirect(char **buffer, char **opfilep)
{
	int flag=0;

	for(int i=0;buffer[i]!=NULL;i++)
		{
			//cout<<"buffer value "<<i<<" "<<buffer[i]<<"\n";
			//char *check;
			//strcpy(check,buffer[i]);
				if(strcmp(buffer[i],">")==0 || strcmp(buffer[i],">>")==0)

				{
						if(strcmp(buffer[i],">")==0)
						{
							flag=1;
						}
						
						else
							flag=2;
			
					
							*opfilep=buffer[i+1];
							*(buffer+i)=NULL;


				}
		}

			return flag;

}


int Count_pipe(char **buffer)
{
	int flag=0;

	for(int i=0;buffer[i]!=NULL;i++)
		{
			
				if(strcmp(buffer[i],"|")==0)

				{
					flag++;

					if(buffer[i+1]==NULL)
						return -1;
				}
		}

	return flag;
}


void Parse_pipe(char *input, char **pipecommand)
{
		//cout<<input<<"check";
		int i=1;
		pipecommand[0]=strtok(input,"|");

		while((pipecommand[i] = strtok(NULL,"|")) != NULL)
		{
			//cout<<"enter\n";
    		i++;
		}

    	pipecommand[i]=NULL;
  }
  #endif