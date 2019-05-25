all: clean
	flex scanner.lex
	bison -d --debug parser.ypp
	g++ -o hw3 *.c *.cpp
clean:
	rm -f lex.yy.c
	rm -f parser.tab.*pp
	rm -f hw3
	rm -f lexer.cpp
