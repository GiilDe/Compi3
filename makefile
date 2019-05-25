all: clean
	flex scanner.lex
	bison -d --debug parser.ypp
	g++ -std=c++11 -g -o hw3 *.c *.cpp
clean:
	rm -f lex.yy.c
	rm -f parser.tab.*pp
	rm -f hw3
	rm -f lexer.cpp
