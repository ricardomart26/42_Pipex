# Pipex Overview #

Pipex is a command-line program that allows the user to redirect the output of one command to the input of another command, similar to the pipe (|) operator in Unix shell. It is a project for the 42 school curriculum, implemented in C language.

## Installation ##

To install Pipex, clone this repository and compile the program using the Makefile provided:

```shell

git clone git@github.com:ricardomart26/42_Pipex.git
cd 42_Pipex
make

```

This will generate the pipex executable in the same directory.

## Usage ##

Pipex takes in four arguments:

``` shell

$ ./pipex infile cmd1 cmd2 outfile

```

    infile: the input file to be processed
    cmd1: the first command to be executed
    cmd2: the second command to be executed
    outfile: the output file to be created

The program will take the contents of infile, execute cmd1 with the contents as input, and then execute cmd2 with the output of cmd1 as input, finally writing the result to outfile.

For example, the following command will execute the cat command with the contents of infile, and then execute the grep command with the output of cat as input, finally writing the result to outfile:

```shell

./pipex infile "cat" "grep word" outfile

```

is equivalent to:

```shell

$ < infile cmd1 | cmd2 > outfile

```
