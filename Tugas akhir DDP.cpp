#include<iostream>
#include<fstream>
#include<string>
using namespace std;//Sultan Mu'ammal Khair
struct Menu{
	string nama;
	int harga;
};
struct Transaksi{
	string namaPelanggan;
	string menuDipesan;
	int jumlah;
	int total;
	int totalHarga;

};
void tampilkanMenu(Menu menu[], int jumlahMenu){
	cout<<"\nMenu Makanan Rumah Makan: "<<endl;
	for(int i=0;i<jumlahMenu; ++i){
		cout<<(i+1)<<". "<<menu[i].nama<<"-Rp"<<menu[i].harga<<endl;
	}
}
int tambahTransaksi(Menu menu[], int jumlahMenu){
	Transaksi transaksi;
	int pilihan,jumlah;
	string namaPelanggan;
	int totalKeseluruhan=0;
	
	cout<<"\nMasukkan nama pelanggan: ";
	cin.ignore();
	getline(cin, namaPelanggan);
	
	while(true){
		tampilkanMenu(menu, jumlahMenu);
		cout<<"\nPilih nomer menu (atau ketik '0' untuk selesaikan): ";
		cin>>pilihan;
		
		if (pilihan== 0){
			break;
		}
		
		if (pilihan >= 1 && pilihan <= jumlahMenu){
			cout<<"Masukan jumlah"<<menu[pilihan - 1].nama<<"yang ingin dipesan: ";
			cin>>jumlah;
			
			transaksi.menuDipesan = menu[pilihan-1].nama;
			transaksi.jumlah = jumlah;
			transaksi.totalHarga = menu[pilihan - 1].harga*jumlah;
			totalKeseluruhan += transaksi.totalHarga;
			
			cout<<"\n======STRUK PEMBELIAN======"<<endl;
			cout<<"pelanggan: "<<namaPelanggan<<endl;
			cout<<transaksi.menuDipesan<<"x"<<transaksi.jumlah<<" = Rp "<<transaksi.totalHarga<<endl;
		}else{
			cout<<"Piliham menu tidak valid.silahkan pilih kembali."<<endl;
		}
	}
	
	cout<<"\nTotal Keseluruhan: Rp "<<totalKeseluruhan<<endl;//Sultan Mu,ammal Khair
	
	int uangDiberikan;//Achmad Dhani Alfianto
	cout<<"Masukkan jumlah uang yang di berikan pelanggan: Rp ";
	cin>>uangDiberikan;
	
	if (uangDiberikan >= totalKeseluruhan){
		int kembalian= uangDiberikan - totalKeseluruhan;
		cout<<"Uang Kembalian: Rp "<<kembalian<<endl;
		
		ofstream file("transaksi.txt", ios::app);
		if(file.is_open()){
			file<<"\n=====STRUK PEMBELIAN=====\n";
			file<<"pelanggan: "<<namaPelanggan<<endl;
			file<<"Total Keseluruhan: Rp "<<totalKeseluruhan<<endl;
			file<<"Uang Diberikan: Rp "<<uangDiberikan<<endl;
			file<<"Kembalian: Rp "<<kembalian<<endl;
			file<<"=============================\n";
			file.close();
			}else{
				cout<<"Gagal membuka file transaksi."<<endl;
			}
		}else{
			cout<<"Uang yang diberikan tidak. Mohon bayar sesuai total keseluruhan."<<endl;
		}
	}
	
	void lihatTransaksi(){
		ifstream file("transaksi.txt");
		if(file.is_open()){
			cout<<"\n===Daftar Transaksi==="<<endl;
			string line;
			while (getline(file, line)){
				cout<<line<<endl;
			}
			file.close();
		}else{
			cout<<"Belum ada transaksi yang disimpan."<<endl;
		}
	}
	int main(){
		
		
		Menu menu[]={
		{"Nasi Padang", 10000},
		{"Rendang", 15000},
		{"Nyet Nyet", 11000},
		{"Nasi Kuning", 15000},
		{"Ayam Kampung", 19000},
		{"Nasi Rames", 7000},
		{"Es Teh", 4000},
		{"Es Jeruk", 5000},
		{"Air Es", 2000},
		{"Nutrisari", 3000}
	};
	int jumlahMenu=sizeof(menu)/sizeof(menu[0]);
	while (true){
		cout<<"\nMenu Kasir Rumah Makan: "<<endl;
		cout<<"1. Pesan Makanan"<<endl;
		cout<<"2. Lihat Transaksi Terakhir"<<endl;
		cout<<"3. Keluar"<<endl;
		cout<<"Pilih menu (1/2/3): ";
		int pilihan;
		cin>>pilihan;
		switch (pilihan){
			case 1:
				tambahTransaksi(menu, jumlahMenu);
				break;
			case 2:
				lihatTransaksi();
				break;
			case 3:
				cout<<"Terima kasih! Semoga hari anda menyenangkan."<<endl;
				return 0;
			default:
				cout<<"Pilihan tidak valid. Silahkan coba lagi."<<endl;
				break;
		}
	}
	return 0;//Achmad Dhnai Alfianto
		
	
		
	
}
