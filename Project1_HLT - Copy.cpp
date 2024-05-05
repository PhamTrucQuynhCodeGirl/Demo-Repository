#include "iostream"
#include "cmath"
using namespace std;

int nhap1()
{
	int a;
	cout << "Nhap vao mot so nguyen a khac 0: ";
	cin >> a;
	return a;
}

int nhap2()
{
	int b;
	cout << "Nhap vao mot so nguyen b khac 0: ";
	cin >> b;
	return b;
}

void kiemtra(int a, int b)
{
	while (a == 0 || b == 0 || a == b)
	{
		cout << "Hai so nguyen a va b phai nguyen va khac 0.\na va b phai khac nhau.\nMoi nhap lai.\n";
		cout << "Nhap vao mot so nguyen a lon hon 0: ";
		cin >> a;
		cout << "Nhap vao mot so nguyen b lon hon 0: ";
		cin >> b;
	}
}
int menu(int a, int b)
{
	int options;
	cout << "Hay chon 1 so bat ki tuong ung voi cac yeu cau sau: \n";
	cout << "1.  " << a << " va " << b << " la duong hay am?\n";
	cout << "2.  " << a << " va " << b << " la so chan hay le?\n";
	cout << "3.  " << a << " va " << b << " la so nguyen to hay hop so?\n";
	cout << "4.  " << "Co bao nhieu so nguyen to giua " << a << " va " << b << endl;
	cout << "5.  " << "Co bao nhieu uoc so giua " << a << " va " << b << endl;
	cout << "6.  " << "Co bao nhieu uoc so chung cua " << a << " va " << b << endl;
	cout << "7.  " << "Uoc chung lon nhat va boi chung nho nhat cua " << a << " va " << b << endl;
	cout << "8.  " << "Co bao nhieu so chinh phuong giua " << a << " va " << b << endl;
	cout << "9.  " << "Co bao nhieu so hoan thien giua " << a << " va " << b << endl;
	cout << "10. " << "Thoat khoi chuong trinh.\n\n";
	do
	{
		cout << "Moi chon so tu 1 den 10: ";
		cin >> options;
	} while (options < 1 || options >10);
	return options;
}

void so1(int a, int b)
{
	if (a > 0 && b > 0)
		cout << a << " va " << b << " la so nguyen duong.";
	else if (a < 0 && b < 0)
		cout << a << " va " << b << " la so nguyen am.";
	else if (a < 0 && b > 0)
		cout << a << " la so nguyen am.\n" << b << " la so nguyen duong.";
	else
		cout << a << " la so nguyen duong.\n" << b << " la so nguyen am.";
}

void so2(int a, int b)
{
	if (a % 2 == 0 && b % 2 == 0)
		cout << a << " va " << b << " la so chan.";
	else if (a % 2 != 0 && b % 2 != 0)
		cout << a << " va " << b << " la so le.";
	else if (a % 2 != 0 && b % 2 == 0)
		cout << a << " la so le.\n" << b << " la so chan.";
	else
		cout << a << " la so chan.\n" << b << " la so le.";
}

bool kiemtraSoNguyenTo(int n)
{
	if (n < 2)
		return false;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;
	return true;
}

void uocSo(int n)
{
	for (int i = 2; i <= n; i++)
		if (n % i == 0)
			cout << i << " ";
}
void so3(int a, int b)
{
	if (kiemtraSoNguyenTo(a) && kiemtraSoNguyenTo(b))
		cout << a << " va " << b << " la so nguyen to.";
	else if (kiemtraSoNguyenTo(a))
	{
		cout << a << " la so nguyen to.\n" << b << " la hop so va co cac uoc so la: ";
		uocSo(b);
	}
	else if (kiemtraSoNguyenTo(b))
	{
		cout << a << " la hop so va co cac uoc so la: ";
		uocSo(a);
		cout << endl;
		cout << b << " la so nguyen to.";
	}
	else
	{
		cout << a << " la hop so va co cac uoc so la: ";
		uocSo(a);
		cout << endl;
		cout << b << " la hop so va co cac uoc so la: ";
		uocSo(b);
	}
}

void so4(int a, int b)
{
	int max, min, dem=0;
	if (a > b)
	{
		max = a;
		min = b;
	}
	else
	{
		max = b;
		min = a;
	}
	for (int i = min+1; i < max; i++)
		if (kiemtraSoNguyenTo(i))
		{
			cout << i << " ";
			dem++;
		}
	if (dem > 0)
	{
		cout << "Cac so nguyen to giua " << a << " va " << b << " la: ";
		cout << "\nCo " << dem << " so nguyen to giua " << a << " va " << b;
	}
	else
		cout << "Khong co so nguyen to giua " << a << " va " << b;
}

void so5(int a, int b)
{
	int max, min;
	if (a > b)
	{
		max = a;
		min = b;
	}
	else
	{
		max = b;
		min = a;
	}
	cout << "Cac uoc so giua " << a << " va " << b << " la: ";
	for (int i = min + 1; i < max; i++)
	{
		if (b % i == 0)
			cout << i << " ";
	}
}

void so6(int a, int b)
{
	int max, min, dem = 0;
	if (a > b)
	{
		max = a;
		min = b;
	}
	else
	{
		max = b;
		min = a;
	}
	cout << "Cac uoc so chung cua " << a << " va " << b << " la: ";
	for (int j = 1; j <= min; j++)
	{
		if (a % j == 0 && b % j == 0)
		{
			cout << j << " ";
			dem++;
		}
	}
	cout << "\nCo " << dem << " uoc so chung cua " << a << " va " << b;
}

void so7(int a, int b)
{
	int max, min, dem = 0;
	if (a > b)
	{
		max = a;
		min = b;
	}
	else
	{
		max = b;
		min = a;
	}
	cout << "Uoc chung lon nhat cua " << a << " va " << b << " la: ";
	for (int i = min; i >= 0; i--)
	{
		if (a % i == 0 && b % i == 0)
		{
			cout << i;
			cout << "\nBoi chung nho nhat cua " << a << " va " << b << " la ";
			int bCNN = (a * b) / i;
			cout << bCNN;
			break;
		}

	}
}

bool ktraSoChinhPhuong(int n)
{
	int m = sqrt(n);
	if (m * m == n)
		return true;
	else
		return false;
}

void so8(int a, int b)
{
	int max, min, dem = 0;
	if (a > b)
	{
		max = a;
		min = b;
	}
	else
	{
		max = b;
		min = a;
	}
	cout << "Cac so chinh phuong giua " << a << " va " << b << " la: ";
	for (int i = min + 1; i < max; i++)
		if (ktraSoChinhPhuong(i))
		{
			cout << i << " ";
			dem++;
		}
	cout << "\nCo " << dem << " so chinh phuong giua " << a << " va " << b;
}

bool soHoanThien(int n)
{
	int tong = 0;
	for (int i = 1; i <= n / 2; i++)
	{
		if (n % i == 0)
			tong += i;
	}
	return tong == n;
}

void so9(int a, int b)
{
	int max, min, dem = 0;
	if (a > b)
	{
		max = a;
		min = b;
	}
	else
	{
		max = b;
		min = a;
	}
	cout << "Cac so hoan thien giua " << a << " va " << b << " la: ";
	for (int j = min + 1; j < max; j++)
	{
		if (soHoanThien(j))
		{
			cout << j << " ";
			dem++;
		}
	}
	cout << "\nCo " << dem << " so hoan thien giua " << a << " va " << b;
}
//---------------------------------------------------------------------------------------
int main()
{
	char k;
	int chon, m, n;
	m = nhap1();
	n = nhap2();
	kiemtra(m, n);
    do
    {
        system("cls");
	cout << endl;
	chon = menu(m, n);
	if (chon == 1)
	{
		cout << "Giai quyet nhiem vu tim so am duong.\n\n";
		so1(m, n);
	}
	else if (chon == 2)
	{
		cout << "Giai quyet nhiem vu tim so chan le.\n";
		so2(m, n);
	}
	else if (chon == 3)
	{
		cout << "Giai quyet van de so nguyen to va hop so.\n";
		so3(m, n);
	}
	else if (chon == 4)
	{
		cout << "Giai quyet van de so nguyen to giua " << m << " va " << n << endl;
		so4(m, n);
	}
	else if (chon == 5)
	{
		cout << "Giai quyet van ve tim uoc so giua " << m << " va " << n << endl;
		so5(m, n);
	}
	else if (chon == 6)
	{
		cout << "Giai quyet van ve tim uoc so chung giua " << m << " va " << n << endl;
		so6(m, n);
	}
	else if (chon == 7)
	{
		cout << "Giai quyet van de tim uoc chung lon nhat va boi chung nho nhat cua " << m << " va " << n << endl;
		so7(m, n);
	}
	else if (chon == 8)
	{
		cout << "Giai quyet van de tim so chinh phuong giua " << m << " va " << n << endl;
		so8(m, n);
	}
	else if (chon == 9)
	{
		cout << "Giai quyet van de tim so hoan thien giua " << m << " va " << n << endl;
		so9(m, n);
	}
	else if (chon == 10)
		exit(0);

        cout<<"\nCo muon tiep tuc voi nhiem vu khac khong? (Chon C hoac K): ";
        cin>>k;
    }while(k=='C'||k=='c');
    cin.get();
    cin.ignore();
	return 0;
}