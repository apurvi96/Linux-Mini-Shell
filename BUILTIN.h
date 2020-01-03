#ifndef BUILTIN_h
#define BUILTIN_h
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
#include<pwd.h>
#include <fstream>
#include <map> 
#include<algorithm>
#include <iterator> 


#define maxi 4096 
#define clearscre() printf("\033[H\033[J") 



using namespace std;


void execute_echo(char **buffer)
{
	//exit_status_child=0;
	//cout<<"enter exexc\n";
	string echout="";
	int flags=0;
	int flagd=0;
	int i=1;
	int k=0;
	if(buffer[1]==NULL)
	{
		//cout<<"enternhh\n";
		cout<<"\n";
		return;
	}

	if(buffer[1][0]=='$')
	{
		for(int m=1;buffer[1][m]!='\0';m++)
		{
			echout=echout+buffer[1][m];

		}

		if(echout=="PATH")
		{
			cout<<PATH<<"\n";
			exit_status_child=0;
			return;
		}

		else if(echout=="USER")
		{
			cout<<USER<<"\n";
			exit_status_child=0;
			return;
		}
		else if(echout=="HOME")
		{
			cout<<HOME<<"\n";
			exit_status_child=0;
			return;
		}
		
		else if(echout=="PS1")
		{
			cout<<PS1<<"\n";
			exit_status_child=0;
			return;
		}

		else if(echout=="$")
		{
			pid_t pids=getpid();
			exit_status_child=0;
			cout<<pids<<"\n";
			return;
		}

		else if(echout=="?")
		{
			
			cout<<exit_status_child<<"\n";
			exit_status_child=0;
			return;
		}

		

	}

	echout="";

	while(buffer[i]!=NULL)
	{
		//cout<<"enter\n";
		if(strcmp(buffer[i],"\"")==0)
		{
			if(flagd==0)
			flagd=1;

			else
				flagd=0;
			i++;
			continue;
		}

		else if(strcmp(buffer[i],"\'")==0)
		{
			if(flags==0)
			flags=1;

			else
				flags==0;
				i++;
				continue;
	    }

		for(k=0;buffer[i][k]!='\0';k++)
		{
			if(buffer[i][k]=='\"')
			{
				if(flagd==0)
			flagd=1;

			else
				flagd=0;
			
			continue;
			}

			if(buffer[i][k]=='\'')
			{
				if(flags==0)
			flags=1;

			else
				flags=0;
			
			continue;
			}

			echout=echout+buffer[i][k];


		}

		echout=echout+" ";


		i++;

	}

	if(flagd==0 &&  flags==0)
	{
		cout<<echout<<"\n";
		exit_status_child=0;
	}

	else
	{
		cout<<"QUOTE MISMATCH\n";
		exit_status_child=-1;



	}

}

#endif