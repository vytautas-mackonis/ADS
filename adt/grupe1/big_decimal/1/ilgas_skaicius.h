#ifndef ILGAS_SKAICIUS_H
#define ILGAS_SKAICIUS_H
#include <string>

using namespace std;

class skaitmuo {
	friend class skaicius;
private:
	short n;          //skaitmuo 0-9
	skaitmuo *kitas;  //adresas i sekanti skaitmeni (desinej)
	skaitmuo *pries;  //adresas i pries tai buvusi skaitmeni (kairej)
	skaitmuo(int x, skaitmuo *pries, skaitmuo *kitas);
public:
	friend ostream& operator<<(ostream& os, const skaicius &x);
};

class skaicius {
private:
	skaitmuo *pirmas;
	skaitmuo *paskutinis;
	bool zenklas;

	void tikrinkNuli();
	short chartoshort(char c);
	skaicius atimtis(const skaicius &x);
	skaicius sudetis(const skaicius &x, bool zenklas);
	skaicius daugyba(const short &x);
public:
	//bool zenklas;
	skaicius operator=(const skaicius &x);
	//void clear();
	~skaicius();
	skaicius();
	skaicius(const skaicius &x);
	skaicius(string x);
	skaicius operator+(const skaicius &x);
	//++x
	skaicius operator++();
	//x++
	skaicius operator++(int);
	//--x
	skaicius operator--();
	//x--
	skaicius operator--(int);
	skaicius operator-(const skaicius &x);
	skaicius operator*(const skaicius &x);
	bool operator==(const skaicius &x) const;
	bool operator!=(const skaicius &x) const;
	bool operator>(const skaicius &x) const;
	bool operator<(const skaicius &x) const;
	bool operator<=(const skaicius &x) const;
	bool operator>=(const skaicius &x) const;
	skaicius operator/(const skaicius &x);
	skaicius operator%(const skaicius &x);
	//string operator<<(const skaicius &x);
	friend ostream& operator<<(ostream& os, const skaicius &x);
	//void spauzdinimas();
};

#endif /* ILGAS_SKAICIUS_H */