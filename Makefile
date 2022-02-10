CC = cl.exe
CFLAGS = /EHsc
RM = rm -rf
SHELL = cmd.exe
.PHONY = all clean test

all: urlparser.exe

urlparser.exe: urlparser.cpp
	$(CC) urlparser.cpp $(CFLAGS)

test:
	printf "https://example.com/some/path/to/file.txt" | urlparser.exe

clean:
	$(RM) urlparser.exe urlparser.obj
