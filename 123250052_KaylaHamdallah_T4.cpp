#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void tampilPeta(char petaKursi[5][8]) {
	cout << "LAYAR BIOSKOP DISINI" << endl;
	cout << "    " << endl;
	for (int k = 0; k <= 8; k++) {
		cout << setw(3) << k << endl;
		
		char baris[] = {'A', 'B', 'C', 'D', 'E'};
		for (int i = 0; i < 5; i++) {
			cout << baris[i] << " [ ";
			for (int j = 0; j < 8; j++) {
				cout << petaKursi[i][j] << "  ";
			}
			cout << " ] " << endl;
		}
	}
}
	
	void pesanTiket(char petaKursi[5][8], string namaPemesan[5][8]) {
		string nama;
		char baris;
		int kolom;
		
		cin.ignore();
		cout << "masukkan nama pemesan : " << endl;
		getline(cin, nama);
		cout << "pilih baris (A-E) : " << endl;
		cin >> baris;
		cout << "pilih kolom (1-8) : " << endl;
		cin >> kolom;
		
		if (baris >= 'a' && baris <= 'z')
			baris = baris - 32;
			
		int i = baris - 'A';
		int j = kolom - 1;
		
		if (i < 0 || i >= 5 || j < 0 || j >= 8) {
			cout << "posisi kursi tidak valid" << endl;
			return;
		}
		
		if (petaKursi[i][j] == 'O') {
			petaKursi[i][j] = 'X';
			namaPemesan[i][j] = nama;
			cout << "tiket berhasil dipesan" << endl;
		} else {
			cout << "maaf, kursi tersebut sudah dipesan atas nama " 
				 << namaPemesan[i][j] << ".\n";
		}
	}
	
	void cariPelanggan(string namaPemesan[5][8]) {
		string nama;
		cin.ignore();
		cout << "masukkan nama pelanggan yang dicari : " << endl;
		getline(cin, nama);
		
		bool ditemukan = false;
		char baris[] = {'A','B','C','D','E'};
		
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 8; j++) {
				if (namaPemesan[i][j] == nama) {
					cout << "pelanggan '" << nama << "' ditemukan di kursi" 
						 << baris[i] << (j + 1) << endl;
						 ditemukan = true;
					 }
				 }
			 }
			 
			 if (!ditemukan)
				cout << "pelanggan tidak ditemukan." << endl;
			}
			
			void laporanPenjualan(char petaKursi[5][8], int hargaTiket)  { 
				int terjual = 0, sisa = 0;
				
				for (int i =0; i < 5; i++) {
					for (int j = 0; j < 8; j++) {
						if (petaKursi[i][j] == 'X') 
							terjual++;
						else 
							sisa++;
						}
					}
					
					cout << "LAPORAN PENJUALAN" << endl;
					cout << "TIKET TERJUAL       : " << terjual << endl;
					cout << "SISA TIKET          : " << sisa << endl;
					cout << "TOTAL PENDAPATAN    : Rp" << (terjual * hargaTiket) << endl;
				}
				
				int main() {
					char petaKursi [5][8];
					string namaPemesan[5][8];
					int hargaTiket = 50000;
					int pilihan;
					
					for (int i = 0; i < 5; i++) 
						for (int j = 0; j < 8; j++) {
							petaKursi[i][j] = 'O';
							namaPemesan[i][j] = "-";
						}
						
						do { 
							cout << "=====================================" << endl;
							cout << "     MENU BIOSKOP CINEMA CODING      " << endl;
							cout << "=====================================" << endl;
							cout << "1. TAMPILKAN PETA KURSI " << endl;
							cout << "2. PESAN TIKET " << endl;
							cout << "3. CARI PELANGGAN " << endl;
							cout << "4. LAPORAN PENJUALAN HARI INI " << endl;
							cout << "5. KELUAR" << endl;
							cout << "PILIH MENU (1-5) : " << endl;
							cin >> pilihan;
							
							switch (pilihan) {
								case 1:
									tampilPeta(petaKursi);
									break;
								case 2:
									pesanTiket(petaKursi, namaPemesan);
									break;
								case 3: 
									cariPelanggan(namaPemesan);
									break;
								case 4: 
									laporanPenjualan(petaKursi, hargaTiket);
									break;
								case 5: 
									cout << "TERIMA KASIH. SISTEM LOKET DITUTUP" << endl;
									break;
								default: 
									cout << "PILIHAN ANDA TIDAK VALID!!!" << endl;
								}
							} while (pilihan !=5);
							
							return 0;
						}
					
