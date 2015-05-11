#
# Soubor:  Makefile
# Datum:   5.5.2015
# Autor:   Martin Kondr, Ondrej Kuchar
#
all: labyrint

labyrint:
	cd src && g++ labyrint.cpp hrac.cpp herni_plan.cpp -o labyrinth

run:
	cd src && ./labyrinth

gui:
	cd src/gui && qmake -o labyrinth

rungui:
	cd src/gui && ./labyrinth

clean:
	cd src && rm labyrinth
