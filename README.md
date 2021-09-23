# INTERPRETER FOR MONTY BYTECODES FILES
The Monty language

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

```
  push 1
  push 2
  push 3
  pall
  push 5
  pint
  pop
  pstr
  pchar
  rotl
  rotr
  # This is a comment
```
## HOW USED IT ?
1. Clone this respository, inner `bytecodes` directory you can found files for test and enjoy it !
2. Compile with the next command: `$ gcc -Wall -Werror -Wextra -pedantic -std=c90 *.c -o monty`
3. Execute: `./monty <file_name.m>`

## COMMANDS

| Name       | Description                             |
| ---        | -----------                             |
| push <int> | add element(int) in the stack           |
| pall       | print all the stack                     |
| pint       | print the top item of the stack         | 
| pop        | remove the top item if the stack        |
| swap       | swaps the top two elements of the stack |
| add        | adds the top two elements of the stack  |
| nop        | It  doesn’t do anything                 |
| sub        | subtracts the top element of the stack from the second top element of the stack |
| div        | divides the second top element of the stack by the top element of the stack |
| mul        | multiplies the second top element of the stack with the top element of the stack |
| mod        |  computes the rest of the division of the second top element of the stack by the top element of the stack |
| #          | comments declaration |
| pchar      | prints the char at the top of the stack, followed by a new line |
| pstr       | prints the string starting at the top of the stack, followed by a new line |
| rotl       | rotates the stack to the top |
| rotr       |  rotates the stack to the bottom |
