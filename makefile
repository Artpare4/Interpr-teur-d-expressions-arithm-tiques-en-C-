a.out: main.o Noeud.o Expression.o PileReel.o PileChar.o NoeudReel.o FileExpression.o NoeudExpression.o
	g++ -std=c++11 main.o  Noeud.o Expression.o PileReel.o PileChar.o NoeudReel.o FileExpression.o NoeudExpression.o

main.o: PileChar.h PileReel.h Noeud.h NoeudReel.h Expression.h  main.cpp FileExpression.h NoeudExpression.h
	g++ -std=c++11 -c main.cpp


FileExpression.o: FileExpression.h FileExpression.cc
	g++ -std=c++11 -c FileExpression.cc


PileReel.o: PileReel.h PileReel.cc
	g++ -std=c++11 -c PileReel.cc

PileChar.o: PileChar.h PileChar.cc
		g++ -std=c++11 -c PileChar.cc

NoeudExpression.o: NoeudExpression.h NoeudExpression.cc
		g++ -std=c++11 -c NoeudExpression.cc

Expression.o: Expression.h Expression.cc
	g++ -std=c++11 -c Expression.cc

NoeudReel.o: NoeudReel.h NoeudReel.cc
		g++ -std=c++11 -c NoeudReel.cc

Noeud.o: Noeud.h Noeud.cc
	g++ -std=c++11 -c Noeud.cc

