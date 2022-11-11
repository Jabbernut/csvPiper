# csvPiper

csvPiper is a cli tool suite for bash that processes csv files. It's intended use is mostly 
for easy csv processing over the command line or an ssh client. That is achieved by building 
composite commands that are reminiscent of relational algebra operations and matrix maths.

Every command is one very simple operation that can only do one thing. Compound expressions
and processing is done with the io redirection tools that are native to bash. Every command
reads from stdin and writes to stdout. Io redirection redirection makes the tools able to do
more complex things such as compound expressions and writing the results of these expressions
to other places than stdout.

This project is mostly intended to be coded in C++ but any compiled language can be used 
provided that most end users has the compiler for said language.

The way the end user will tweak the settings is by running a command that recompiles 
every tool with a new header file. That's why it's important for most end users to have 
the compiler for every used language.

The tool will by default conform to rfc4180 and it's intended to match the end users 
character encoding and locale.
