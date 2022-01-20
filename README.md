# Automatons
Implementations of an NFA and a PDA in the C++ programming languange.


These programs were written as assignments for my Theory of Computation classes.

They are by no means perfect implementations, there are much better ones out there in the internet. 
As a matter of fact, they are rather basic in the way they were structured and ultimately coded.

But anyway...

If you plan to use these codes for whatever purposes you may have, please note that there is
one strange bug with the NFA implementation. The automaton seems to work just fine but only
with the configuration provided in the input text file. The bug seems to be related to the
file handling. I never fixed it.

The PDA implementation works as intended. I reused the code from the NFA implementation 
and made some changes and additions to it. There is only one little detail. For the automaton
to work properly, there must always be one whitespace after the string in the input file.

Example:
ABC=(340%2)+(12-C;_ <------ Whitespace (illustrated with the "_" character)