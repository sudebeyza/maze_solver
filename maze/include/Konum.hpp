#ifndef KONUM_HPP
#define KONUM_HPP

typedef enum{ ASAGI, SOL, YUKARI, SAG}Yon;//saat yonune gore


struct Konum{
	int x,y;//x satiri y ise sutunu temsil eder.
	Yon yon;
	Konum(int,int,Yon);
	Konum(int,int);
	Konum();
	Konum AyniYon();
	Konum SaatYonu(Yon);
	Konum Asagi();
	Konum Yukari();
	Konum Sol();
	Konum Sag();
	Yon TersYon();
};

#endif
