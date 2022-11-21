
# Concepts
## Terminal
In Linux systems, the terminal (used as a placeholder for the terms "terminal" "console" and "shell". For the difference and proper use click [here](https://www.linuxbabe.com/command-line/linux-terminal)) is a way to communicate with your computer using commands. It has some build in commands and also packages bundled in your os for many uses. you can also install new packages or write your own programms.
To run a command you type the name of the command and hit enter. then you see the result on the terminal. To run a command not installed in your system [PATH](http://www.linfo.org/path_env_var.html)  you have to run it using the full path of the app (see [[#directories]] beloiw).

## directories
Directories = Folders.
there are also basic directories
. -> the current directory
.. -> the directory above
~-> the home directory
/ -> the root directory
	this is the start (root) of the filesystem. Everything else is a directory inside this directory. 
	This means deleting this or overwriting its content deletes EVERYTHING! (known meme is to make someone run `sudo rm -rf /`. We hope in the end you can figure out what this does ([dont try this !!)](https://youtu.be/D4fzInlyYQo))(more : [[#rm]] [[#switches]] [[#sudo]] [[#man]])

	

for example
let's say we are in a directory "folder2" inside a directory "folder1" inside  our home directory. lets say we are also the user kali, the default user of kali linux.
Then :
~ -> /home/kali 
.. -> ~/folder1 -> /home/kali/folder1
. -> ../folder2 -> /home/kali/folder1/folder2

So when we run something using ./command what we actually do is type the path of the file, and if it can be executed as a program it will run. See more about it in [[#permissions]] below. To run commands from every directory we have to add them in our[ PATH](http://www.linfo.org/path_env_var.html)

## permissions
there are 3 permissions:
r -> read (allows you to read the content of a file)
w -> write (allows you to change content of a file)
x -> execute (allows you to run the file as a program)
we can change permissions of a file using [[#chmod]]

## pipes and terminal operators
Pipes are used to redirect text (outputs from one command to another)
``|`` -> use output as input for another command 
``>>`` -> append output to file
``>`` -> send output to file 
`<` -> get input from file to file
```
> command1
out1

> command2 out1
out2

> command1 | command 2
out2

> command1
out1

> command1 >> file
> cat file
out1

> command2 < file
out2

```
 (more : [[#cat]])
Operators are used to run many commands in one line
`&` -> run commands in parallel
`;` -> run commands sequentially
`&&` -> run second if first succeeds
`||` -> run second if first fails

## hidden files
All files that start with . are hidden files


## switches
Are used as options for commands.
**Usually** start with a - if they are one letter and -- if they arewords
For example
`ls` -> shows content of file
`ls -a` -> shows content of file including hidden files
	same as `ls --all`
`ls -l` -> shows content of file in a list
`ls -la` -> shows content of file in a list including hidden files
You can find the options of a command using [[#man]]
 (more : [[#ls]])
## sudo 
Used to run commands as root (same as Administrator on windows).
for example 
```mkdir /new_dir``` (creates a new directory inside `/` (aka root) directory) fails. 
but 
```sudo mkdir /new_dir``` succeeds
(more : [[#mkdir]])

ctrl+c ctrl+shift+c ctr+shift+v
up arrow
tab



# Commands
## echo
prints given text to the terminal 
#### ...
```
> echo Hello World
Hello World
```
## pwd 
Print Working Directory. Shows the directory we are in.
##### ...
If we are for example in a  directory "folder1 " inside the home foder:
```
> pwd
/home/kali/folder1
```
## whoami
shows our user's name
#### ...
```
> whoami
kali
```
## ls
show  directory content
#### ...
Lets say we are in a directory like this
. 
	file2
	file2
	file3
	folder
		file3
		file4		
	
```
> ls
file1 file2 file3 folder

> ls folder 
file3 file4

```
## cd
moves us to a directory
#### ...
```
> ls
file1 file2 file3 folder

> cd folder 
> ls
file3 file4


```

## touch
creates a new file
#### ...
```
> ls
file1 file2 file3 folder

> touch new
> ls
file1 file2 file3 folder new


```
## mkdir
creates new directory
#### ...
```
> ls
file1 file2 file3 folder

> mkdir newdir
> ls
file1 file2 file3 folder newdir


```
## cp 
copies file to destination. (can also rename the copy)
#### ...
```
> ls
file1 file2 file3 folder
> ls folder
file4 

> cp file1 folder
> ls folder
> ls
file1 file2 file3 folder
file4 file1




> ls
file1 file2 file3 folder

> cp file1 file6
> ls
file1 file2 file3 folder file6

```
## mv
moves file to new destination (also used to rename)
#### ...
```
> ls
file1 file2 file3 folder
> ls folder
file4 

> mv file1 folder
> ls folder
> ls
file2 file3 folder
file4 file1




> ls
file1 file2 file3 folder

> mv file1 file6
> ls
file6 file2 file3 folder 

```

## rm
remove (delete) or directory
#### ...
```
> ls
file1 file2 file3 folder
> ls folder
file4 

> rm file1 

> ls
file2 file3 folder



> ls
file1 file2 file3 folder

> rm -r folder
> ls
file1 file2 file3 

```

## chmod
change [[#permissions]] of file
#### ...
you can use `-` to remove a permission or `+` to add a permission
for examlpe to add executable permission:
```
> ls
file1 file2 file3 folder profram
> ./program
zsh: permission denied: ./program

> chmod +x program
> ./program
/** success **/
```
## cat
shows inside of file
#### ...
```
> ls
file
> cat file
Lorem ipsum dolor sit amet consectetur adipisicing elit. Maxime mollitia,
molestiae quas vel sint commodi repudiandae consequuntur voluptatum laborum
numquam blanditiis harum quisquam eius sed odit fugiat iusto fuga praesentium
optio, eaque rerum! Provident similique accusantium nemo autem. Veritatis
obcaecati tenetur iure eius earum ut molestias architecto voluptate aliquam
nihil, eveniet aliquid culpa officia aut! Impedit sit sunt quaerat, odit,
tenetur error, harum nesciunt ipsum debitis quas aliquid. Reprehenderit,
quia. Quo neque error repudiandae fuga? Ipsa laudantium molestias eos 

```

## nano
simple text editor for the terminal
#### ...
```
> ls 
file
> nano file
*opens file in editor*
```
## diff
show difference of 2 files
#### ...
```
> ls
file1 file2
> cat file1
same
diff1
same
diff2
> cat file2
same
diff-1
same
diff-2
> diff file1 file2
 > diff1
 < diff-1
 ---
 > diff2
 < diff-2
```


## man
shows the "manual" of a command. Most commands also accept the switch `--help` or `-h` (see [[#switches]]), although for many `man` is more complete 
#### ...
```
> man ls
  
NAME  
      ls - list directory contents  
  
SYNOPSIS  
      ls [OPTION]... [FILE]...  
  
DESCRIPTION  
      List information about the FILEs (the current directory by default).  Sort entries alphabetically if none of -cftuvSUX nor --sort is specified.  
  
      Mandatory arguments to long options are mandatory for short options too.  
  
      -a, --all  
             do not ignore entries starting with .  
  
      -A, --almost-all  
             do not list implied . and ..  
  
      --author  
             with -l, print the author of each file  
  
      -b, --escape  
             print C-style escapes for nongraphic characters 
......
```

## apt
The package manager downloads packages
#### ...
```
> sudo apt install program
# =====----- 50% #
program installed successfully
```

## find
search a directory for files (exc by name)
#### ...
```
> ls 
file1 file2 folder
> ls folder 
file3 file4 file_i_look_for

> find . -name file_i_look_for
./folder/file_i_look_for
```

## grep
searches a file for a word/patern
#### ...
```
>ls
file
> cat file
apple
bread
milk
chocolate
milkshake

> grep milk file
milk
milkshake
```


## bonus comands: xdg-open and alias
### xdg-open
Opens file with default program( like double clicking).
It can also open directories in file explorer (if filegiven is a directory).

### alias
can map one command to another. 
#### 
```
> alias say="echo"
> say Hello World
Hello World
```

what i like to do is alias `xdg-open` to just `open` (`alias open="xdg-open"`)
	This way, `open image.png` opens image in image viewer  and `open file.py` opens it in a graphical editor (because **nano** *sucks* and **vim** is complecated for new users)
		Warning: this makes it work only for current terminal session. If you want to make aliases permanent ask me.
		



# Python
Python is a programming Language. To make a script (aka program) in python there are two ways:
- file
```
> nano script.py
/* edit *
> python script.py
Result
```
- interpreter
```
> python
>>>> //write commands here and enter to run
```
## Comments
```python
# this line doesnt run
```
## printing
To print something to the screen
```python
print("Hello World")
```
```
Hello World
```
## strings
Strings are basically text (aka a series of characters). To convert something like a number to a string you can use 2 methods:
- convert to a string and add to a string
	example:
```python
	i = 2 # this is a number
	my_str = "Two = " + str(i)
	print(my_str)
```
```
Two = 2
```
- Use String formatting (f before string and variable or expresion in brackets)
	example:
```python
i = 2
	my_str = f"Two = {i}"
	print(my_str)
```
```
Two = 2
```
## for loop
do something N times (giving a variable values from I to N)

```python
for variable in range(from, to, step):
# "step" defaults to 1 and "from" to 0. 
# to is not included
# needs tab to put code inside a loop
	do this

#example
for i in range(10):
	print(i)
print("Once")
```
```
0
1
2
3
4
5
6
7
8
9
Once
```

lists
files

# Other commands:
Other commands will be shown in the ful workshop, or in a possible extended guide to python, if time is not enough.

Also other specific commands will be shown during other workshops. You can learn more about python [here](https://www.w3schools.com/python/)