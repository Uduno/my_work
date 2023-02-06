#include <string>
#include <iostream>
#include <cstdio>
#include <stdlib.h>

using namespace std;
namespace N
{
    struct Map
    {
        const int lo = 7;
        const int la = 7;
        string **tab;

        Map()
        {
            tab = new string *[lo];
            for (int i = 0; i < lo; ++i)
            {
                tab[i] = nullptr;
            }
            for (int i = 0; i < lo; ++i)
            {
                tab[i] = new string[la];
            }
            for (int i = 0; i < lo; ++i)
            {
                for (int j = 0; j < la; ++j)
                {
                    tab[i][j] = "  ";
                }
            }
        }

        void affiche()
        {
            // affichage du tableau
            cout << " +----+----+----+----+----+----+----+" << endl;
            for (int i = 0; i < 7; i++)
            {
                cout << " | ";
                for (int j = 0; j < 7; j++)
                {

                    cout << tab[i][j] << " | ";
                }
                cout << endl;

                cout << " +----+----+----+----+----+----+----+" << endl;
            }
            clear();
        }

        // format i,j
        bool estVide(int a, int b)
        {
            if (a > 6 || b > 6 || a < 0 || b < 0 || tab[a][b] != "  ")
            {
                return false;
            }
            return true;
        }

        void placement(int a, int b, string n)
        {
            tab[a][b] = n;
        }

        void clear(){
            for (int i = 0; i < lo; ++i)
            {
                for (int j = 0; j < la; ++j)
                {
                    tab[i][j] = "  ";
                }
            }
        }

        ~Map() {}
    };
} // namespace N
