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
		string vlozenePolicko;
	public:
		HerniPlan (int);
		void inicializace();
		//priradi predmet hraci
		void prirad_predmet(Hrac *);
		//vrati predmet podle cisla (indexu)
		string herni_predmety(int );
		//vykresli stredove policko kazde casti, kde muze byt i postava hrace nebo predmet
		void vykresli_stred(int, int, int);
		//posune hrace
		int pohyb_hrace(string, int, Hrac *, int);
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
};
