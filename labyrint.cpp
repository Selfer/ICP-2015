/*
 * Soubor:  labyrint.cpp
 * Datum:   6.5.2015
 * Autori:  Martin Kondr, Ondrej Kuchar
 * Projekt: ICP - Labyrint
 * Popis:   Program realizuje hru labyrint
 */
#include "labyrint.h"
#include "hrac.h"
#include "herni_plan.h"

int main(int argc, char *argv[]) {
	int velikost = VELIKOST;
	int pocetHracu = 2;
	//vylosovani zacinajiciho hrace
	int hracNaTahu = rand() % pocetHracu;
	int vyhral = 0;
	bool posunuto = false;
	string prikaz;
	string posunuti;
	HerniPlan plan(velikost);
	Hrac hrac[pocetHracu];
	for(int i = 0; i < pocetHracu; i++){
		hrac[i].inicializace(i, velikost);
		plan.prirad_predmet(&hrac[i]);
	}
	cout << "Na tahu je hrac cislo: " << hracNaTahu+1 << endl;
	plan.vypis(hrac, pocetHracu);
	//herni cyklus
	while(1){
		cout << "Prikaz: ";
		cin >> prikaz;
		plan.cista_obrazovka();
		//ukonci hru
		if(prikaz == "konec"){
			break;
		}
		//ukaze hraci hledany predmet
		else if(prikaz == "predmet"){
			cout << "Na tahu je hrac cislo: " << hracNaTahu+1 << endl;
			plan.vypis(hrac, pocetHracu);
			if(hrac[hracNaTahu].hledany_predmet() == -2) cout << "Vrat se na zacatek" << endl;
			else cout << "Hledas: " << plan.herni_predmety(hrac[hracNaTahu].hledany_predmet()) << endl;
			continue;
		}
		
		if(posunuto == false){
			//otoci volnym polickem
			if(prikaz == "otoc"){
				plan.otoc();
			}
			//vlozi policko
			else if(prikaz.length() == 1){
				posunuto = plan.posun(prikaz, hrac, pocetHracu);
				if(posunuto == false) 
					cout << "Nelze vsunout policko na tohle misto" << endl;
			}
			else cout << "Nejprve vloz volne policko" << endl;
		}
		else{
			//preda hru dalsimu hraci
			if(prikaz == "dalsi"){
				if(hracNaTahu == pocetHracu-1) hracNaTahu = 0;
				else hracNaTahu++; 
				posunuto = false;
			}
			//posune hracem
			else if(prikaz[0] == 'd' || prikaz[0] == 'n' || prikaz[0] == 'p' || prikaz[0] == 'l'){
				vyhral = plan.pohyb_hrace(prikaz, velikost, &hrac[hracNaTahu], hracNaTahu);
			}
			else cout << "Neplatny prikaz" << endl;
		}
		cout << "Na tahu je hrac cislo: " << hracNaTahu+1 << endl;
		plan.vypis(hrac, pocetHracu);
		if(vyhral > 0) {
			cout << "Vyhral hrac " << vyhral << endl;
			break;
		}
	}
	return 0;
}
