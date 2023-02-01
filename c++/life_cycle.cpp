#include<iostream>
#include<cstdio>
#include<string>
#include <stdlib.h>
#include <vector>
#include <math.h> 


using namespace std;


class Map{
    public:
    const int lo = 7;
    const int la = 7;
    string **tab;
    
    Map(){
        tab = new string*[lo];
		for (int i = 0; i < lo; ++i)
		{
			tab[i] = nullptr;
		}
		for (int i = 0; i < lo; ++i)
		{
			tab[i]= new string[la];
		}
		for (int i = 0; i < lo; ++i)
		{
			for (int j = 0; j < la; ++j)
			{
				tab[i][j]="  ";
				
			}
		}
    }


    void affiche(){
		//affichage du tableau
		cout<<" +----+----+----+----+----+----+----+"<<endl;
		for(int i = 0; i < 7; i++)
		{
			cout<<" | ";
			for(int j = 0; j <7; j++)
			{

				cout<<tab[i][j]<<" | ";
			}
			cout<<endl;

			cout<<" +----+----+----+----+----+----+----+"<<endl;	
		}
	}
    
    //format i,j
    bool estVide(int a, int b){
        if(a > 6 || b > 6 || a < 0 || b < 0){
            return false;
        }
        return tab[a][b] != "  ";
    }

    ~Map(){}

};

class Animal{
    private:
        string name;
        int pv,x,y;
        string sx;
    public:
        Animal(const string &n,int p, const string &s,int px, int py){
            name = n;
            pv = p;
            sx = s;
            x = px;
            y = py;
        }

        string get_name(){
            return name;
        }

        int* get_pos(){
            static int pos[2] = {y,x};
            return pos;
        }

        bool dead(){
            return pv<=0;
        }

        ~Animal(){}
};

int main(){
    Animal a("M",5,"F",1,4);
    int *pos = a.get_pos();
    Map map;
    map.tab[1][2] = "AA";
    cout<<map.estVide(7,2)<<endl;
    map.affiche();
    return 0;
}