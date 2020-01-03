#ifndef BG_HANDLE_h
#define BG_HANDLE_h
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
#include "PIPEHANDLE.h"
#include<pwd.h>
#include <fstream>
#include <map> 
#include<algorithm>
#include <iterator> 


#define maxi 4096 
#define clearscre() printf("\033[H\033[J") 

using namespace std;

int Check_bg(char **buffer)
 {
 	int bg=0;
 	int buffer_length=0;

		//FINDING BUFFER LENGTH
		for(int i=0;buffer[i]!=NULL;i++)
		{
			//cout<<" "<<buffer[i];
			buffer_length++;
		}

 	//CHECKING IF BACKGROUND COMMND if as LS &
		if(strcmp(buffer[buffer_length-1],"&")==0)
		{
			bg=1;
			buffer[buffer_length-1]=NULL;
			buffer_length--;
		}

		// if ls&
			char checkbg[1000];
			strcpy(checkbg,buffer[buffer_length-1]);
			int len =strlen(checkbg);

			if(checkbg[len-1]=='&')
			{
				bg=1;
				buffer[buffer_length-1][len-1]='\0';
			}

			return bg;
	
			//cout<<buffer[buffer_length-1]<<" ";

		//cout<<"background "<<bg<<"\n";

	
 }
 #endif