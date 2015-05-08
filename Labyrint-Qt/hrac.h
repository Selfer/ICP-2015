//definice hrace
class Hrac {
	private:
		int x, y;
		int predmet;
		int body;
	public:
		void inicializace(int, int);
		//nastavi hodnoty hrace
		void inicializace_ulozena(int, int, int, int);
		//vrati pocet bodu
		int pocet_bodu();
		//vrati cislo hledaneho predmetu
		int hledany_predmet();
		//nastavi predmet podle cisla
		void nastav_predmet(int);
		//nastavi predmet na hornotu, ktera znaci, ze hrac muze koncit
		void nastav_konec();
		//prida bod po nalezenem predmetu
		void pridej_bod();
		//ubere bod v pripade zmeny zpet
		void uber_bod();
		//vrati pozici hrace
		void vrat_pozici(int *, int *);
		//pohne s hracem
		void pohyb(char, int, bool);
		//zjisti, zda je na policku postava
		bool je_postava(int, int);
		//ulozi hrace do souboru
		void uloz(ofstream *);
  
};
