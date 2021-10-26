#include<iostream>
#define MAX 10
using namespace std;

//Định nghĩa lớp PHANSO
class PHANSO{
public:
	//Khai bao thuoc tinh cua lop PHANSO
	int tu, mau;
	//Ham khoi tao khong doi
	PHANSO() {
		tu = 0;
		mau = 1;
	}
	//Ham khoi tao co doi
	PHANSO(int _tu, int _mau) {
		tu = _tu;
		if (_mau == 0)
			mau = 1;
		else
		{
			mau = _mau;
		}
	}
	//Ham huy
	~PHANSO() {}
	//Ham nhap gia tri phan so
	void nhapPhanSo() {
		cout << "\tNhap tu so: ";
		cin >> tu;
		cout << "\tNhap mau so: ";
		cin >> mau;
	}
	//Ham xuat thong tin phan so
	void xuatPhanSo() {
		cout << tu << "/" << mau << endl;
	}
	//Ham tim uoc so chung lon nhat
	int USCLN(int a, int b) {
		int gcd = a;
		while (a % gcd || b % gcd) {
			gcd--;
		}
		return gcd;
	}
	//Ham rut gon phan so
	PHANSO rutGonPhanSo() {
		int ucln = USCLN(tu, mau);
		PHANSO ketqua;
		ketqua.tu = tu / ucln;
		ketqua.mau = mau / ucln;
		return ketqua;
	}
	//Ham operator overloading +
	PHANSO operator + (PHANSO a) {
		PHANSO ketqua;
		ketqua.tu = tu*a.mau + a.tu*mau;
		ketqua.mau = mau * a.mau;
		ketqua = ketqua.rutGonPhanSo();
		return ketqua;
	}
	//Nap chong toan tu >
	bool operator > (PHANSO a) {
		if (tu * a.mau > a.tu * mau) {
			return true;
		}
		return false;
	}
	//Nap chong toan tu <
	bool operator < (PHANSO a) {
		if (tu * a.mau < a.tu * mau) {
			return true;
		}
		return false;
	}
};

//Hàm nhập danh sách phân số
void nhapMangPhanSo(PHANSO a[], int& n) {
	cout << "Nhap so luong phan so: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Nhap phan so thu " << i + 1 << ":\n";
		a[i].nhapPhanSo();
	}
}
//Hàm xuất danh sách phân số
void xuatMangPhanSo(PHANSO a[], int n) {
	for (int i = 0; i < n; i++) {
		a[i].xuatPhanSo();
	}
}
//Hàm hoán vị 2 phân số
void swap(PHANSO& a, PHANSO& b) {
	PHANSO tmp = a;
	a = b;
	b = tmp;
}
//Hàm sắp xếp danh sách phân số theo thứ tự giảm dần
void sapXepGiamDan(PHANSO a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (float(a[i].tu) / a[i].mau < float(a[j].tu) / a[j].mau) {
				swap(a[i], a[j]);
			}
		}
	}
}
//Hàm tính tổng các phân số trong danh sách
PHANSO tongPhanSo(PHANSO a[], int n) {
	PHANSO tong;
	for (int i = 0; i < n; i++) {
		tong = tong + a[i];
	}
	return tong;
}
//Hàm tìm phân số có giá trị lớn nhất
PHANSO phanSoLonNhat(PHANSO a[], int n) {
	PHANSO max;
	for (int i = 0; i < n; i++) {
		if (float(a[i].tu) / a[i].mau > float(max.tu) / max.mau) {
			max = a[i];
		}
	}
	return max;
}
//Hàm main
int main() {
	//Khai báo danh sách phân số, phân số tổng, phân số max
	PHANSO a[MAX],tong, max;
	//Khai báo số lượng phân số trong danh sách
	int n;
	//Gọi hàm nhập danh sách
	nhapMangPhanSo(a, n);
	cout << "\nMang ban dau: "<<endl;
	//Gọi hàm xuất danh sách
	xuatMangPhanSo(a, n);
	cout << "\nPhan so tong: ";
	//Gọi hàm tính tổng các phân số và rút gọn phân số kết quả
	tong = tongPhanSo(a, n).rutGonPhanSo();
	//Gọi hàm xuất phân số
	tong.xuatPhanSo();
	//Gọi hàm sắp xếp danh sách
	sapXepGiamDan(a, n);
	cout << "\nMang sau khi sap xep: " << endl;
	//Gọi hàm xuất danh sách
	xuatMangPhanSo(a, n);
	cout << "Phan so lon nhat: ";
	//Gọi hàm tìm phân số lớn nhất
	max = phanSoLonNhat(a, n);
	max.xuatPhanSo();
	return 0;
}

