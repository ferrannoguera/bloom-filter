#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

void rword (char *word) {
    int len = rand () % 12 + 1;
    word [len] = 0;
    while (len) word [--len] = 'a' + rand () % 26;
}

int randomentre175i375(){
	return rand() % 200 + 175;
}

int randomentre0i500(){
	return rand() % 500;
}

void swap(string & a, string&  b){
	string c= a;
	a=b;
	b=c;
	return;
}


int main () {
    srand(time(0));
    string s;
    vector<string> vs(0);
    int a_comp = randomentre175i375();
    while (cin >> s) vs.push_back(s);
    for(int i=0 ;i<6;i++){
		string test="test", txt=".txt",carpeta="tests/cinccents/";
		string num= to_string(i);
		string name = carpeta+ test+ num +txt;
		ofstream outfile;
		outfile.open(&name[0]);
        char word[7];
        char word2[7];
        int x=0;
        int tete = 0;
        if (i == 0) tete = 500;
        else if (i == 1) tete = 5000;
        else if (i == 2) tete = 10000;
        else if (i == 3) tete = 20000;
        else if (i == 4) tete = 40000;
        else tete = 80000;
        while (x<tete) {
            rword(word);
            outfile << word << endl;
            x++;
        }
        //paraules nostres
		for(int j=0;j<a_comp;j++){
			outfile << vs[randomentre0i500()] << endl;
		}
        outfile.close();
    }   
}
