#include "hrac.h"
#include "labyrint.h"
//definice hrace
void Hrac::inicializace(int cisloHrace, int velikost){
	switch(cisloHrace){
		case 0:
			x = 0;
			y = 0;
			break;
		case 1:
			x = velikost-1;
			y = velikost-1;
			break;
		case 2:
			x = 0;
			y = velikost-1;
			break;
		case 3:
			x = velikost-1;
			y = 0;
			break;
		default:
			cerr << "CHYBA" << endl;
	}
	body = 0;
}
//vrati pocet bodu
int Hrac::pocet_bodu(){
	return body;
}
//vrati cislo hledaneho predmetu
int Hrac::hledany_predmet(){
	return predmet;
}
//nastavi predmet podle cisla
void Hrac::nastav_predmet(int cislo){
	predmet = cislo;
}
//nastavi predmet na hornotu, ktera znaci, ze hrac muze koncit
void Hrac::nastav_konec(){
	predmet = KONEC;
}
//prida bod po nalezenem predmetu
void Hrac::pridej_bod(){
	body++;
}
//vrati pozici hrace
void Hrac::vrat_pozici(int *radek, int *sloupec){
	*radek = x;
	*sloupec = y;
}
//pohne s hracem
void Hrac::pohyb(char prikaz, int velikost, bool presah){
	if(prikaz == 'd'){
		if(presah == true && x == velikost-1) x = 0;
		else x++;
	}
	else if(prikaz == 'n'){
		if(presah == true && x == 0) x = velikost - 1;
		else x--;
	}
	else if(prikaz == 'p'){
		if(presah == true && y == velikost-1) y = 0;
		else y++;
	}
	else if(prikaz == 'l'){
		if(presah == true && y == 0) y = velikost - 1;
		else y--;
	}
}
//zjisti, zda je na policku postava
bool Hrac::je_postava(int r, int s){
	if(x == r && y == s) return true;
	else return false;
}
