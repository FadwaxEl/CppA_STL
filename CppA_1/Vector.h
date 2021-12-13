#pragma once
#include <iostream>
#include <assert.h> 
using namespace std;
namespace vect {
	template <class T>
	class Vecteur3d
	{
	private:
		T vect[3];

	public:
		/*------------eviter le passage par valeur-------------*/
		Vecteur3d(T x = 0.0, T y = 0.0, T z = 0.0);
		Vecteur3d(const Vecteur3d&) = delete; /** impossible de travailler par le cr propre à la classe allouer les passage par valeur**/
		Vecteur3d& operator=(const Vecteur3d&) = delete; /***interdire de travailler avec = ****/
		/*on a le droit de travailler avec le passage par reference ou bien par adresse*/

		void print()const;
		T at(unsigned int)const;
		T& operator[](unsigned int); // si on a float ona just l'accés en lecture 
		//retourn la reference vers la variable
		bool operator==(const Vecteur3d& v)const;//protejer en meme temp notre vecteur et l'autre 
		bool operator!=(const Vecteur3d& v)const;
		Vecteur3d* opposite();
		Vecteur3d* operator+(const Vecteur3d&);
		Vecteur3d* operator-(const Vecteur3d&);
		Vecteur3d* operator*(const Vecteur3d&);
		Vecteur3d* operator^(const Vecteur3d&);
		T norme();
		Vecteur3d* produit(T val);
		Vecteur3d* addition(T val);

		//friend 	void display(Vecteur3d& v);

	};
	template<class T>
	inline Vecteur3d<T>::Vecteur3d<T>(T x, T y, T z)
	{
		this->vect[0] = x;
			this->vect[1] = y;
			this->vect[2] = z; 
	}
	template<class T>
	void Vecteur3d<T>::print() const
	{
		int i = 0;
			cout << "(" << this->at(i);
			for (i = 1; i < 3; i++)
			{
				cout << "," << this->at(i);
			}
			cout << ")";

	}
	template<class T>
	inline T Vecteur3d<T>::at(unsigned int i) const
	{
		assert(i >= 0 && i < 3);//debeug
   	try//en mode release
   	{
   		if (i < 0 || i >= 3) throw "range erre";
   		return this->vect[i];
   
   	}
   	catch (char* e)
   	{
   		cout << e << endl;
   	}
	}
	template<class T>
	inline T& Vecteur3d<T>::operator[](unsigned int i)
	{
		// TODO: insérer une instruction return ici
		assert(i >= 0 && i < 3);//debeug
		try//en mode release
		{
			if (i < 0 || i >= 3) throw "range erre";

			return this->vect[i];

		}
		catch (char* e)
		{
			cout << e << endl;
		}
	}
	template<class T>
	 bool Vecteur3d<T>::operator==(const Vecteur3d& v) const
	{
		bool res = true;
			for (int i = 0; i < 3; i++)
			{
				res = res && (this->at(i) == v.at(i));
			}
		
			return res;
	}
	template<class T>
	 inline bool Vecteur3d<T>::operator!=(const Vecteur3d& v) const
	{
		 bool res = !(*this == v);
		 return res;
	 }	
	template<class T>
	 Vecteur3d<T>* Vecteur3d<T>::opposite()
	{
		 Vecteur3d* res = new Vecteur3d();
		 for (int i = 0; i < 3; i++)
		 {
			 res->vect[i] = -(this->vect[i]);

		 }

		 return res;
		
	}
	template<class T>
	 Vecteur3d<T>* Vecteur3d<T>::operator+(const Vecteur3d&v)
	{
		
		 Vecteur3d* res = new Vecteur3d();
		 for (int i = 0; i < 3; i++)
		 {
			 res->vect[i] = this->at(i) + v.at(i);
		 }

		 return res;
	}
	template<class T>
	 Vecteur3d<T>* Vecteur3d<T>::operator-(const Vecteur3d&v)
	{
		 Vecteur3d* res = new Vecteur3d();
		 for (int i = 0; i < 3; i++)
		 {
			 res->vect[i] = this->at(i) - v.at(i);
		 }

		 return res;
	}
	template<class T>
	 Vecteur3d<T>* Vecteur3d<T>::operator*(const Vecteur3d&v)
	{
		 Vecteur3d* res = new Vecteur3d();
		 for (int i = 0; i < 3; i++)
		 {
			 res->vect[i] = this->at(i) * v.at(i);
		 }

		 return res;
	}
	template<class T>
	 Vecteur3d<T>* Vecteur3d<T>::operator^(const Vecteur3d&v)
	{
		 Vecteur3d* res = new Vecteur3d();
		 res->vect[0] = this->vect[1] * v.vect[2] - this->vect[2] * v.vect[1];
		 res->vect[1] = this->vect[2] * v.vect[0] - this->vect[0] * v.vect[2];
		 res->vect[2] = this->vect[0] * v.vect[1] - this->vect[1] * v.vect[0];

		 return *res;
	}
	template<class T>
	 T Vecteur3d<T>::norme()
	{
		 return sqrt(pow(this->vect[0], 2) + pow(this->vect[1], 2) + pow(this->vect[2], 2));
	}
	template<class T>
	 Vecteur3d<T>* Vecteur3d<T>::produit(T val)
	{
		 Vecteur3d* res = new Vecteur3d();
		 for (int i = 0; i < 3; i++)
		 {
			 res->vect[i] = (val * this->vect[i]);

		 }
		 return res;
	}
	template<class T>
	 Vecteur3d<T>* Vecteur3d<T>::addition(T val)
	{
		 Vecteur3d* res = new Vecteur3d();
		 for (int i = 0; i < 3; i++)
		 {
			 res->vect[i] = (val + this->vect[i]);

		 }
		 return res;
	}
	//void display(Vecteur3d& v);
};

