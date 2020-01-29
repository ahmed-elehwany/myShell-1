# myShell
Name: Muhammad Huzaifa Elahi

## OS
Ubuntu

## Instructions
`gcc -c shell.c interpreter.c shellmemory.c`

`gcc -o mysh shell.o interpreter.o shellmemory.o`

`./mysh`

## Operations
| Command (case sensitive)    |      Description                          |
|:----------------------------|:------------------------------------------|
| help 			                  | 	Displays all the commands               |
| quit 			                  |  Exits / terminates the shell with "Bye!" |
|	set VAR STRING 		        	|   Assigns a value to shell memory         |
|	print VAR 				          | Displays the STRING assigned to VAR       |
|	run SCRIPT.TXT 		         	|	Executes the file SCRIPT.TXT              |

## Assumptions
1. File recursion beyond a limit will cause an error to prevent memory overload
2. Running quit inside a script will exit the script, not the shell
