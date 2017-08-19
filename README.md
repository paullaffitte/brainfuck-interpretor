# Brainfuck Interpretor
A interpretor for brainfuck code

## Compilation
To compile the source code, you just need gcc and make. If you don't have them, you can install it by the following.
```sh
sudo apt install gcc make
```
Then, make will do the job.
```sh
make
```

## Usage
The compilation will generate a executable named bfi. His usage is very simple, you just have to give the name of the script that you want to execute, and bfi will gives you the result.
```sh
./bfi scripts/hello_world_loops.bf 
```
There are some samples of brainfuck that you can try in the scripts repertory.

## Warning
The code was written on Ubuntu 16.04 and I can't tell you that it will work on any linux distribution.
Some bugs can still be there, I wrote this interpretor in a small amount of time for fun, without testing all his features. So if you found bugs, it would be appreciated if you report them in the [issues section](https://github.com/paullaffitte/brainfuck-interpretor/issues). You can also fork the project to add new features.
