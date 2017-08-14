![corewar](https://github.com/arodiono/corewar/blob/master/corewar.png)
### Project description

Create a virtual arena where programs written in a simple language fight one another. Explore the design of a VM (with the relevant instructions, records, etc.) and challenges related to compiling an assembly language in byte-code. As a bonus, you'll be able to enjoy programming your heroes to win the arena battles. Let the building begin and let the best hero win!

### What is Corewar?
* Corewar is a very peculiar game. It’s about bringing “players” together around a
“virtual machine”, which will load some “champions” who will fight against one another
with the support of “processes”, with the objective being for these champions
to stay “alive”.
* The processes are executed sequentially within the same virtual machine and memory
space. They can therefore, among other things, write and rewrite on top of
each others so to corrupt one another, force the others to execute instructions that
can damage them, try to rewrite on the go the coding equivalent of a Côtes du
Rhône 1982 (that is one delicious French wine!), etc...
* The game ends when all the processes are dead. The winner is the last player
reported to be “alive”.

#### allowed functions
* open
* read
* lseek
* write
* close
* malloc
* realloc
* free
* perror
* strerror
* exit
