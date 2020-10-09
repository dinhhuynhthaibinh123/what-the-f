#include <iostream>
#include <string>
using namespace std;

class QuanCo
{
protected:
	bool MauCo;//True trang - False den
	int x, y;
public:
	QuanCo() 
	{
		MauCo = 1;
		x = 0; y = 0;
	}
	~QuanCo() {}

	virtual void CachDiChuyen() = 0;
};
class Xe :public QuanCo
{
public:
	Xe() {}
	Xe(bool b, int a, int c)
	{
		MauCo = b;
		x = a;
		y = c;
	}
	void CachDiChuyen()
	{
		cout << "\nXe: Đi ngang hay dọc trên bàn cờ miễn là đừng bị quân khác cản đường từ điểm đi";
		cout << "\nđến điểm đến.";
	}
};
class Ngua :public QuanCo
{
public:
	Ngua() {}
	Ngua(bool b, int a, int c)
	{
		MauCo = b;
		x = a;
		y = c;
	}
	void CachDiChuyen()
	{
		cout << "\nMã: Đi ngang 2 ô và dọc 1 ô (hay dọc 2 ô và ngang 1 ô) cho mỗi nước đi. Nếu có";
		cout << "\nquân nằm ngay bên cạnh mã và cản đường ngang 2 (hay đường dọc 2), mã bị cản không";
		cout << "\nđược đi đường đó.";
	}
};
class Vua :public QuanCo
{
public:
	Vua() {}
	Vua(bool b, int a, int c)
	{
		MauCo = b;
		x = a;
		y = c;
	}
	void CachDiChuyen()
	{
		cout << "\nTướng: Đi từng ô một, đi ngang hoặc dọc. Tướng luôn luôn phải ở trong phạm vi";
		cout << "\ncung và không được ra ngoài. Cung tức là hình vuông 2X2 được đánh dấu bằng đường ";
		cout << "\nchéo hình chữ X";
	}
};
class Si :public QuanCo
{
public:
	Si() {}
	Si(bool b, int a, int c)
	{
		MauCo = b;
		x = a;
		y = c;
	}
	void CachDiChuyen()
	{
		cout << "\nSĩ: Đi xéo 1 ô mỗi nước. Sĩ luôn luôn phải ở trong cung như Tướng.";
	}
};
class Tuong :public QuanCo
{
public:
	Tuong() {}
	Tuong(bool b, int a, int c)
	{
		MauCo = b;
		x = a;
		y = c;
	}
	void CachDiChuyen()
	{
		cout << "\nTượng: Đi chéo 2 ô (ngang 2 và dọc 2) cho mỗi nước đi. Tượng chỉ được phép ở một";
		cout << "\nbên của bàn cờ, không được di chuyển sang nửa bàn cờ của đối phương. Nước đi của ";
		cout << "\ntượng sẽ không hợp lệ khi có một quân cờ nằm chặn giữa đường đi.";
	}
};
class Phao :public QuanCo
{
public:
	Phao() {}
	Phao(bool b, int a, int c)
	{
		MauCo = b;
		x = a;
		y = c;
	}
	void CachDiChuyen()
	{
		cout << "\nPháo: Đi ngang và dọc giống như xe. Điểm khác biệt là nếu pháo muốn ăn quân, pháo";
		cout << "\nphải nhảy qua đúng 1 quân nào đó. Khi không ăn quân, tất cả những điểm từ chỗ đi đến";
		cout << "\nchéo hình chữ X";
	}
};

class Chot :public QuanCo
{
public:
	Chot() {}
	Chot(bool b, int a, int c)
	{
		MauCo = b;
		x = a;
		y = c;
	}
	void CachDiChuyen()
	{
		cout << "\nTốt: đi một ô mỗi nước. Nếu tốt chưa vượt qua sông, nó chỉ có thể đi thẳng tiến. Khi";
		cout << "\nđã vượt sông rồi, tốt có thể đi ngang 1 nước hay đi thẳng tiến 1 bước mỗi nước.";
	}
};

class BanCo
{
private:
	QuanCo *a[32];
public:
	BanCo()//true = Trang, false = Den
	{
		//Ben trang
		a[0] = new Chot(true, 4, 1);
		a[1] = new Chot(true, 4, 3);
		a[2] = new Chot(true, 4, 5);
		a[3] = new Chot(true, 4, 7);
		a[4] = new Chot(true, 4, 9);
		a[5] = new Phao(true, 3, 2);
		a[6] = new Phao(true, 3, 8);
		a[7] = new Xe(true, 1, 1);
		a[8] = new Xe(true, 1, 9);
		a[9] = new Ngua(true, 1, 2);
		a[10] = new Ngua(true, 1, 8);
		a[11] = new Tuong(true, 1, 3);
		a[12] = new Tuong(true, 1, 7);
		a[13] = new Si(true, 1, 4);
		a[14] = new Si(true, 1, 6);
		a[15] = new Vua(true, 1, 5);

		//Ben den
		a[16] = new Chot(false, 7, 1);
		a[17] = new Chot(false, 7, 3);
		a[18] = new Chot(false, 7, 5);
		a[19] = new Chot(false, 7, 7);
		a[20] = new Chot(false, 7, 9);
		a[21] = new Phao(false, 8, 2);
		a[22] = new Phao(false, 8, 8);
		a[23] = new Tuong(false, 10, 3);
		a[24] = new Tuong(false, 10, 7);
		a[25] = new Xe(false, 10, 1);
		a[26] = new Xe(false, 10, 9);
		a[27] = new Ngua(false, 10, 2);
		a[28] = new Ngua(false, 10, 8);
		a[29] = new Si(false, 10, 4);
		a[30] = new Si(false, 10, 6);
		a[31] = new Vua(false, 10, 5);
	}
	~BanCo()
	{
		delete[]a;
	}
	QuanCo *getQuanCo(int i)
	{
		return a[i];
	}
	void XuatCacDiCuaQuanCo(QuanCo* a)
	{
		a->CachDiChuyen();
	}
};

int main()
{
	cout << "Thai Binh dep trai thanh lich vo dich khap vu tru";
	return 0;
}

