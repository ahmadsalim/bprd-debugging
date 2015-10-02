# BPRD 2015 Debugging Tutorial and Exercise

## Debugging Guide and Commands

In order to use the debugger optimally, you have to compile your program by adding the `-g` flag.
For example, if we are compiling the file `example.c` we can issue the following command `gcc -Wall -g -o example.out example.c` (or similar with clang, msvc, icc, etc.).

To debug your program you run it as usual, except you add `gdb` or `lldb` to the start, e.g., `gdb ./example.out'.
This will get you into the debugging shell where something similar to the following will be shown:

```
(gdb)>
```

Then you can issue the debugging commands you want to use to debug your programs.
The table below has a summary of the most useful/common commands you want to use.


| Command                 | Description                                             |
|:------------------------|:--------------------------------------------------------|
| __help__                | Displays the available commands and how to use them     |
| __run__                 | Runs the program until next breakpoint or completion    |
| __b__ listmachine.c:264 | Inserts a breakpoint at line 264 in file listmachine.c  |
| __b__ _mark_            | Inserts a breakpoint at function _mark_                 |
| __s__                   | Steps into next line                                    |
| __n__                   | Steps over next line                                    |
| __finish__              | Step out of frame                                       |
| __bt__                  | Shows backtrace of program                              |
| __p__ _var_             | Prints value of variable _var_                          |
| __exit__                | Exits the debugger                                      |
