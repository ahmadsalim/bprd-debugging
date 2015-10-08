# BPRD 2015 Debugging Tutorial and Exercise

## Tracing Macros

The file [trace.h](trace.h) provides three useful tracing macros `TRACE_ERROR`, `TRACE_WARNING` and `TRACE_INFO`.
Each of these macros take a format string as first argument, and the data to print as subsequent arguments similar to the *printf functions in C.

To use these macros in your own project, simply #include the [trace.h](trace.h) file in your C file and then call them like you would call ordinary C functions, for example:

```{c}
TRACE_ERROR("Unexpected argc: %d", argc);
```

The level of tracing output is configurable on compile-time and will per default only show errors.
If you want to increase the trace level, simply provide the `-DTRACE_LEVEL=level` argument to your compiler where _level_ is the level of output desired; for example, `gcc -DTRACE_LEVEL=3 -o example.out example.c -lm` will print trace.

The different trace levels are shown in the followin table:

| TRACE_LEVEL | Shown                  |
|:-----------:|:----------------------:|
| < 0         | Nothing                |
| 0           | Errors                 |
| 1           | Errors and Warnings    |
| &geq; 2     | Everything             |

## Debugging Guide and Commands

In order to use the debugger optimally, you have to compile your program by adding the `-g` flag.
For example, if we are compiling the file `example.c` we can issue the following command `gcc -Wall -g -o example.out example.c -lm` (or similar with clang, msvc, icc, etc.).

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

## Facebook Infer tool

Static analysis tools are also useful for finding bugs, and a particularly interesting static analysis tool is [infer](http://fbinfer.com) by Facebook.
The [documentation](http://fbinfer.com/docs/getting-started.html) is excellent, so if you are interested just visit the site to know how to install and use the tool.

