CC=g++
CFLAGS=-std=c++11 -Wall

all: main

Funcao.o: Funcao.h Funcao.cpp
	$(CC) ${CFLAGS} -c Funcao.cpp

Calculo_Analitico.o: Calculo_Analitico.h Calculo_Analitico.cpp
	$(CC) ${CFLAGS} -c Calculo_Analitico.cpp

Calculo_Numerico.o: Calculo_Numerico.h Calculo_Numerico.cpp
	$(CC) ${CFLAGS} -c Calculo_Numerico.cpp

Grafico.o: Grafico.h Grafico.cpp
	$(CC) ${CFLAGS} -c Grafico.cpp

gnuplot.o: gnuplot.h gnuplot.cpp
	$(CC) ${CFLAGS} -c gnuplot.cpp

main.o: Funcao.h Calculo_Analitico.h Calculo_Numerico.h Grafico.h gnuplot.h main.cpp
	$(CC) ${CFLAGS} -c main.cpp		

main: main.o Funcao.o Calculo_Analitico.o Calculo_Numerico.o  Grafico.o gnuplot.o
	$(CC) ${CFLAGS} -o main main.o Funcao.o Calculo_Analitico.o Calculo_Numerico.o Grafico.o gnuplot.o

clean:
	rm -f main *.o