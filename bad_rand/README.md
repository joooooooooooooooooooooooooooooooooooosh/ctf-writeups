# Flag

```
COMP6841{but_i5_4nyth1ng_truLy_r4ndom?}
```

# Title

bad_rand

# Description

I made another random number generator! You can't hijack this one, it runs on a server! I also made sure to seed the random number generator on this one, so you get new numbers every time...

# Files to give to participants

vuln.c
vuln

# Solve

1. Create a script to launch two instances of the binary (or make two connections to the server for the remote version) simultaneously.
Since the generator is seeded with `time(NULL)`, this almost guarantees that they will have the same seed - and hence produce the same "random" numbers.
2. Enter 's' to get one instance to show the secret number, and enter that number into the second instance after using the 'g' option.

# Solve script
```python
#!/usr/bin/python3
import pwn

# might not work *every* time if you get unlucky with timing
# but consistent enough that it should work on the second go
p = pwn.process("./vuln")
q = pwn.process("./vuln")
# p = pwn.remote("CHALLENGE_IP", CHALLENGE_PORT)
# q = pwn.remote("CHALLENGE_IP", CHALLENGE_PORT)

p.sendline("s")
q.sendline("g")
p.recvlines(3)
secret = p.recvline()
q.sendline(secret)

q.recvuntil("secret? ")
print(q.recvall())
```
