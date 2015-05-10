/**
* @author xkondr01 xkucha20
* @file hrac.cpp
* @brief Definice hrace a funkci s nim spojenych
*/
#include "labyrint.h"
#include "hrac.h"

Hrac::Hrac(){}

//Inicializace hrace
Hrac::Hrac(int cisloHrace, int velikost){
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
//Inicializace ulozeneho hrace
Hrac::Hrac(int pozicex, int pozicey, int spredmet, int sbody){
	x = pozicex;
	y = pozicey;
	predmet = spredmet;
	body = sbody;
}
//Navraceni poctu bodu hrace
int Hrac::pocet_bodu(){
	return body;
}
//Navraceni cisla hledaneho predmetu
int Hrac::hledany_predmet(){
	return predmet;
}
//Nastaveni predmetu hraci
void Hrac::nastav_predmet(int cislo){
	predmet = cislo;
}
//Nastaveni predmetu na hodnotu znacici, ze hrac muze jit do cile a koncit
void Hrac::nastav_konec(){
	predmet = KONEC;
}
//Pridani bodu hraci
void Hrac::pridej_bod(){
	body++;
}
//Odebrani bodu hraci pri kroku zpet
void Hrac::uber_bod(){
	body--;
}
//Vraceni pozice hrace
void Hrac::vrat_pozici(int *radek, int *sloupec){
	*radek = x;
	*sloupec = y;
}
//Pohyb hrace
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
//Zjisteni pritomnosti osoby na policku
bool Hrac::je_postava(int r, int s){
	if(x == r && y == s) return true;
	else return false;
}
// Ulozeni hrace do souboru
void Hrac::uloz(ofstream *soubor){
	*soubor << x << endl << y << endl << predmet << endl << body << endl;
}
