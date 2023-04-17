environment: environment.c
	gcc environment.c -o enviro

execThing: execThing.c
	gcc execThing.c -o executeOther

fseekThing: fseekThing.c
	gcc fseekThing.c -o fseeking

lseekThing: lseekThing.c
	gcc lseekThing.c -o lseeking

namedFIFOreader: namedFIFOreader.c
	gcc namedFIFOreader.c -o fifoR

namedFIFOwriter: namedFIFOwriter.c
	gcc namedFIFOwriter.c -o fifoW

pipes: pipes.c
	gcc pipes.c -o pipes

sharedMem: sharedMem.c
	gcc sharedMem.c -o mem

signalHandling: signalHandling.c
	gcc signalHandling.c -o signals

subreaping: subreaping.c
	gcc subreaping -o subreaping

variadic: variadic.c
	gcc variadic.c -o variadic