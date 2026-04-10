default: build

build: clean
	gcc main.c -lcurl -o CLI_Printer
	./CLI_Printer

clean:
	rm -f CLI_Printer