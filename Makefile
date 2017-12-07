all:
	g++ main.cpp -o out/shell

run: all
	./out/shell

clean:
	rm out/shell