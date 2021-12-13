//#include "Vector.h"
//#include <assert.h>
//using namespace std;
//using namespace vect;
//Vecteur3d::Vecteur3d(float x, float y, float z)
//{
//	this->vect[0] = x;
//	this->vect[1] = y;
//	this->vect[2] = z; /*l'operateur crocher de la classe float*/
//
//}
//
//void Vecteur3d::print() const
//{
//	int i = 0;
//	cout << "(" << this->at(i);
//	for (i = 1; i < 3; i++)
//	{
//		cout << "," << this->at(i);
//	}
//	cout << ")";
//}
//
//float Vecteur3d::at(unsigned int i) const
//{
//	assert(i >= 0 && i < 3);//debeug
//	try//en mode release
//	{
//		if (i < 0 || i >= 3) throw "range erre";
//		return this->vect[i];
//
//	}
//	catch (char* e)
//	{
//		cout << e << endl;
//	}
//
//}
//
//float& Vecteur3d::operator[](unsigned int i)
//{
//	assert(i >= 0 && i < 3);//debeug
//	try//en mode release
//	{
//		if (i < 0 || i >= 3) throw "range erre";
//
//		return this->vect[i];
//
//	}
//	catch (char* e)
//	{
//		cout << e << endl;
//	}
//}
//
//
//bool Vecteur3d::operator==(const Vecteur3d& v) const
//{
//	bool res = true;
//	for (int i = 0; i < 3; i++)
//	{
//		res = res && (this->at(i) == v.at(i));
//	}
//
//	return res;
//}
//
//bool Vecteur3d::operator!=(const Vecteur3d& v) const
//{
//	bool res = !(*this == v);
//	return res;
//}
//
//Vecteur3d* vect::Vecteur3d::opposite()
//{
//	Vecteur3d* res = new Vecteur3d();
//	for (int i = 0; i < 3; i++)
//	{
//		res->vect[i] = -(this->vect[i]);
//
//	}
//
//	return res;
//}
//
//Vecteur3d* vect::Vecteur3d::operator+(const Vecteur3d& v)
//{
//	Vecteur3d* res = new Vecteur3d();
//	for (int i = 0; i < 3; i++)
//	{
//		res->vect[i] = this->at(i) + v.at(i);
//	}
//
//	return res;
//}
//template<class T>
//Vecteur3d <T>* vect::Vecteur3d<T>::operator-(const Vecteur3d& v)
//{
//	Vecteur3d<T>* res = new Vecteur3d<T>();
//	for (int i = 0; i < 3; i++)
//	{
//		res->vect[i] = this->at(i) - v.at(i);
//	}
//
//	return res;
//}
//Vecteur3d* vect::Vecteur3d::operator*(const Vecteur3d& v)
//{
//	Vecteur3d* res = new Vecteur3d();
//	for (int i = 0; i < 3; i++)
//	{
//		res->vect[i] = this->at(i) * v.at(i);
//	}
//
//	return res;
//}
//
//Vecteur3d* vect::Vecteur3d::operator^(const Vecteur3d&)
//{
//	return nullptr;
//}
//
//double Vecteur3d::norme()
//{
//
//	return sqrt(pow(this->vect[0], 2) + pow(this->vect[1], 2) + pow(this->vect[2], 2));
//}
//
//Vecteur3d* vect::Vecteur3d::produit(float val)
//{
//	Vecteur3d* res = new Vecteur3d();
//	for (int i = 0; i < 3; i++)
//	{
//		res->vect[i] = (val * this->vect[i]);
//
//	}
//	return res;
//}
//
//Vecteur3d* vect::Vecteur3d::addition(float val)
//{
//	Vecteur3d* res = new Vecteur3d();
//	for (int i = 0; i < 3; i++)
//	{
//		res->vect[i] = (val + this->vect[i]);
//
//	}
//	return res;
//}
//
//
///**void vect::display(Vecteur3d& v)
//{
//	cout << "(";
//	for (int i = 0; i < 3; i++)
//	{
//		cout << i << "," << v.vect[i];
//	}
//	cout << ")";
//}*/
//
