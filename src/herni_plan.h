#include "labyrint.h"
#include "hrac.h"

//definice herniho planu
class HerniPlan {
	private:
		int lPole;
		int tPole;
		int iPole;
		int velikost;
		Policko mapa[11][11];
		//Policko **mapa;
		Policko volne;
        string predmety[POCET_PREDMETU];
        string volnePredmety[POCET_PREDMETU];
		string vlozenePolicko;
        int pocetBodu;
        int pocetPredmetu;
        bool gui;
	public:
        /**
        * Inicializace herniho planu
        * @param vel velikost herniho planu(int)
        */
        void inicializace(int, int, int);
        /**
        * Inicializace ulozeneho herniho planu
        * @param vel velikost herniho planu(int)
        */
        void inicializace_ulozena(int, int, int);
        /**
        * Nastavi, ze se pouziva graficka verze programu
        */
        void je_gui();
        /**
        * Nastavi druh, otoceni a predmet policka
        * @param x radek herniho planu(int)
        * @param y sloupec herniho planu (int)
        * @param druh druh policka(int)
        * @param otoceni otoceni policka(int)
        * @param predmet predmet na policku (int)
        */
		void nastav_policko(int, int, int, int, int);
        /**
        * Nastavi druh, otoceni a predmet volneho policka
        * @param druh druh policka(int)
        * @param otoceni otoceni policka(int)
        * @param predmet predmet na policku (int)
        */
		void nastav_volne_policko(int, int, int);
        /**
        * Nastavi predmet ziskany z ulozene hry do pole predmetu
        * @param i index(int)
        * @param predmet predmet, ktery se ma nastavit na index pole predmety(string)
        * @param volnyPredmet predmet, ktery se ma nastavit na index pole volnePredmety(string)
        */
		void nastav_predmet(int, string, string);
        /**
        * Prirazeni nahodneho predmetu hraci
        * @param hrac hrac, kteremu se predmet nastavi(Hrac *)
        */
		void prirad_predmet(Hrac *);
        /**
        * Ulozene herni predmety v unicode
        * @param cislo cislo predmetu(int)
        * @return  unicode reprezentace znaku (string)
        */
		string herni_predmety(int );
        /**
        * Vykresleni stredu policka
        * @param postava cislo hrace na policku(int)
        * @param predmet predmet na policku(int)
        * @param zacatek cislo hrace, ktery na policku startoval(int)
        */
		void vykresli_stred(int, int, int);
        /**
        * Posune hracem o jedno pole
        * @param prikaz smer pohybu hrace(string)
        * @param velikost velikost herniho planu(int)
        * @param hrac posouvany hrac(Hrac *)
        * @param cisloHrace cislo posouvaneho hrace(int)
        * @param historie historie hernich tahu(stack<string> *)
        * @return cislo hrace, ktery zvitezil(pokud zvitezil) (int)
        */
		int pohyb_hrace(string, int, Hrac *, int, stack<string> *);
        /**
        * Vykresleni jednoho policka
        * @param mapa atributy policka mapy(Policko)
        * @param cast cast policka, ktere je rozdeleno do tri casti(int)
        * @param postava cislo hrace na policku(int)
        * @param zacatek cislo hrace, ktery na policku startoval(int)
        */
		void vypis_policko(Policko, int, int, int);
        /**
        * Vytvoreni popisku herniho planu
        * @param radek cislo radku indikujici vypsani vodorovneho popisku(int)
        * @param cast cast policka, ktere je rozdeleno do tri casti (int)
        * @param zacatek indikuje, zda se jedna o levy nebo pravy svisly popisek(bool)
        */
		void popisek(int, int, bool);
        /**
        * Vypsani (vykresleni) herni mapy
        * @param hrac[] vsichni hraci(Hrac)
        * @param pocetHracu pocet hracu ve hre (int)
        */
		void vypis(Hrac [], int );
        /**
        * Vycisti terminalovou obrazovku
        * @return terminalovy prikaz pro posun/vycisteni pohledu(int)
        */
		int cista_obrazovka();
        /**
        * Vlozi volne policko na souradnici a ulozi vysunute
        * @param x radek herniho planu(int)
        * @param y sloupec herniho planu (int)
        * @param hrac[] vsichni hraci(Hrac)
        * @param pocetHracu pocet hracu ve hre(int)
        */
		void vloz(int, int, Hrac[], int);
        /**
        * Posunuti rady
        * @param symbol znak reprezentujici vlozeni policka na miste, kde se nachazi popisek s danym znakem(string)
        * @param hrac[] vsichni hraci(Hrac)
        * @param pocetHracu pocet hracu ve hre(int)
        * @return hodnota reprezentujici, zda byl symbol na hernim planu a byl-li tedy umoznen posun(bool)
        */
		bool posun(string, Hrac [], int);
        /**
        * Otoci s volnym polickem
        */
		void otoc();
        /**
        * Otoci s volnym polickem zpet
        */
		void otoc_zpet();
        /**
        * Posledni provedene vlozeni policka
        * @return naposledy pouzity prikaz pro vsunuti policka(string)
        */
		string vlozene_policko();
        /**
        * Nastavi vlozenePolicko po navraceni vlozeneho policka
        */
		void nastav_vlozene_policko(string);
        /**
        * Vrati hracem sebrany predmet zpet do hry a vrati hru do stavu pred sebranim tohoto predmetu
        * @param x radek herniho planu(int)
        * @param y sloupec herniho planu (int)
        * @param predmet vraceny predmet(string)
        * @param hrac hrac, ktery vraci predmet(Hrac *)
        */
		void vrat_predmet_zpet(int, int, string, Hrac *);
        /**
        * Ulozeni herniho planu do souboru
        * @param soubor soubor, kam se herni plan ulozi(ofstream *)
        */
        void uloz(ofstream *);
        /**
        * Vrati druh policka na souradnicich
        * @param x radek herniho planu(int)
        * @param y sloupec herniho planu (int)
        * @return druh policka(int)
        */
        int vrat_druh(int, int);
        /**
        * Vrati otoceni policka na souradnicich
        * @param x radek herniho planu(int)
        * @param y sloupec herniho planu (int)
        * @return otoceni policka(int)
        */
        int vrat_otoceni(int, int);
        /**
        * Vrati predmet policka na souradnicich
        * @param x radek herniho planu(int)
        * @param y sloupec herniho planu (int)
        * @return predmet policka(int)
        */
        int vrat_predmet(int, int);
};
