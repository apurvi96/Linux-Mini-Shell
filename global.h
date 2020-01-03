#ifndef global_h
#define global_h
#include <map>
#include<string>

using namespace std;

char PATH[4096];
char *HOME;
char *USER;
int HSIZE=5;
char HOSTNAME[1024];
char PS1[1000];
char promptpath[1000];
char currdir[1024];
char SHELL_DIR[1000];
int exit_status_child;
int Shell_Pid;
map <string,string> Alias_map;
//void setvariables();
#endif
