#include <iostream>
#include "ilgas_skaicius.h"

skaitmuo::skaitmuo(int x, skaitmuo *pries, skaitmuo *kitas) {
	n = x;
	this->pries = pries;
	if (pries != NULL) {
		pries->kitas = this;
	}
	this->kitas = kitas;
	if (kitas != NULL) {
		kitas->pries = this;
	}

}

skaicius::skaicius(const skaicius &x) {
	//skaitmuo *current = this->pirmas;
	skaitmuo *pradinis = new skaitmuo(x.pirmas->n, NULL, NULL);
	pirmas = pradinis;
	paskutinis = pradinis;
	this->zenklas = x.zenklas;
	skaitmuo *current = x.pirmas->kitas;
	while (current != NULL) {
		paskutinis = new skaitmuo(current->n, paskutinis, NULL);
		current = current->kitas;
	}
	tikrinkNuli();
}

skaicius::skaicius() {
	skaitmuo *pradinis = new skaitmuo(0, NULL, NULL);
	pirmas = pradinis;
	paskutinis = pradinis;
	this->zenklas = false;
}

void skaicius::tikrinkNuli() {
	//skaitmuo *current = this->pirmas;
	while (pirmas->kitas != NULL) {
		if (pirmas->n != 0) break;
		pirmas = pirmas->kitas;
		delete pirmas->pries;
		pirmas->pries = NULL;
	}
	if (this->pirmas == this->paskutinis && this->pirmas->n == 0) {
		this->zenklas = false;
	}

}

skaicius skaicius::operator=(const skaicius &x) {
	skaitmuo *current = this->pirmas->kitas;
	skaitmuo *next;
	while (current != NULL) {
		next = current->kitas;
		delete current;
		current = next;
	}
	this->paskutinis = this->pirmas;
	this->pirmas->kitas = NULL;
	this->zenklas = x.zenklas;
	this->pirmas->n = x.pirmas->n;
	current = x.pirmas->kitas;
	while (current != NULL) {
		paskutinis = new skaitmuo(current->n, paskutinis, NULL);
		current = current->kitas;
	}
	tikrinkNuli();
	return *this;
}

skaicius::~skaicius() {
	skaitmuo *current = this->pirmas;
	skaitmuo *next;
	if (this->pirmas != this->paskutinis) {
		while (current != NULL) {
			next = current->kitas;
			delete current;
			current = next;
		}
	}
	else {
		delete this->pirmas;
	}
}

short skaicius::chartoshort(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	else {
		throw invalid_argument("Invalid argument");
	}
}

skaicius::skaicius(string x) {
	this->zenklas = false;
	//NUSKAITYMAS!!!
	if (x[0] == '-') {
		this->zenklas = true;
		pirmas = new skaitmuo(chartoshort(x[1]), NULL, NULL);
		paskutinis = pirmas;
	}
	else {
		pirmas = new skaitmuo(chartoshort(x[0]), NULL, NULL);
		paskutinis = pirmas;
		if (x.size() > 1) {
			pirmas->kitas = new skaitmuo(chartoshort(x[1]), pirmas, NULL);
			paskutinis = pirmas->kitas;
		}
		//paskutinis = pirmas->kitas;
	}
	//skaitmuo *laikinas;
	for (unsigned int i = 2; i < x.size(); i++) {
		paskutinis = new skaitmuo(chartoshort(x[i]), paskutinis, NULL);
		
	}
	tikrinkNuli();
}

skaicius skaicius::operator+(const skaicius &x) {
	//skaicius naujasskaicius = (string) "0";

	if (this->zenklas != x.zenklas) {
		//pereiti i atimti
		if (this->zenklas == true) {
			atimtis(x);
			if (this->zenklas == true) {
				zenklas = false;
			}
			else {
				this->zenklas = true;
			}
		}
		else {
			atimtis(x);
		}
	}
	else {
		sudetis(x, this->zenklas);
	}
	return *this;
}

//++x
skaicius skaicius::operator++() {
	skaicius laikinas = (string) "1";
	*this + laikinas;
	return *this;
}

//x++
skaicius skaicius::operator++(int) {
	skaicius laikinas(*this);
	++(*this);
	return laikinas;
}

//--x
skaicius skaicius::operator--() {
	skaicius laikinas = (string) "-1";
	*this - laikinas;
	return *this;
}

//x--
skaicius skaicius::operator--(int) {
	skaicius laikinas(*this);
	--(*this);
	return laikinas;
}

skaicius skaicius::operator-(const skaicius &x) {
	//skaicius naujas = (string) "0";

	if (this->zenklas != x.zenklas) {
		if (this->zenklas == true) {
			sudetis(x, true);
		}
		else {
			sudetis(x, false);
		}
	}
	else {
		atimtis(x);
		//!!!!!!!!!!!
		if (x.zenklas == true) {
			if (this->zenklas == true) {
				this->zenklas = false;
			}
			else {
				this->zenklas = true;
			}
		}
	}
	return *this;
}

skaicius skaicius::atimtis(const skaicius &x) {
	// grazina (this - x)

	bool skola = false;

	skaicius naujas = (string) "0";

	short laikinas = 0;

	//kuris didesnis?
	skaitmuo *curr1 = x.paskutinis;
	skaitmuo *curr2 = this->paskutinis;

	while (curr1 != NULL && curr2 != NULL) {
		curr1 = curr1->pries;
		curr2 = curr2->pries;
	}

	if (curr1 == NULL && curr2 == NULL) {
		//po tiek pat skaitmenu
		curr1 = x.pirmas;
		curr2 = this->pirmas;
		while (curr1->n == curr2->n) {
			curr1 = curr1->kitas;
			curr2 = curr2->kitas;

			if (curr1 == NULL) {
				//vel atejo i desine, reiskia x == this
				
				*this = naujas;
				return *this;
			}
		}
		if (curr1->n > curr2->n) {
			// x > this
			curr1 = x.paskutinis;
			curr2 = this->paskutinis;
			naujas.zenklas = true;
		}
		else if (curr1->n < curr2->n) {
			//x < this
			curr1 = this->paskutinis;
			curr2 = x.paskutinis;
		}
	}
	else if (curr2 == NULL) {
		//x > this
		curr1 = x.paskutinis;
		curr2 = this->paskutinis;
		naujas.zenklas = true;
	}
	else {
		//this > x
		curr1 = this->paskutinis;
		curr2 = x.paskutinis;
	}

	//curr1 = x.paskutinis;
	//curr2 = this->paskutinis;

	//dabar galima atimti
	while (curr1 != NULL && curr2 != NULL) {
		laikinas = curr1->n - curr2->n;
		if (skola == true) laikinas--;
		skola = false;
		if (laikinas < 0) {
			laikinas += 10;
			skola = true;
		}

		curr1 = curr1->pries;
		curr2 = curr2->pries;

		naujas.pirmas->n = laikinas;
		naujas.pirmas = new skaitmuo(0, NULL, naujas.pirmas);
	}

	while (curr1 != NULL) {
		if (skola) {
			naujas.pirmas->n = curr1->n - 1;
			skola = false;
			if (naujas.pirmas->n < 0) {
				naujas.pirmas->n += 10;
				skola = true;
			}
		}
		else {
			naujas.pirmas->n = curr1->n;
		}
		naujas.pirmas = new skaitmuo(0, NULL, naujas.pirmas);
		curr1 = curr1->pries;
	}

	if (naujas.pirmas != naujas.paskutinis) {
		while (naujas.pirmas->kitas != NULL) {
			if (naujas.pirmas->n == 0) {
				naujas.pirmas = naujas.pirmas->kitas;
				delete naujas.pirmas->pries;
				naujas.pirmas->pries = NULL;
			}
			else {
				break;
			}
		}
	}
	
	*this = naujas;

	return *this;
}

skaicius skaicius::sudetis(const skaicius &x, bool zenklas) {
	bool minty = false;
	skaicius naujas = (string) "0";
	naujas.zenklas = zenklas;

	short laikinas = 0;

	skaitmuo *curr1 = x.paskutinis;
	skaitmuo *curr2 = this->paskutinis;

	while (curr1 != NULL && curr2 != NULL) {
		laikinas = curr1->n + curr2->n;
		if (minty) laikinas++;
		minty = false;
		if (laikinas / 10 > 0) {
			laikinas -= 10;
			minty = true;
		}
		curr1 = curr1->pries;
		curr2 = curr2->pries;

		naujas.pirmas->n = laikinas;
		naujas.pirmas = new skaitmuo(0, NULL, naujas.pirmas);
	}

	while (curr1 != NULL) {
		if (minty) {
			naujas.pirmas->n = curr1->n + 1;
			minty = false;
			if (naujas.pirmas->n / 10 > 0) {
				naujas.pirmas->n -= 10;
				minty = true;
			}
		}
		else {
			naujas.pirmas->n = curr1->n;
		}
		naujas.pirmas = new skaitmuo(0, NULL, naujas.pirmas);
		curr1 = curr1->pries;
	}

	while (curr2 != NULL) {
		if (minty) {
			naujas.pirmas->n = curr2->n + 1;
			minty = false;
			if (naujas.pirmas->n / 10 > 0) {
				naujas.pirmas->n -= 10;
				minty = true;
			}
		}
		else {
			naujas.pirmas->n = curr2->n;
		}
		naujas.pirmas = new skaitmuo(0, NULL, naujas.pirmas);
		curr2 = curr2->pries;
	}
	naujas.pirmas = naujas.pirmas->kitas;
	naujas.pirmas->pries = NULL;

	if (minty) {
		naujas.pirmas = new skaitmuo(1, NULL, naujas.pirmas);
	}
	
	*this = naujas;

	return *this;
}

skaicius skaicius::operator*(const skaicius &x) {
	skaicius suma = (string) "0";
	if (this->zenklas != x.zenklas) {
		suma.zenklas = true;
	}
	skaitmuo *current = x.paskutinis;
	skaicius daugiklis = (string) "0";
	//skaicius i = (string) "0";
	skaicius laikinas;
	while (current != NULL) {
		laikinas = x;
		laikinas.daugyba(current->n);
		for (skaicius i = (string) "0"; i < daugiklis; i++) {
			laikinas.paskutinis = new skaitmuo(0, laikinas.paskutinis, NULL);
		}
		daugiklis++;
		suma + laikinas;
		current = current->pries;
	}
	
	*this = suma;
	return *this;
}

skaicius skaicius::daugyba(const short &x) {
	skaicius laikinas = *this;
	for (short i = 1; i < x; i++) {
		*this + laikinas;
	}
	return *this;
}

bool skaicius::operator==(const skaicius &x) const {
	if (this->zenklas == x.zenklas) {
		skaitmuo* curr1 = x.paskutinis;
		skaitmuo* curr2 = this->paskutinis;
		while (curr1 != NULL && curr2 != NULL) {
			if (curr1->n != curr2->n) return false;
			curr1 = curr1->pries;
			curr2 = curr2->pries;
		}
		if (curr1 != NULL || curr2 != NULL) return false;
		return true;
	}
	else {
		return false;
	}
}

bool skaicius::operator!=(const skaicius &x) const {
	return !this->operator==(x);
}

bool skaicius::operator>(const skaicius &x) const {
	if (*this != x) {
		if (this->zenklas != x.zenklas) {
			if (this->zenklas == true) {
				return false;
			}
			else return true;
		}
		else {
			skaitmuo *curr1 = x.paskutinis;
			skaitmuo *curr2 = this->paskutinis;

			while (curr1 != NULL && curr2 != NULL) {
				curr1 = curr1->pries;
				curr2 = curr2->pries;
			}

			if (curr1 == NULL && curr2 == NULL) {
				curr1 = x.pirmas;
				curr2 = this->pirmas;
				while (curr1->n == curr2->n) {
					curr1 = curr1->kitas;
					curr2 = curr2->kitas;

					if (curr1 == NULL) {
						return false;
					}
				}
				if (curr1->n > curr2->n) {
					if (this->zenklas) {
						return true;
					}
					else return false;
				}
				else {
					if (this->zenklas) {
						return false;
					}
					else return true;
				}
			}
			else {
				if (curr1 == NULL) {
					if (this->zenklas) {
						return false;
					}
					else return true;
				}
				else {
					if (this->zenklas) {
						return true;
					}
					else return false;
				}
			}
		}
	}
	else {
		return false;
	}
}

bool skaicius::operator<(const skaicius &x) const {
	if (this->operator==(x)) {
		return false;
	}
	else return !this->operator>(x);
}

bool skaicius::operator<=(const skaicius &x) const {
	if (*this == x) {
		return true;
	}
	else {
		return this->operator<(x);
	}
}

bool skaicius::operator>=(const skaicius &x) const {
	if (*this == x) {
		return true;
	}
	else {
		return this->operator>(x);
	}
}

skaicius skaicius::operator%(const skaicius &x) {
	if (x.pirmas == x.paskutinis && x.pirmas->n == 0) {
		throw logic_error("Division by zero");
	}
	skaicius laikinas = (string)"0";
	skaicius daugiklis = (string)"10";
	skaicius daliklis = x;
	skaitmuo *curr1 = this->pirmas;
	skaicius nulis = (string)"0";
	while (curr1 != NULL) {
		daliklis.paskutinis = new skaitmuo(0, daliklis.paskutinis, NULL);
		curr1 = curr1->kitas;
	}
	while (*this >= x) {
		while (*this >= daliklis) {
			*this - daliklis;
			laikinas++;
		}
		if (*this != nulis) {
			while (*this < daliklis) {
				daliklis.paskutinis = daliklis.paskutinis->pries;
				laikinas = laikinas * daugiklis;
			}
		}
	}

	return *this;
}

skaicius skaicius::operator/(const skaicius &x) {
	if (x.pirmas == x.paskutinis && x.pirmas->n == 0) {
		throw logic_error("Division by zero");
	}
	skaicius laikinas = (string) "0";
	if (x.zenklas != this->zenklas) {
		laikinas.zenklas = true;
	}
	skaicius daliklis = x;
	skaitmuo *curr1 = this->pirmas;
	skaitmuo *curr2 = daliklis.pirmas;
	skaicius i = (string) "0";
	while (curr2 != NULL) {
		if (curr1 == NULL) {
			
			*this = laikinas;
			return *this;
		}
		curr1 = curr1->kitas;
		curr2 = curr2->kitas;
	}
	while (curr1 != NULL) {
		daliklis.paskutinis = new skaitmuo(0, daliklis.paskutinis, NULL);
		i++;
		curr1 = curr1->kitas;
	}

	//prisirasiau nulius prie galo.

	for (skaicius j = (string) "0"; j < i; j++) {
		while (daliklis <= *this) {
			*this - daliklis;
			laikinas++;
		}
		laikinas.paskutinis = new skaitmuo(0, laikinas.paskutinis, NULL);
		daliklis.paskutinis = daliklis.paskutinis->pries;
		delete daliklis.paskutinis->kitas;
		daliklis.paskutinis->kitas = NULL;
	}
	while (daliklis <= *this) {
		*this - daliklis;
		laikinas++;
	}
	
	*this = laikinas;
	tikrinkNuli();
	return *this;
}

ostream& operator<<(ostream& os, const skaicius &x)
{
	if (x.zenklas == true) os << "-";
	skaitmuo *current = x.pirmas;
	while (current != NULL) {
		os << current->n;
		current = current->kitas;
	}
	return os;
}