#	A Simple Implementation of an Interpreter for Monty ByteCode files

## Requirements
- Ubuntu 20.04
- gcc 9.3.0
- Valgrind memory checker

## Usage
```c
./monty <file>
```
``file`` is the path to file containing the monty bytecode

## Example
```c
taiwo@Taiwo-avangarde:~/monty$ cat bytecode_1.m
push 1
push 2
push 3
pall
taiwo@Taiwo-avangarde:~/monty$ ./monty
USAGE: monty file
taiwo@Taiwo-avangarde:~/monty$ ./monty bytecode_1.m
3
2
1
taiwo@Taiwo-avangarde:~/monty$
```
The above is a simple demonstration of how the program works.

## Tests
This program was compiled with gcc & tested with Ubuntu 20.04. 
see [here](https://github.com/Taiwopeter-babs/monty/tree/master/tests)

## Notes
Program was successfully compiled and no memory leaks were observed at runtime.


## Author(s)
- Taiwo Babalola <babalolataiwop@gmail.com>
