OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11



program.exe: program.o Cjt_Idiomas.o Idioma.o Tree_Code.o
	g++ -o program.exe program.o Cjt_Idiomas.o Idioma.o Tree_Code.o

Tree_Code.o: Tree_Code.cc Tree_Code.hh
	g++ -c Tree_Code.cc $(OPCIONS)

Cjt_Idiomas.o: Cjt_Idiomas.cc Cjt_Idiomas.hh Idioma.hh
	g++ -c Cjt_Idiomas.cc $(OPCIONS)

Idioma.o: Idioma.cc Idioma.hh Tree_Code.hh
	g++ -c Idioma.cc $(OPCIONS)

program.o: program.cc Cjt_Idiomas.hh Tree_Code.hh Idioma.hh
	g++ -c program.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe
