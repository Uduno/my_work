#include <iostream>

using namespace std;


struct player;
struct plt; 


struct player{
    char m;
    player(char mark){
        m = mark;
    }
};

struct plt{
    char tab[3][3] = {{' ',' ',' '},
                      {' ',' ',' '},
                      {' ',' ',' '}};

    bool Draw(){
        int check = 0;
        for (int i = 0; i < 3; i++)
        {
           for (int j = 0; j < 3; j++)
           {
            if(tab[i][j]==' '){return false;}
           }
           
        }
        return true;
    }

    bool Linear_win(player p){
        for (int i = 0; i < 3; i++)
        {
            if(tab[i][0] == p.m && tab[i][1] == p.m && tab[i][2] == p.m){
                return true;
            }
        }
        for (int j = 0; j < 3; j++)
        {
            if(tab[0][j] == p.m && tab[1][j] == p.m && tab[2][j] == p.m){
                return true;
            }
        }
        return false;
    }

    bool Diagonal_win(player p){
        return tab[0][0] == p.m && tab[1][1] == p.m && tab[2][2] == p.m ||
        tab[0][2] == p.m && tab[1][1] == p.m && tab[2][2] == p.m;
    }

    void affichage(){
        int num = 1;
        for (int i = 0; i < 3; i++)
        {
            cout<<"+-+-+-+"<<endl;
           for (int j = 0; j < 3; j++)
           {
            if (tab[i][j] == ' '){
                cout<<"|"<< num;
            }else{
                cout<<"|"<<tab[i][j];
            }
            
            num++;
           }
           cout<<"|"<<endl;
        }
        cout<<"+-+-+-+"<<endl;
    }

    bool verify(int i, int j){
        return tab[i][j] == ' ';
    }
    
};

void placement(plt &plt, player p){
    int choix;
    try
    {
        cin>>choix;
        while(choix>9 || choix <= 0){
            cout<<"Hors Zone"<<endl;
            cout<<"Nouveau choix: ";
            cin>>choix;
        }
        switch (choix)
        {
        case 1:
            if(plt.verify(0,0)){
                plt.tab[0][0] = p.m;
            }else{
                cout<<"Case occupéé"<<endl;
                cout<<"Nouveau choix: ";
                placement(plt,p);
            }
            break;
        case 2:
            if(plt.verify(0,1)){
                plt.tab[0][1] = p.m;
            }else{
                cout<<"Case occupéé"<<endl;
                cout<<"Nouveau choix: ";
                placement(plt,p);
            }
            break;
        case 3:
            if(plt.verify(0,2)){
                plt.tab[0][2] = p.m;
            }else{
                cout<<"Case occupéé"<<endl;
                cout<<"Nouveau choix: ";
                placement(plt,p);
            }
            break;
        case 4:
            if(plt.verify(1,0)){
                plt.tab[1][0] = p.m;
            }else{
                cout<<"Case occupéé"<<endl;
                cout<<"Nouveau choix: ";
                placement(plt,p);
            }
            break;
        case 5:
            if(plt.verify(1,1)){
                plt.tab[1][1] = p.m;
            }else{
                cout<<"Case occupéé"<<endl;
                cout<<"Nouveau choix: ";
                placement(plt,p);
            }
            break;
        case 6:
            if(plt.verify(1,2)){
                plt.tab[1][2] = p.m;
            }else{
                cout<<"Case occupéé"<<endl;
                cout<<"Nouveau choix: ";
                placement(plt,p);
            }
            break;
        case 7:
            if(plt.verify(2,0)){
                plt.tab[2][0] = p.m;
            }else{
                cout<<"Case occupéé"<<endl;
                cout<<"Nouveau choix: ";
                placement(plt,p);
            }
            break;
        case 8:
            if(plt.verify(2,1)){
                plt.tab[2][1] = p.m;
            }else{
                cout<<"Case occupéé"<<endl;
                cout<<"Nouveau choix: ";
                placement(plt,p);
            }
            break;
        case 9:
            if(plt.verify(2,2)){
                plt.tab[2][2] = p.m;
            }else{
                cout<<"Case occupéé"<<endl;
                cout<<"Nouveau choix: ";
                placement(plt,p);
            }
            break;
        
        default:
            break;
        }
        plt.affichage();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "error\n";
    }
    
}
void Game(plt plt,player p1, player p2){
    while (!plt.Draw()){
        int choix;
        cout<<"Tour J1:"<<endl;
        cout<<"Choisir une case (1 à 9): ";
        
    }
}



int main(){
    player p1('O');
    player p2('X');
    plt plat;
    plat.affichage();
    placement(plat,p1);
    return 0;
}