all:
	mkdir -p out/
	g++ main.cpp -o out/shell -lreadline

run: all
	./out/shell

clean:
	rm out/shell