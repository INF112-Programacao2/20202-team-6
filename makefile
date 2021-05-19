CC = g++
FLAGS = 

all:  exe.x
 
exe.x: Calculo_Analitico.cpp Calculo_Numerico.cpp Funcao.cpp Grafico.cpp gnuplot.cpp main.cpp
	$(CC) $(FLAGS) Calculo_Analitico.cpp Calculo_Numerico.cpp Funcao.cpp Grafico.cpp main.cpp gnuplot.cpp -o exe.x

clean:
	rm *.x	

