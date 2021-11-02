all:  project1

project0: project1.c
	cc project1.c -o project1
clean:
	rm -f project1
