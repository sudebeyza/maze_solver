#include "Labirent.hpp"

int main(){
	Labirent *labirent = new Labirent(Konum(0,20),Konum(19,11));
	//labirent nesnesi olusturup ona baslangic ve bitis degerleri ata
	
	labirent->yigit->push(Konum(labirent->x,labirent->y,ASAGI));//giris noktasini yigita at
	labirent->ayarla(Konum(labirent->x,labirent->y,ASAGI).Asagi(),ASAGI);
	
	//cozum kismi	
	while(!labirent->CikisaGeldimi()){
		int denemeYonSayisi=1;
		Konum oncekiKonum = labirent->yigit->top();//top ile yigitin son elemanini(cikmak uzere olan)oku
		Konum mevcutKonum = labirent->mevcutKonum();
		
		Konum ileri = mevcutKonum.AyniYon();//duvara carpana kadar ayni yonde ilerle
		//duvara gelirse dort yone donebilmesi icin
		if(!labirent->adimAt(mevcutKonum,ileri)){
			int i=0;
			bool sonuc = false;
			Konum yeni = mevcutKonum;
			while(!sonuc && denemeYonSayisi<5){	//4 kez deneyebilir cunku 4 cografi yon vardir.
				yeni = mevcutKonum.SaatYonu((Yon)((mevcutKonum.yon+i)%4));		
								
				i++;
				denemeYonSayisi++;
				if(yeni.yon == mevcutKonum.TersYon()){
					sonuc=false;
				}
				else{
					sonuc = labirent->adimAt(mevcutKonum,yeni);
				}
			}
			if(denemeYonSayisi == 5){
				labirent->yigit->pop();
				labirent->ayarla(oncekiKonum,oncekiKonum.TersYon());//her yer duvar ise geri don
			}
		}
		
	}
	cout<<endl;
	cout<<"            !!!!!!!!!! TEBRIKLERR !!!!!!!!!!"<<endl;
	cout<<"          !!!!!!!!!! CIKIS BULUNDU !!!!!!!!!!"<<endl;
	
	getchar();
	
	delete labirent;
	return 0;
}
