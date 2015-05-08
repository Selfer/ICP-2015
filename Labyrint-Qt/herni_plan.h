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
	public:
		void inicializace(int);
		void inicializace_ulozena(int);
		//nastaveni policka
		void nastav_policko(int, int, int, int, int);
		//nastaveni volneho policka
		void nastav_volne_policko(int, int, int);
		//nastaveni predmetu
		void nastav_predmet(int, string, string);
		//priradi predmet hraci
		void prirad_predmet(Hrac *);
		//vrati predmet podle cisla (indexu)
		string herni_predmety(int );
		//vykresli stredove policko kazde casti, kde muze byt i postava hrace nebo predmet
		void vykresli_stred(int, int, int);
		//posune hrace
		int pohyb_hrace(string, int, Hrac *, int, stack<string> *);
		//vypise cast policka podle jeho druhu a natoceni
		void vypis_policko(Policko, int, int, int);
		//vypise popisek k mape
		void popisek(int, int, bool);
		//vypise herni mapu
		void vypis(Hrac [], int );
		//"prekresli" obrazovku
		int cista_obrazovka();
		//vlozi policko na souradnici a ulozi vysunute
		void vloz(int, int, Hrac[], int);
		//posune radu
		bool posun(string, Hrac [], int);
		//otoci s volnym polickem
		void otoc();
		//otoci s volnym polickem zpet
		void otoc_zpet();
		//vrati posledni provedene vlozeni policka
		string vlozene_policko();
		//pro vraceni vlozeneho policka se musi nastavit vlozenePolicko
		void nastav_vlozene_policko(string);
		//vrati hracem vzaty predmet zpet do hry a vrati hru do stavu pred sebranim tohoto predmetu
		void vrat_predmet_zpet(int, int, string, Hrac *);
		//ulozi herni plan do souboru
		void uloz(ofstream *);
        //vrati druh policka
        int vrat_druh(int, int);
        //vrati otoceni policka
        int vrat_otoceni(int, int);
        //vrati predmet na policku
        int vrat_predmet(int, int);
};
