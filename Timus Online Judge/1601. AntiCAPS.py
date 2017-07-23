// The solution of the problem was written by Izaron
// Date: 16:49:43   29 Apr 2015
// Execution time: 0.062

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

from sys import stdin
from sys import stdout
upper = True
while (True):
    char = stdin.read(1)
    if (not char):
        break;
    elif (65 <= ord(char) <= 90):
        if (upper):
            upper = False
            stdout.write(char)
        else:
            stdout.write(char.lower())
    else:
        stdout.write(char)
        if (char == "." or char == "!" or char == "?"):
            upper = True