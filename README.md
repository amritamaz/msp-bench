#msp-bench
## benchmarks for msp430 beginners

Getting started with the MSP430 can be confusing. Trying to do the right 
thing and work with the modern msp430-elf-gcc, rather than the well-supported-but-outmoded
mspgcc, makes this harder. msp-bench can help.

## what you get
+ benchmarks
	- blank - literally nothing but print statements
	- math - super simple math
	- FIR filter - TI says this "intense math operation" tests "multiply-and-accumulate" operations
	- Dhrystone - pointer, structures, and string manipulation
	- Whetstone - integer and floating point math (this code is SUPER awkward)
+ handy-dandy makefile

## what you need to do
1. make sure you have a working build of msp430-elf-gcc. ([see here](http://amritamaz.me/blog/modern-clueless-msp430gcc/) if you don't).
2. set your msp430 model and msp430-library path in the Makefile
3. `make` should do it!

## simulation in mspdebug
+ if you want to test this code out in mspdebug's sim mode, set your msp430 model to f1611. 