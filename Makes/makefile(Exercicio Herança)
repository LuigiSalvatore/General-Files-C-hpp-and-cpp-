EXERCICIO = app
CFLAGS = -c -std=c++11 #-DDEBUG

all:			${EXERCICIO}

${EXERCICIO}:	Exercicio003.o Equipe.o Clube.o
	g++ -o ${EXERCICIO} Exercicio003.o Equipe.o Clube.o
	
Exercicio003.o:		Exercicio003.cpp Equipe.cpp Equipe.hpp
	g++ ${CFLAGS} Exercicio003.cpp

Equipe.o:			Equipe.cpp Equipe.hpp Clube.cpp Clube.hpp		
	g++ ${CFLAGS} Equipe.cpp

Clube.o:			Clube.cpp Clube.hpp 
	g++ ${CFLAGS} Clube.cpp

run:			${EXERCICIO} 
	./${EXERCICIO}

clean: 			
	rm -f Exercicio003.o Equipe.o Clube.o ${EXERCICIO}