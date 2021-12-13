#pragma once
#include <iostream>
template <class T>
class Array
{

public:
	Array(int t) {
		this->taille = t;
		this->tab = new T[t];
	}
	void remplissage();
	void print()const;

private:
	T* tab;
	int taille;
};



template<class T>
inline void Array<T>::remplissage()
{
	for (int i = 0; i < this->taille; i++)
	{
		std::cin >> this->tab[i];
	}
}

template<class T>
inline void Array<T>::print() const
{
	for (int i = 0; i < this->taille; i++)
	{
		std::cout << this->tab[i]<<std::endl;
	}
}
