#include "fichiers.h"

// Convertit un int en string
string intTostring(int i)
{
    ostringstream oss;
    oss << i;
    return oss.str();
}


template<typename Out>
void split(const string &s, char delim, Out result) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        *(result++) = item;
    }
}

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, back_inserter(elems));
    return elems;
}


graphe readInstance(int& A, int& P, int& B, int& K, int& G,vector<vol >& vols){
    ifstream fichier;
    fichier.open(srcPath("instance_exemple.in.txt"),ios::in);
    string contenu;
    getline(fichier,contenu); // Lecture de la 1ere ligne
    vector<string> line1 = split(contenu,' '); // Split selon les espaces

    // Nombre de sommets
    int N = atoi(line1[1].c_str());

    // Autre constantes
    A = atoi(line1[3].c_str());
    P = atoi(line1[5].c_str());
    B = atoi(line1[7].c_str());
    K = atoi(line1[9].c_str());
    G = atoi(line1[11].c_str());
    //cout  << B << endl;
    //cout << G;

    // Liste des vols
    for(int ivol=0;ivol<N;++ivol){
        vol v;
        vector<int> cout;
        vector<int> avions;
        vector<int> temps;
        getline(fichier,contenu);
        line1 = split(contenu,' ');
        // Pour chaque avion on stocke le cout
        for(int avion=3;avion<P+3;++avion)
            cout.push_back(atoi(line1[avion].c_str()));
        v.cout = cout;
        v.avions = avions;
        v.temps = temps;
        vols.push_back(v);
    }

    // Construction des arcs
    vector<arc> liste_arcs;
    for(int iarc=0;iarc<A;++iarc){
        getline(fichier,contenu);
        line1 = split(contenu,' ');
        arc a;
        a.d=atoi(line1[3].c_str())-1;
        a.f=atoi(line1[5].c_str())-1;
        a.t=atoi(line1[7].c_str());
        a.n=atoi(line1[9].c_str());
        //cout << a.d << a.f << a.t << a.n << endl;
        liste_arcs.push_back(a);
    }

    graphe g(N,liste_arcs);
    //g.createdeltaE(); // Ne fonctionne pas...
    g.createdeltaS();
    return g;
}


void writeRes(vector<vector<int> > res){
    ofstream f;
    f.open(srcPath("sol.txt"),ios::in | ios::trunc); // Attention, reecrit par dessus le fichier
    if(f){
        // On parcours les avions
        for(int i=1;i<res.size()+1;++i){
            f << "p" << ' ' << i << ' ' << "a" << ' ';
            for(int j=0;j<res[i-1].size();++j)
                f << res[i-1][j] + 1 << " ";
            f << endl;
        }
        f.close();
    }

}
