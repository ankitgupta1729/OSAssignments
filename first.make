all: clean build
build: gcc test.c -o execc
clean: rm execc  