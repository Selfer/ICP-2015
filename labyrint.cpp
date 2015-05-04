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
	int pocetHracu = 4;
	//vylosovani zacinajiciho hrace
	int hracNaTahu = rand() % pocetHracu;
	int vyhral = 0;
	bool posunuto = false;
	string prikaz;
	string posunuti;
	HerniPlan plan;
	plan.inicializace(velikost);
	Hrac hrac[pocetHracu];
	stack<string> historie;
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
		//ulozi hru
		else if(prikaz == "uloz"){
			ofstream soubor;
			soubor.open("ulozena_hra.txt", ios::out);
			soubor << pocetHracu << endl << hracNaTahu << endl;
			for(int i = 0; i < pocetHracu; i++){
				hrac[i].uloz(&soubor);
			}
			plan.uloz(&soubor);
			soubor.close();
		}
		else if(prikaz == "nacti"){
			ifstream soubor;
			soubor.open("ulozena_hra.txt", ios::in);
			soubor >> pocetHracu >> hracNaTahu;
			//nastaveni hracu
			for(int i = 0; i < pocetHracu; i++){
				int x,y,predmet,body;
				soubor >> x >> y >> predmet >> body;
				hrac[i].inicializace_ulozena(x,y,predmet,body);
			}
			int vel;
			string vlPolicko;
			soubor >> vel >> vlPolicko;
			//nastaveni velikosti a volneho policka
			plan.inicializace_ulozena(vel);
			plan.nastav_vlozene_policko(vlPolicko);
			int druh,otoceni,predmet;
			//nastaveni kazdeho policka
			for(int i = 0; i < vel; i++){
				for(int j = 0; j < vel; j++){
					soubor >> druh >> otoceni >> predmet;
					plan.nastav_policko(i,j,druh,otoceni,predmet);
				}
			}
			soubor >> druh >> otoceni >> predmet;
			plan.nastav_volne_policko(druh,otoceni,predmet);
			string policko, volnePolicko;
			//nastaveni predmetu na jednotlive indexy
			for(int i = 0; i < POCET_PREDMETU; i++){
				soubor >> policko >> volnePolicko;
				plan.nastav_predmet(i, policko, volnePolicko);
			}
			soubor.close();
			continue;
		}
		//vrati hru o krok zpet
		else if(prikaz == "zpet"){
			if(historie.empty() == true){
				cout << "Nelze vratit krok zpet" << endl;
				cout << "Na tahu je hrac cislo: " << hracNaTahu+1 << endl;
				plan.vypis(hrac, pocetHracu);
				continue;
			}
			//vraceni hry predchozimu hraci
			else if(historie.top() == "dalsi"){
				if(hracNaTahu == 0) hracNaTahu = pocetHracu-1;
				else hracNaTahu--; 
				posunuto = true;
			}
			//otoceni zpet
			else if(historie.top() == "otoc"){
				plan.otoc_zpet();
			}
			//vraceni pohybu
			else if(historie.top() == "d1" || historie.top() == "n1" || historie.top() == "p1" || historie.top() == "l1"){
				int radek;
				int sloupec;
				hrac[hracNaTahu].vrat_pozici(&radek,&sloupec);
				plan.pohyb_hrace(historie.top(), velikost, &hrac[hracNaTahu], hracNaTahu, &historie);
				historie.pop();
				historie.pop();
				//ziskal-li hrac bod, je potreba pri kroku zpet ho odebrat a vratit predmet zpet
				if(historie.top() == "bod") {
					hrac[hracNaTahu].uber_bod();
					historie.pop();
					plan.vrat_predmet_zpet(radek, sloupec, historie.top(), &hrac[hracNaTahu]);
					historie.pop();
				}
				cout << "Na tahu je hrac cislo: " << hracNaTahu+1 << endl;
				plan.vypis(hrac, pocetHracu);
				continue;
			}
			//vsunuti zpet vysunuteho policka
			else if(historie.top().length() == 1){
				string vPolicko = historie.top();
				//nastavime hodnotu posledniho posuvu na hodnotu, ktera nebude ovlivnovat zmenu zpet 
				plan.nastav_vlozene_policko("F");
				historie.pop();
				//vlozeni volneho policka z druhe strany
				if(historie.top() == "A") plan.posun("S", hrac, pocetHracu);
				else if(historie.top() == "B") plan.posun("R", hrac, pocetHracu);
				else if(historie.top() == "C") plan.posun("Q", hrac, pocetHracu);
				else if(historie.top() == "D") plan.posun("P", hrac, pocetHracu);
				else if(historie.top() == "E") plan.posun("O", hrac, pocetHracu);
				else if(historie.top() == "I") plan.posun("Y", hrac, pocetHracu);
				else if(historie.top() == "J") plan.posun("X", hrac, pocetHracu);
				else if(historie.top() == "K") plan.posun("W", hrac, pocetHracu);
				else if(historie.top() == "L") plan.posun("V", hrac, pocetHracu);
				else if(historie.top() == "M") plan.posun("U", hrac, pocetHracu);
				
				else if(historie.top() == "O") plan.posun("E", hrac, pocetHracu);
				else if(historie.top() == "P") plan.posun("D", hrac, pocetHracu);
				else if(historie.top() == "Q") plan.posun("C", hrac, pocetHracu);
				else if(historie.top() == "R") plan.posun("B", hrac, pocetHracu);
				else if(historie.top() == "S") plan.posun("A", hrac, pocetHracu);
				else if(historie.top() == "U") plan.posun("M", hrac, pocetHracu);
				else if(historie.top() == "V") plan.posun("L", hrac, pocetHracu);
				else if(historie.top() == "W") plan.posun("K", hrac, pocetHracu);
				else if(historie.top() == "X") plan.posun("J", hrac, pocetHracu);
				else if(historie.top() == "Y") plan.posun("I", hrac, pocetHracu);
				posunuto = false;
				//nastaveni omezeni pro vlozeni policka, ktere by vratilo tah spoluhrace
				plan.nastav_vlozene_policko(vPolicko);
			}
			historie.pop();
			cout << "Na tahu je hrac cislo: " << hracNaTahu+1 << endl;
			plan.vypis(hrac, pocetHracu);
			continue;
		}
		if(posunuto == false){
			//otoci volnym polickem
			if(prikaz == "otoc"){
				plan.otoc();
				historie.push("otoc");
			}
			//vlozi policko
			else if(prikaz.length() == 1){
				string vPolicko = plan.vlozene_policko();
				posunuto = plan.posun(prikaz, hrac, pocetHracu);
				if(posunuto == false) {
					cout << "Nelze vsunout policko na tohle misto" << endl;
				}
				else {
					historie.push(prikaz);
					historie.push(vPolicko);
				}
			}
			else cout << "Nejprve vloz volne policko" << endl;
		}
		else{
			//preda hru dalsimu hraci
			if(prikaz == "dalsi"){
				if(hracNaTahu == pocetHracu-1) hracNaTahu = 0;
				else hracNaTahu++; 
				posunuto = false;
				historie.push("dalsi");
			}
			//posune hracem
			else if(prikaz[0] == 'd' || prikaz[0] == 'n' || prikaz[0] == 'p' || prikaz[0] == 'l'){
				vyhral = plan.pohyb_hrace(prikaz, velikost, &hrac[hracNaTahu], hracNaTahu, &historie);
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
