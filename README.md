# header_gen
header_gen is a tool to create and document header files from sources.

## Usage
```
hgen [OPTION...] <source1.c> <...> <sourceN.c> <header_name.h>
```
## Options
```
  -a, --append               Allows to create a new header file, from an
                             existing header file and .c source files.                       
```
Usage :
```bash
hgen -a [OPTION] <sources.c> <...> <sourceN.c> <existant_header_file.h> <header_name.h>
```
---
```
  -c, --count                Shows the number of prototypes put in the file.
```
---
```
  -f, --from                 Put above the prototype in the header file the
                             source file as a comment. If this option is used
                             with the -s option, the prototypes are sorted for
                             each source file.
```
```c
/*
** from src.c
*/
int fct(void);
int fct2(void);
...
```
---
```
  -s, --sort                 Sorts the different protypes in ASCII order.
```
---
```
  -v, --verbose              Print each prototypes create by hgen in std
                             output.
```
---
## Installation
```
make && mv ./hgen ~/.local/bin/
```
If the ~/.local/bin folder does not exist, create it with :
```bash
mkdir -p ~/.local/bin
```
and put the PATH in your .zshrc or .bashrc file.
### About the author
Student @ 42Paris.
### About the project
This project is a tool for creating headers. It has been programmed to help me during the realization of my school's projects.
It is possible that this project has bugs and malfunctions.
Please make a pull request or send me a mail at pbrochar@student.42.fr
### Version
0.1.0