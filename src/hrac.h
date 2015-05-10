
//definice hrace

class Hrac {
	private:
		int x, y;
		int predmet;
		int body;
	public:
        Hrac();
        /**
        * Inicializace hrace
        * @param cisloHrace cislo inicializovaneho hrace(int)
        * @param velikost velikost herniho planu(int)
        */
        Hrac(int, int);
        /**
        * Inicializace ulozeneho hrace
        * @param pozicex x-ova pozice hrace(int)
        * @param pozicey y-ova pozice hrace(int)
        * @param spredmet cislo hracem hledaneho predmetu(int)
        * @param sbody body hrace(int)
        */
        Hrac(int, int, int, int);
        /**
        * Navraceni poctu bodu hrace
        * @return pocet bodu hrace(int)
        */
		int pocet_bodu();
        /**
        * Navraceni cisla hledaneho predmetu
        * @return cislo hledaneho predmetu(int)
        */
		int hledany_predmet();
        /**
        * Nastaveni predmetu hraci
        * @param cislo cislo hracem hledaneho predmetu(int)
        */
		void nastav_predmet(int);
        /**
        * Nastaveni predmetu na hodnotu znacici, ze hrac muze jit do cile a koncit
        */
		void nastav_konec();
        /**
        * Pridani bodu hraci
        */
		void pridej_bod();
        /**
        * Odebrani bodu hraci pri kroku zpet
        */
		void uber_bod();
        /**
        * Vraceni pozice hrace
        * @param radek radek, kde se hrac nachazi(int *)
        * @param sloupec sloupec, kde se hrac nachazi(int *)
        */
		void vrat_pozici(int *, int *);
        /**
        * Pohyb hrace
        * @param prikaz smer posunu hrace(char)
        * @param velikost velikost herniho planu(int)
        * @param presah hodnota indikujici presunuti hrace na druhou stranu herniho planu(bool)
        */
		void pohyb(char, int, bool);
        /**
        * Zjisteni pritomnosti osoby na policku
        * @param r radek herniho planu(int)
        * @param s sloupec herniho planu (int)
        * @return hodnota reprezentujici, zda je nebo neni na policku postava(bool)
        */
		bool je_postava(int, int);
        /**
        * Ulozeni hrace do souboru
        * @param soubor soubor, kam se herni plan ulozi(ofstream *)
        */
		void uloz(ofstream *);
  
};
