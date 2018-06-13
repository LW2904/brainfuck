## brainfuck.c

Simple [brainfuck](http://www.muppetlabs.com/~breadbox/bf/) interpreter implemented in C.

[Portable Brainfuck](http://www.muppetlabs.com/~breadbox/bf/standards.html)-nice.

Reads the brainfuck to execute from a file that is passed as the first argument:

```bash
$ ./brainfuck code.txt
...
```

There are 9999 available cells, which is also the maximum allowed number of brainfuck symbols. All cells are `int`, so the size depends on your compiler and machine - although it is guaranteed to be able to hold -32767 to 32767.