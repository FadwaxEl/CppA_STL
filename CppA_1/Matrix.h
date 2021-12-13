#pragma once
#include <iostream>
using namespace std;
namespace Mat {
	template <class F>
	class Matrix
	{
	private:
		int nbligne;
		int nbcolone;
		F** Matr;
	public:
		Matrix(int l, int c);
		Matrix(const Matrix&) = delete;
		void Remplissage(F);
		~Matrix();
		Matrix& operator=(const Matrix&)const = delete;
		Matrix* operator+(const Matrix&);
		Matrix* operator-(const Matrix&);
		Matrix* operator*(const Matrix&);
		bool operator==(const Matrix&) const;

		void print()const;

	};

	template<class F>
	 Matrix<F>::Matrix(int l, int c)
	{
		this->nbligne = l;
		this->nbcolone = c;
		this->Matr = new F* [l];
		for (int i = 0; i < l; i++)
		{
			this->Matr[i] = new F[c];
		}

		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < c; j++)
			{
				this->Matr[i][j] = 0;
			}
		}
	}

	template<class F>
	 void Matrix<F>::Remplissage(F n)
	{
		for (int i = 0; i < this->nbligne; i++)
		{
			for (int j = 0; j < this->nbcolone; j++)
			{
				this->Matr[i][j] = n;
			}
		}
	}

	template<class F>
	 Matrix<F>::~Matrix()
	{
		for (int i = 0; i < this->nbligne; i++)
		{
			delete[] this->Matr[i];
			this->Matr[i] = NULL;
		}
		delete[] this->Matr;
		this->Matr = NULL;
	}

	template<class F>
	 Matrix<F>* Matrix<F>::operator+(const Matrix& m)
	{
		assert(this->nbligne == m.nbcolone && this->nbcolone == m.nbcolone);
		try {
			if (this->nbligne != m.nbcolone && this->nbcolone != m.nbcolone) throw "ils ne sont pas compatibles";
			Matrix* mat = new Matrix(this->nbligne, this->nbcolone);
			for (int i = 0; i < this->nbligne; i++)
			{
				for (int j = 0; j < this->nbcolone; j++)
				{
					mat->Matr[i][j] = this->Matr[i][j] + m.Matr[i][j];
				}
			}
			return mat;
		}
		catch (string e) {
			cout << e << endl;
		}
	}

	template<class F>
	 Matrix<F>* Matrix<F>::operator-(const Matrix& m)
	{
		assert(this->nbligne == m.nbcolone && this->nbcolone == m.nbcolone);
		try {
			if (this->nbligne != m.nbcolone && this->nbcolone != m.nbcolone) throw "ils ne sont pas compatibles";
			Matrix* mat = new Matrix(this->nbligne, this->nbcolone);
			for (int i = 0; i < this->nbligne; i++)
			{
				for (int j = 0; j < this->nbcolone; j++)
				{
					mat->Matr[i][j] = this->Matr[i][j] - m.Matr[i][j];
				}
			}
			return mat;
		}
		catch (string e) {
			cout << e << endl;
		}
	}

	template<class F>
	 Matrix<F>* Matrix<F>::operator*(const Matrix& m)
	{
		assert(this->nbcolone == m.nbligne);
		try {
			if (this->nbcolone != m.nbligne) throw "ils ne sont pas compatibles";
			Matrix* mat = new Matrix(this->nbligne, m.nbcolone);
			cout << "\n * function" << endl;
			mat->print();

			for (int i = 0; i < this->nbcolone; i++)
			{
				for (int j = 0; j < m.nbligne; j++)
				{
					int somme = 0;
					for (int k = 0; k < m.nbligne; k++)
					{
						somme = somme + (this->Matr[i][k] * m.Matr[k][j]);

					}
					mat->Matr[i][j] = somme;
				}
			}
			return mat;
		}
		catch (string e) {
			cout << e << endl;
		}

	}

	template<class F>
	 bool Matrix<F>::operator==(const Matrix& m) const
	{
		assert(this->nbligne == m.nbcolone && this->nbcolone == m.nbcolone);
		try {
			if (this->nbligne != m.nbcolone && this->nbcolone != m.nbcolone) throw "ils ne sont pas compatibles";
			bool res = true;
			for (int i = 0; i < this->nbligne; i++)
			{
				for (int j = 0; j < this->nbcolone; j++)
				{
					res = res && this->Matr[i][j] == m.Matr[i][j];
				}
			}
			return res;
		}
		catch (string e) {
			cout << e << endl;
		}

	}

	template<class F>
	 void Matrix<F>::print() const
	{
		for (int i = 0; i < this->nbligne; i++)
		{
			cout << "\n" << endl;
			for (int j = 0; j < this->nbcolone; j++)
			{
				cout << "\t" << this->Matr[i][j] << "\t";

			}
		}
	}

}