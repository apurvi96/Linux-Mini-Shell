# <h2>Linux-Mini-Shell</h2>
POSIX compatible shell with a subset of feature support of default linux shell executing all the basic commands such as ls,echo,cat etc. Apart from basic working
other features are also implemented.

# <h2>Compile and Run Code</h2>
g++ -o shell Shell.cpp<br/>
./shell

# <h2>Features</h2>
<ul>
<li> Builtin shell commands supported. eg: cat, pwd, ls, echo, clear..</li>
<li>IO redirection with ‘>>’ and ‘>’ done for one source and
one destination.</li>
<li>Multiple Pipe Support Eg: cat file1.txt| sort | uniq > save.txt</li>
<li>Maintain a configuration file(Myrc.txt) which program reads
on startup and sets the environment accordingly.</li>
<li>Support for Environment variables such as PATH, HOME, USER, HOSTNAME, PS1 provided.</li>
<li>Auto Tab Completion for Directory/file names.</br>Write command cd/cat some characters of file/directory name and press tab.</li>
<li>OPEN COMMAND: Maps with extension of given file(.pdf,.jpeg,.mp3 etc) and uses default application(set via myrc.txt) to access it.</li>
<li>Alias support for commands. E.g. alias ll='ls -l'.</li>
<li>HISTORY COMMAND: History.txt maintains a list of all commands executed ever(even after one uses 'exit' shell). This can have a cap limit which can be configured via “myrc.txt” file in HISTSIZE variable.
  Write some characters of previous command and press ctrl+r for auto completion.</li>
<li>Singnal Handling to disable ctrl+Z,ctrl+x.Use 'exit' to exit code.</li>
<li>Handle support for - $$, $? Similar to shell, Association of ~ with HOME variable.</li>

</ul>
