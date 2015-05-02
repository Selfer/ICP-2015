#
# Soubor:  Makefile
# Datum:   5.5.2015
# Autor:   Martin Kondr, Ondrej Kuchar
#
all: labyrint

labyrint:
	g++ labyrint.cpp hrac.cpp herni_plan.cpp -o labyrint

clean:
	rm labyrint
