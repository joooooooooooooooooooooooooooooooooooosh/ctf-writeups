# Flag

```
COMP6841{dynam1c_Link1ng_i5_fuN}
```

# Title

shimmy

# Description

I made a random number generator! Hope this doesn't get hijacked, if it was hijacked that could cause havoc on my random numbers..

# Files to give to participants

shimmy.c
shimmy

# Solve

1. Create a custom rand function that returns -5 in order to satisfy the impossible condition in main()
2. Compile this into a shared library with `gcc -shared -fpic <filename> -o shim.so`
3. Run `LD_PRELOAD=./shim.so ./shimmy` to execute `shimmy` with the new rand() function being linked and the flag will be printed for you

4. Alternatively, patch the binary back up so it can be loaded in a decompiler and reverse the flag printing algorithm
