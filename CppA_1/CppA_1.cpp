// CppA_1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Vector.h"
#include "Matrix.h"
//#include "Array.h"
//template <typename T>
//bool mini(T a, T b)
//{
//    return a < b;
//}
using namespace std;
using namespace vect;
using namespace Mat;
int main()
{
    Vecteur3d<int>*v1= new Vecteur3d<int>(3,1,2);
    v1->print();
    Matrix<double>* m = new Matrix<double>(2, 2);
    m->Remplissage(1);
    m->print();
    delete m;
    delete v1;
    /*cout << mini(4, 5) << endl;
    cout << mini("kee", "jjj") << endl;
    cout << mini(4, 5) << endl;
    Array <int> tab1(3);
    tab1.remplissage();
    tab1.print();*/

}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
