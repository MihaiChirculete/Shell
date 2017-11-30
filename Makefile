all:
	g++ main.cpp -o shell

run: all
	./shell

clean:
	rm shell