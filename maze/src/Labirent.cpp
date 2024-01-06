#include "Labirent.hpp"
//#=duvar , ' ' = gecebilecegimiz yol
Labirent::Labirent(Konum baslangic, Konum bitis){//bilgisayarin konumu bulmasini saglar.baslangictan girip bitise dogru
	//dosya oku
	FILE* fp = fopen("Harita.txt", "r");
	unsigned char karakter = 0;
	
	int satir=0,sutun=0;
	x = baslangic.x;
	y = baslangic.y;
	this->bitis = bitis;
	yon = ASAGI;
	yigit = new Stack<Konum>();//yigitin icerine konum bilgisini atar.
	yigit->push(Konum(-1,-1,yon));//labirente gridigimizi gostermek icin -1,-1 i isaret etmek icin kullandim.
	while (!feof(fp)) {
	   karakter = getc(fp);
	   if(karakter == 255) break;//255 dosya sonu karakteri(karakterlerin ASCII karsiligi
	   if(karakter == 10){//10 bi alt satira gelmesi
		 satir++;
		 sutun=0;
	   }
	   else{
			harita[satir][sutun] = karakter;
			sutun++;
	   }
	}
}
Konum Labirent::mevcutKonum(){
	return Konum(x,y,yon);
}
bool Labirent::adimAt(Konum mevcut, Konum ileri){
	if(!EngelVarmi(ileri)){//eger enegel yoksa ileri gider.
		yigit->push(mevcut);//stack'e konumu atarak devam eder.
		ayarla(ileri,ileri.yon);
		return true;
	}
	return false;
}
void Labirent::ayarla(Konum konum,Yon yon){
	system("cls");//ekran temizle
	this->x = konum.x;//yeni x konumu
	this->y = konum.y;//yeni y konumu
	this->yon = yon;//yeni yon
	harita[konum.x][konum.y] = '-';//haritada ilerledigimiz yeri cizgi ile belirttir
	cout<<yaz();
	Sleep(30);//ekranda titreme olmamasi 30 milisaniye bekler
}
bool Labirent::CikisaGeldimi(){
	return x == bitis.x && y == bitis.y;
}
bool Labirent::EngelVarmi(Konum konum){			
	if(konum.x >= YUKSEKLIK || konum.x < 0 || konum.y >= GENISLIK || konum.y < 0) return false;
	return harita[konum.x][konum.y] == '#' || harita[konum.x][konum.y] == '-';//cizgide bir nevi engel.gittigi yoldan tekrar gitmemesi icin
}
	
string Labirent::yaz(){
	char YonChr[] = {31,17,30,16};
	stringstream ss;
	for(int satir=0;satir<YUKSEKLIK;satir++){
		ss<<setw(10);
		for(int sutun=0;sutun<GENISLIK;sutun++){
			if(satir == x && sutun == y){
				ss<<YonChr[yon];
			}
			else{
				 if(harita[satir][sutun] == '-') ss<<' ';//cizgi yazmamak icin bosluk birak
				 else ss<<harita[satir][sutun];
			}
		}	
		ss<<endl;				
	}
	return ss.str();
}
