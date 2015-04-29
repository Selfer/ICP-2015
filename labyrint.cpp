#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <iostream>
#define VELIKOST 5
#define POCET_PREDMETU 20
#define POCET_BODU 5
#define NIC -1
#define KONEC -2

using namespace std;

//struktura pro kazde policko
typedef struct {
int druh;
int otoceni;
int predmet;
} Policko;

//definice hrace
class Hrac {
	private:
		int x, y;
		int predmet;
		int body;
	public:
		void inicializace(int cisloHrace, int velikost){
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
		int pocet_bodu(){
			return body;
		}
		//vrati cislo hledaneho predmetu
		int hledany_predmet(){
			return predmet;
		}
		//nastavi predmet podle cisla
		void nastav_predmet(int cislo){
			predmet = cislo;
		}
		//nastavi predmet na hornotu, ktera znaci, ze hrac muze koncit
		void nastav_konec(){
			predmet = KONEC;
		}
		//prida bod po nalezenem predmetu
		void pridej_bod(){
			body++;
		}
		//vrati pozici hrace
		void vrat_pozici(int *radek, int *sloupec){
			*radek = x;
			*sloupec = y;
		}
		//pohne s hracem
		void pohyb(char prikaz, int velikost, bool presah){
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
		bool je_postava(int r, int s){
			if(x == r && y == s) return true;
			else return false;
		}
  
};

//definice herniho planu
class HerniPlan {
	private:
		int lPole;
		int tPole;
		int iPole;
		int velikost;
		Policko mapa[VELIKOST][VELIKOST];
		Policko volne;
		string predmety[POCET_PREDMETU];
		string volnePredmety[POCET_PREDMETU];
	public:
		HerniPlan (int vel){
			velikost = vel;
			inicializace();
		}
		void inicializace(){
			lPole = 4;
			tPole = 5;
			iPole = 0;
			//pevna policka
			mapa[0][0].druh = 0;
			mapa[0][0].otoceni = 1;
			mapa[0][velikost-1].druh = 0;
			mapa[0][velikost-1].otoceni = 2;
			mapa[velikost-1][0].druh = 0;
			mapa[velikost-1][0].otoceni = 0;
			mapa[velikost-1][velikost-1].druh = 0;
			mapa[velikost-1][velikost-1].otoceni = 3;
			
			mapa[2][0].druh = 1;
			mapa[2][0].otoceni = 3;
			mapa[0][2].druh = 1;
			mapa[0][2].otoceni = 0;
			mapa[2][2].druh = 1;
			mapa[2][2].otoceni = 3;
			mapa[2][velikost-1].druh = 1;
			mapa[2][velikost-1].otoceni = 1;
			mapa[velikost-1][2].druh = 1;
			mapa[velikost-1][2].otoceni = 2;
			//vytvoreni herniho planu
			int pocet_poli = (velikost*velikost)/3;
			for(int i = 0; i < velikost; i++){
				for(int j = 0; j < velikost; j++){
					if(i % 2 == 0 && j % 2 == 0) continue;
					int nahoda;
					while(1){
						nahoda = rand() % 3;
						//zajisteni co nejrovnomernejsiho rozlozeni poli
						if(nahoda == 0 && lPole <= pocet_poli) break;
						else if(nahoda == 1 && tPole <= pocet_poli) break;
						else if(nahoda == 2 && iPole <= pocet_poli) break;
					}
					mapa[i][j].druh = nahoda;
					mapa[i][j].otoceni = rand() % 4;
					if(mapa[i][j].druh == 0) lPole++;
					else if(mapa[i][j].druh == 1) tPole++;
					else iPole++;
				}
			}
			//volne policko
			if(lPole < tPole && lPole < iPole) volne.druh = 0;
			else if(tPole < lPole && tPole < iPole) volne.druh = 1;
			else volne.druh = 2;
			volne.otoceni = rand() % 4;
			
			//predmety
			for(int i = 0; i < 20; i++){
				predmety[i] = herni_predmety(i);
				volnePredmety[i] = predmety[i];
			}
			
			volne.predmet = -1;
			for(int i = 0; i < velikost; i++){
				for(int j = 0; j < velikost; j++){
					mapa[i][j].predmet = -1;
				}
			}
			int radek;
			int sloupec;
			//rozmisteni predmetu
			for(int i = 0; i < POCET_PREDMETU; ){
				//umisteni jednoho predmetu na volne policko
				if(i == 17){
					volne.predmet = i;
					i++;
					continue;
				}
				//nahodne vybrani souradnic
				radek = rand() % velikost;
				sloupec = rand() % velikost;
				if((radek == 0 && sloupec == 0) || (radek == 0 && sloupec == velikost-1) ||
					(radek == velikost-1 && sloupec == 0) || (radek == velikost-1 && sloupec == velikost-1)) continue;
				if(mapa[radek][sloupec].predmet >= 0) continue;
				else mapa[radek][sloupec].predmet = i;
				i++;
			}
		}
		//priradi predmet hraci
		void prirad_predmet(Hrac *hrac){
			int nahoda;
			while(1){
				nahoda = rand() % POCET_PREDMETU;
				if(volnePredmety[nahoda] != ""){
					hrac->nastav_predmet(nahoda);
					volnePredmety[nahoda] = "";
					break;
				}
				
			}
		}
		//vrati predmet podle cisla (indexu)
		string herni_predmety(int cislo){
			switch (cislo){
				case 0:
					return "\u27B4";
				case 1:
					return "\u2606";
				case 2:
					return "\u260F";
				case 3:
					return "\u2602";
				case 4:
					return "\u2600";
				case 5:
					return "\u2618";
				case 6:
					return "\u2620";
				case 7:
					return "\u2658";
				case 8:
					return "\u2693";
				case 9:
					return "\u2694";
				case 10:
					return "\u2696";
				case 11:
					return "\u2698";
				case 12:
					return "\u2690";
				case 13:
					return "\u26C0";
				case 14:
					return "\u2708";
				case 15:
					return "\u270E";
				case 16:
					return "\u271A";
				case 17:
					return "\u2625";
				case 18:
					return "\u273F";
				case 19:
					return "\u2730";
				default:
					return "CHYBA";
			}
		}
		//vykresli stredove policko kazde casti, kde muze byt i postava hrace nebo predmet
		void vykresli_stred(int postava, int predmet, int zacatek){
			switch(postava){
				case 0:
					cout << "\x1B[31m\u26B1\x1B[0m";
					break;
				case 1:
					cout << "\x1B[32m\u26B1\x1B[0m";
					break;
				case 2:
					cout << "\x1B[36m\u26B1\x1B[0m";
					break;
				case 3:
					cout << "\x1B[33m\u26B1\x1B[0m";
					break;
				case 4:
					cout << "\u26B1";
					break;
				default:
					if(zacatek == 0) cout << "\x1B[31m\u2591\x1B[0m";
					else if(zacatek == 1) cout << "\x1B[32m\u2591\x1B[0m";
					else if(zacatek == 2) cout << "\x1B[36m\u2591\x1B[0m";
					else if(zacatek == 3) cout << "\x1B[33m\u2591\x1B[0m";
					else cout << "\u2591";
					break;
			}
			if(predmet >= 0) cout << predmety[predmet];
			else {
				if(zacatek == 0) cout << "\x1B[31m\u2591\x1B[0m";
				else if(zacatek == 1) cout << "\x1B[32m\u2591\x1B[0m";
				else if(zacatek == 2) cout << "\x1B[36m\u2591\x1B[0m";
				else if(zacatek == 3) cout << "\x1B[33m\u2591\x1B[0m";
				else cout << "\u2591";
			}
		}
		//posune hrace
		int pohyb_hrace(string prikaz, int velikost, Hrac *hrac, int cisloHrace){
			string pocet = prikaz.substr(1,prikaz.length()-1);
			//kontrola, zda je pocet kroku cislo
			for(unsigned int i = 0; i < pocet.length(); i++) {
				if(pocet[i] > '0' && pocet[i] < '9');
				else {
					cout << "Neni cislo";
					return 0;
				}
			}
			int pocetKroku = atoi(pocet.c_str());
			if(pocetKroku > velikost) {
				cout << "Cislo je moc velke";
				return 0;
			}
			int radek;
			int sloupec;
			for(int i = 0; i < pocetKroku; i++){
				hrac->vrat_pozici(&radek,&sloupec);
				//krok dolu
				if(prikaz[0] == 'd'){
					if(radek == velikost-1) break;
					//kontrola, zda se muze hrac pohnout dolu z aktualniho policka
					if((mapa[radek][sloupec].druh == 0 && mapa[radek][sloupec].otoceni == 0) ||
						(mapa[radek][sloupec].druh == 0 && mapa[radek][sloupec].otoceni == 3) ||
						(mapa[radek][sloupec].druh == 1 && mapa[radek][sloupec].otoceni == 2) ||
						(mapa[radek][sloupec].druh == 2 && mapa[radek][sloupec].otoceni == 1) ||
						(mapa[radek][sloupec].druh == 2 && mapa[radek][sloupec].otoceni == 3)) break; 
					//kontrola, zda se muze hrac posunout na nove policko
					if((mapa[radek+1][sloupec].druh == 0 && mapa[radek+1][sloupec].otoceni == 1) ||
						(mapa[radek+1][sloupec].druh == 0 && mapa[radek+1][sloupec].otoceni == 2) ||
						(mapa[radek+1][sloupec].druh == 1 && mapa[radek+1][sloupec].otoceni == 0) ||
						(mapa[radek+1][sloupec].druh == 2 && mapa[radek+1][sloupec].otoceni == 1) ||
						(mapa[radek+1][sloupec].druh == 2 && mapa[radek+1][sloupec].otoceni == 3)) break; 
					hrac->pohyb(prikaz[0], velikost, false);
					radek++;
				}
				//krok nahoru
				else if(prikaz[0] == 'n'){
					if(radek == 0) break;
					//kontrola, zda se muze hrac pohnout nahoru z aktualniho policka
					if((mapa[radek][sloupec].druh == 0 && mapa[radek][sloupec].otoceni == 1) ||
						(mapa[radek][sloupec].druh == 0 && mapa[radek][sloupec].otoceni == 2) ||
						(mapa[radek][sloupec].druh == 1 && mapa[radek][sloupec].otoceni == 0) ||
						(mapa[radek][sloupec].druh == 2 && mapa[radek][sloupec].otoceni == 1) ||
						(mapa[radek][sloupec].druh == 2 && mapa[radek][sloupec].otoceni == 3)) break; 
					//kontrola, zda se muze hrac posunout na nove policko
					if((mapa[radek-1][sloupec].druh == 0 && mapa[radek-1][sloupec].otoceni == 0) ||
						(mapa[radek-1][sloupec].druh == 0 && mapa[radek-1][sloupec].otoceni == 3) ||
						(mapa[radek-1][sloupec].druh == 1 && mapa[radek-1][sloupec].otoceni == 2) ||
						(mapa[radek-1][sloupec].druh == 2 && mapa[radek-1][sloupec].otoceni == 1) ||
						(mapa[radek-1][sloupec].druh == 2 && mapa[radek-1][sloupec].otoceni == 3)) break; 
					hrac->pohyb(prikaz[0], velikost, false);
					radek--;
				}
				//krok vpravo
				else if(prikaz[0] == 'p'){
					if(sloupec == velikost-1) break;
					//kontrola, zda se muze hrac doprava dolu z aktualniho policka
					if((mapa[radek][sloupec].druh == 0 && mapa[radek][sloupec].otoceni == 2) ||
						(mapa[radek][sloupec].druh == 0 && mapa[radek][sloupec].otoceni == 3) ||
						(mapa[radek][sloupec].druh == 1 && mapa[radek][sloupec].otoceni == 1) ||
						(mapa[radek][sloupec].druh == 2 && mapa[radek][sloupec].otoceni == 0) ||
						(mapa[radek][sloupec].druh == 2 && mapa[radek][sloupec].otoceni == 2)) break; 
					//kontrola, zda se muze hrac posunout na nove policko
					if((mapa[radek][sloupec+1].druh == 0 && mapa[radek][sloupec+1].otoceni == 0) ||
						(mapa[radek][sloupec+1].druh == 0 && mapa[radek][sloupec+1].otoceni == 1) ||
						(mapa[radek][sloupec+1].druh == 1 && mapa[radek][sloupec+1].otoceni == 3) ||
						(mapa[radek][sloupec+1].druh == 2 && mapa[radek][sloupec+1].otoceni == 0) ||
						(mapa[radek][sloupec+1].druh == 2 && mapa[radek][sloupec+1].otoceni == 2)) break; 
					hrac->pohyb(prikaz[0], velikost, false);
					sloupec++;
				}
				//krok vlevo
				else if(prikaz[0] == 'l'){
					if(sloupec == 0) break;
					//kontrola, zda se muze hrac pohnout doleva z aktualniho policka
					if((mapa[radek][sloupec].druh == 0 && mapa[radek][sloupec].otoceni == 0) ||
						(mapa[radek][sloupec].druh == 0 && mapa[radek][sloupec].otoceni == 1) ||
						(mapa[radek][sloupec].druh == 1 && mapa[radek][sloupec].otoceni == 3) ||
						(mapa[radek][sloupec].druh == 2 && mapa[radek][sloupec].otoceni == 0) ||
						(mapa[radek][sloupec].druh == 2 && mapa[radek][sloupec].otoceni == 2)) break; 
					//kontrola, zda se muze hrac posunout na nove policko
					if((mapa[radek][sloupec-1].druh == 0 && mapa[radek][sloupec-1].otoceni == 2) ||
						(mapa[radek][sloupec-1].druh == 0 && mapa[radek][sloupec-1].otoceni == 3) ||
						(mapa[radek][sloupec-1].druh == 1 && mapa[radek][sloupec-1].otoceni == 1) ||
						(mapa[radek][sloupec-1].druh == 2 && mapa[radek][sloupec-1].otoceni == 0) ||
						(mapa[radek][sloupec-1].druh == 2 && mapa[radek][sloupec-1].otoceni == 2)) break; 
					hrac->pohyb(prikaz[0], velikost, false);
					sloupec--;
				}
				if(mapa[radek][sloupec].predmet == hrac->hledany_predmet()){
					hrac->pridej_bod();
					mapa[radek][sloupec].predmet = NIC;
					if(hrac->pocet_bodu() == POCET_BODU){
						hrac->nastav_konec();
					}
					else prirad_predmet(hrac);
				}
				else if(hrac->hledany_predmet() == KONEC){
					if(cisloHrace == 0 && radek == 0 && sloupec == 0) return 1;
					else if(cisloHrace == 1 && radek == velikost-1 && sloupec == velikost -1) return 2;
					else if(cisloHrace == 2 && radek == 0 && sloupec == velikost-1) return 3;
					else if(cisloHrace == 3 && radek == velikost-1 && sloupec == 0) return 4;
					
				}
			}
			return 0;
		}
		//vypise cast policka podle jeho druhu a natoceni
		void vypis_policko(Policko mapa, int cast, int postava, int zacatek){
			//políčko tvaru L
			if(mapa.druh == 0){
				if(mapa.otoceni == 0){
					if(cast == 0) cout << "\u2588\u2588\u2591\u2591\u2588\u2588\t";
					else if(cast == 1) {
						cout << "\u2588\u2588";
						vykresli_stred(postava, mapa.predmet, zacatek);
						cout << "\u2591\u2591\t";
					}
					else cout << "\u2588\u2588\u2588\u2588\u2588\u2588\t";
				}
				else if(mapa.otoceni == 1){
					if(cast == 0) cout << "\u2588\u2588\u2588\u2588\u2588\u2588\t";
					else if(cast == 1) {
						cout << "\u2588\u2588";
						vykresli_stred(postava, mapa.predmet, zacatek);
						cout << "\u2591\u2591\t";
					}
					else cout << "\u2588\u2588\u2591\u2591\u2588\u2588\t";
				}
				else if(mapa.otoceni == 2){
					if(cast == 0) cout << "\u2588\u2588\u2588\u2588\u2588\u2588\t";
					else if(cast == 1) {
						cout << "\u2591\u2591";
						vykresli_stred(postava, mapa.predmet, zacatek);
						cout << "\u2588\u2588\t";
					}
					else cout << "\u2588\u2588\u2591\u2591\u2588\u2588\t";
				}
				else {
					if(cast == 0) cout << "\u2588\u2588\u2591\u2591\u2588\u2588\t";
					else if(cast == 1) {
						cout << "\u2591\u2591";
						vykresli_stred(postava, mapa.predmet, zacatek);
						cout << "\u2588\u2588\t";
					}
					else cout << "\u2588\u2588\u2588\u2588\u2588\u2588\t";
				}
			}
			//políčko tvaru T
			else if(mapa.druh == 1){
				if(mapa.otoceni == 0){
					if(cast == 0) cout << "\u2588\u2588\u2588\u2588\u2588\u2588\t";
					else if(cast == 1) {
						cout << "\u2591\u2591";
						vykresli_stred(postava, mapa.predmet, zacatek);
						cout << "\u2591\u2591\t";
					}
					else cout << "\u2588\u2588\u2591\u2591\u2588\u2588\t";
				}
				else if(mapa.otoceni == 1){
					if(cast == 0) cout << "\u2588\u2588\u2591\u2591\u2588\u2588\t";
					else if(cast == 1) {
						cout << "\u2591\u2591";
						vykresli_stred(postava, mapa.predmet, zacatek);
						cout << "\u2588\u2588\t";
					}
					else cout << "\u2588\u2588\u2591\u2591\u2588\u2588\t";
				}
				else if(mapa.otoceni == 2){
					if(cast == 0) cout << "\u2588\u2588\u2591\u2591\u2588\u2588\t";
					else if(cast == 1) {
						cout << "\u2591\u2591";
						vykresli_stred(postava, mapa.predmet, zacatek);
						cout << "\u2591\u2591\t";
					}
					else cout << "\u2588\u2588\u2588\u2588\u2588\u2588\t";
				}
				else{
					if(cast == 0) cout << "\u2588\u2588\u2591\u2591\u2588\u2588\t";
					else if(cast == 1) {
						cout << "\u2588\u2588";
						vykresli_stred(postava, mapa.predmet, zacatek);
						cout << "\u2591\u2591\t";
					}
					else cout << "\u2588\u2588\u2591\u2591\u2588\u2588\t";
				}
			}
			//políčko tvaru I
			else if(mapa.druh == 2){
				if(mapa.otoceni == 0 || mapa.otoceni == 2){
					if(cast == 0) cout << "\u2588\u2588\u2591\u2591\u2588\u2588\t";
					else if(cast == 1) {
						cout << "\u2588\u2588";
						vykresli_stred(postava, mapa.predmet, zacatek);
						cout << "\u2588\u2588\t";
					}
					else cout << "\u2588\u2588\u2591\u2591\u2588\u2588\t";
				}
				else{
					if(cast == 0) cout << "\u2588\u2588\u2588\u2588\u2588\u2588\t";
					else if(cast == 1) {
						cout << "\u2591\u2591";
						vykresli_stred(postava, mapa.predmet, zacatek);
						cout << "\u2591\u2591\t";
					}
					else cout << "\u2588\u2588\u2588\u2588\u2588\u2588\t";
				}
			}
		}
		//vypise popisek k mape
		void popisek(int radek, int cast, bool zacatek){
			if(radek == 0 && cast == 0 && zacatek == true){
				if(velikost >= 5) cout << "\t\t" << "   A\t\t   B";
				if(velikost >= 7) cout << "\t   C";
				if(velikost >= 9) cout << "\t   D";
				if(velikost >= 11) cout << "\t   E"; 
				cout << endl;
			}
			if(cast == 1){
				switch (radek){
					case 1:
						if(zacatek == true) cout << "   Y\t";
						else cout << "   I\t";
						break;
					case 3:
						if(zacatek == true) cout << "   X\t";
						else cout << "   J\t";
						break;
					case 5:
						if(zacatek == true) cout << "   W\t";
						else cout << "   K\t";
						break;
					case 7:
						if(zacatek == true) cout << "   V\t";
						else cout << "   L\t";
						break;
					case 9:
						if(zacatek == true) cout << "   U\t";
						else cout << "   M\t";
						break;
					default:
						cout << "\t";
				}
			}
			else cout << "\t";

		}
		//vypise herni mapu
		void vypis(Hrac hrac[], int pocetHracu){
			for(int i = 0; i < velikost; i++){
				//rozdeleni jednoho policka na tri kvuli lepsi graficke podobe
				for(int cast = 0; cast < 3; cast++){
					popisek(i, cast, true);
					for(int j = 0; j < velikost; j++){
						int postava = -1;
						//hledani hracu na policku
						for(int h = 0; h < pocetHracu; h++){
							if(hrac[h].je_postava(i,j)){
								if(postava >= 0) postava = 4;
								else postava = h;
							}
						}
						int zacatek = NIC;
						if(i == 0 && j == 0) zacatek = 0;
						else if(i == velikost-1 && j == velikost -1) zacatek = 1;
						else if(i == 0 && j == velikost-1) zacatek = 2;
						else if(i == velikost-1 && j == 0) zacatek = 3;
						vypis_policko(mapa[i][j], cast, postava, zacatek);
					}
					popisek(i, cast, false);
					//vypise herni stav
					if(i == 0 && cast == 0){
						cout << "\x1B[31mHrac 1:\x1B[0m " << hrac[0].pocet_bodu() << " bodu";
						cout << "\t" << "\x1B[36mHrac 3:\x1B[0m " << hrac[2].pocet_bodu() << " bodu";
					}
					if(i == 0 && cast == 1){
						cout << "\x1B[32mHrac 2:\x1B[0m " << hrac[1].pocet_bodu() << " bodu";
						cout << "\t" << "\x1B[33mHrac 4:\x1B[0m " << hrac[3].pocet_bodu() << " bodu";
					}
					//vypise volne policko
					if(i == 1){
						cout << "\t";
						vypis_policko(volne, cast, NIC, NIC);
					}
					cout << endl;
				}
				cout << endl;
				if(i + 1 == velikost){
					if(velikost >= 5) cout << "\t\t" << "   S\t\t   R";
					if(velikost >= 7) cout << "\t   Q";
					if(velikost >= 9) cout << "\t   P";
					if(velikost >= 11) cout << "\t   O"; 
					cout << endl;
				}
			}
		}
		//"prekresli" obrazovku
		int cista_obrazovka(){
			return write(STDOUT_FILENO,"\e[1;1H\e[2J\n",12);
		}
		//vlozi policko na souradnici a ulozi vysunute
		void vloz(int x, int y, Hrac hrac[], int pocetHracu){
			Policko vysunute;
			//vlozeni volne policko podle souradnic
			if(x == 0){
				vysunute = mapa[velikost-1][y];
				for(int i = velikost-1; i > 0; i--){
					mapa[i][y] = mapa[i-1][y];
				}
				mapa[0][y] = volne; 
				volne = vysunute;
			}
			else if(y == 0){
				vysunute = mapa[x][velikost-1];
				for(int i = velikost-1; i > 0; i--){
					mapa[x][i] = mapa[x][i-1];
				}
				mapa[x][0] = volne; 
				volne = vysunute;
			}
			else if(x == velikost-1){
				vysunute = mapa[0][y];
				for(int i = 0; i < velikost; i++){
					mapa[i][y] = mapa[i+1][y];
				}
				mapa[velikost-1][y] = volne; 
				volne = vysunute;
			}
			else if(y == velikost-1){
				vysunute = mapa[x][0];
				for(int i = 0; i < velikost-1; i++){
					mapa[x][i] = mapa[x][i+1];
				}
				mapa[x][velikost-1] = volne; 
				volne = vysunute;
			}
			
			int radek;
			int sloupec;
			//posun hraci na posunutych polich
			for(int i = 0; i < pocetHracu; i++){
				hrac[i].vrat_pozici(&radek,&sloupec);
				if(x == 0 && sloupec == y){
					hrac[i].pohyb('d', velikost, true);
				}
				else if(y == 0 && radek == x){
					hrac[i].pohyb('p', velikost, true);
				}
				else if(x == velikost-1 && sloupec == y){
					hrac[i].pohyb('n', velikost, true);
				}
				else if(y == velikost-1 && radek == x){
					hrac[i].pohyb('l', velikost, true);
				}
			}
		}
		//posune radu
		void posun(string symbol, Hrac hrac[], int pocetHracu){
			if(symbol == "A") vloz(0,1,hrac,pocetHracu);
			else if(symbol == "B") vloz(0,3,hrac,pocetHracu);
			
			else if(symbol == "I") vloz(1,velikost-1,hrac,pocetHracu);
			else if(symbol == "J") vloz(3,velikost-1,hrac,pocetHracu);
			
			else if(symbol == "R") vloz(velikost-1,3,hrac,pocetHracu);
			else if(symbol == "S") vloz(velikost-1,1,hrac,pocetHracu);
			
			else if(symbol == "X") vloz(3,0,hrac,pocetHracu);
			else if(symbol == "Y") vloz(1,0,hrac,pocetHracu);
			else cout << "Prikaz neodpovida" << endl; 
		}
		//otoci s volnym polickem
		void otoc(){
			if(volne.otoceni == 3) volne.otoceni = 0;
			else volne.otoceni++; 
		}
};

int main(int argc, char *argv[]) {
	int velikost = VELIKOST;
	int pocetHracu = 4;
	int hracNaTahu = 0;
	int vyhral = 0;
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
		//otoci volnym polickem
		else if(prikaz == "otoc"){
			plan.otoc();
		}
		//preda hru dalsimu hraci
		else if(prikaz == "dalsi"){
			if(hracNaTahu == pocetHracu-1) hracNaTahu = 0;
			else hracNaTahu++; 
		}
		//ukaze hraci hledany predmet
		else if(prikaz == "predmet"){
			cout << "Na tahu je hrac cislo: " << hracNaTahu+1 << endl;
			plan.vypis(hrac, pocetHracu);
			if(hrac[hracNaTahu].hledany_predmet() == -2) cout << "Vrat se na zacatek" << endl;
			else cout << "Hledas: " << plan.herni_predmety(hrac[hracNaTahu].hledany_predmet()) << endl;
			continue;
		}
		//posune hracem
		else if(prikaz[0] == 'd' || prikaz[0] == 'n' || prikaz[0] == 'p' || prikaz[0] == 'l'){
			vyhral = plan.pohyb_hrace(prikaz, velikost, &hrac[hracNaTahu], hracNaTahu);
		}
		//vlozi policko
		else if(prikaz.length() == 1){
			plan.posun(prikaz, hrac, pocetHracu);
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

