CC = cc
LEX = lex
YACC = yacc -d

lex.yy.c: scanner.l
	$(lex) scanner.l

scanner: lex.yy.c
	$(CC) lex.yy.c -ll -o scanner

y.tab.c: parser.y
	$(YACC) parser.y

parser: y.tab.c lex.yy.c symbol_table.c symbol_table.h
	$(CC) y.tab.c lex.yy.c symbol_table.c -ll -o parser

clean:
	rm -rf *.o
