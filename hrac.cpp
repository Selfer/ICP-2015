/**
*\author xkondr01 xkucha20
* @file hrac.cpp
* @brief Definice hrace a funkci s nim spojenych
*/
#include "labyrint.h"
#include "hrac.h"
/**
* Inicializace hrace
* @param cisloHrace cislo inicializovaneho hrace(int)
* @param velikost velikost herniho planu(int)
*/
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
/**
* Inicializace ulozeneho hrace
* @param pozicex x-ova pozice hrace(int)
* @param pozicey y-ova pozice hrace(int)
* @param spredmet cislo hracem hledaneho predmetu(int)
* @param sbody body hrace(int)
*/
void Hrac::inicializace_ulozena(int pozicex, int pozicey, int spredmet, int sbody){
	x = pozicex;
	y = pozicey;
	predmet = spredmet;
	body = sbody;
}
/**
* Navraceni poctu bodu hrace
* @return pocet bodu hrace(int)
*/
int Hrac::pocet_bodu(){
	return body;
}
/**
* Navraceni cisla hledaneho predmetu
* @return cislo hledaneho predmetu(int)
*/
int Hrac::hledany_predmet(){
	return predmet;
}
/**
* Nastaveni predmetu hraci
* @param cislo cislo hracem hledaneho predmetu(int)
*/
void Hrac::nastav_predmet(int cislo){
	predmet = cislo;
}
/**
* Nastaveni predmetu na hodnotu znacici, ze hrac muze jit do cile a koncit
*/
void Hrac::nastav_konec(){
	predmet = KONEC;
}
/**
* Pridani bodu hraci
*/
void Hrac::pridej_bod(){
	body++;
}
/**
* Odebrani bodu hraci pri kroku zpet
*/
void Hrac::uber_bod(){
	body--;
}
/**
* Vraceni pozice hrace
* @param radek radek, kde se hrac nachazi(int *)
* @param sloupec sloupec, kde se hrac nachazi(int *)
*/
void Hrac::vrat_pozici(int *radek, int *sloupec){
	*radek = x;
	*sloupec = y;
}
/**
* Pohyb hrace
* @param prikaz smer posunu hrace(char)
* @param velikost velikost herniho planu(int)
* @param presah hodnota indikujici presunuti hrace na druhou stranu herniho planu(bool)
*/
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
/**
* Zjisteni pritomnosti osoby na policku
* @param r radek herniho planu(int)
* @param s sloupec herniho planu (int)
* @return hodnota reprezentujici, zda je nebo neni na policku postava(bool)
*/
bool Hrac::je_postava(int r, int s){
	if(x == r && y == s) return true;
	else return false;
}
/**
* Ulozeni hrace do souboru
* @param soubor soubor, kam se herni plan ulozi(ofstream *)
*/
void Hrac::uloz(ofstream *soubor){
	*soubor << x << endl << y << endl << predmet << endl << body << endl;
}
