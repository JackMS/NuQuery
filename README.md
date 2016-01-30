# NuQuery
Rewriting Burn Query from the ground up.

Multitools are complicated, and so NuQuery is more of a toolbox.
Burn Query was meant to make things easier, and it did, 
but it's complicated to extend and not the cleanest code in the world
to start with. NuQuery solves that problem by being a collection
of specialised binaries managed by a bash script. Each binary
is a black box that performs it's function and is easy to modify,
while the bash script just pipes ls -1 | grep 'blah' options
around and massages the output a little for parsability.
This also opens the door to some fun extensions I considered
for Burn Query but dismissed as a pain in the ass to implement. 

This project is only just get started and so expect nothing useful
for a little while. Ie, the code found here should not be expected to 
work as intended, or even compile, until this readme says as much, and
even then that's no gaurantee of either.
