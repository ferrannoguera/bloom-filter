#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <stack>
#include <queue>
#include <math.h>
#include <time.h>
#include<stdlib.h>
using namespace std;

void printbloom(vector<bool> b) {
    for(int i = 0; i < b.size(); ++i) {
        if(b[i]) cout << i <<" TRUE" << endl;
    }
}

void printvs(vector<string> vs) {
    for(int i = 0; i < vs.size(); ++i) cout << vs[i] << endl;
}

void arreglar(vector<string> &vss) {
    for(int i = 0; i < vss.size(); ++i) {
        if(vss[i].length() < 9) {
            for(int j = vss[i].length(); j < 9; ++j) {
                vss[i] = "0" + vss[i];
            }
        }
    }
}

void arreglar2(string &vss) {
    for(int j = vss.length(); j < 64; ++j) {
                vss = "0" + vss;
    }
}
    

string dec_to_hex(int a) {
    stringstream stream;
    stream << hex << a;
    string result(stream.str());
    return result;
}

int power(int a, int b) {
    if (b == 0) return 1;
    else return power(a,b-1) * a;
}

string hash1(string original) {
    vector<int> v(8,0);
    int i = 0;
    int j = 0;
    while(i < original.length()) {
        v[j] = v[j] + (int)original[i];
        ++i;
        ++j;
        if(j == 8) j = 0;
    }
    vector<string> v8bits(8);
    for(int t = 0; t < 8; ++t) {
        v8bits[t] = dec_to_hex(v[t]);
    }
    string hashed = v8bits[0] + v8bits[1] + v8bits[2] + v8bits[3] + v8bits[4] + v8bits[5] + v8bits[6] + v8bits[7];
    return hashed;
}

string arreglar3(string &vss) {
    if(vss.length() > 64) return vss.substr(0,64);
    else {
        string aux = hash1(vss);
        vss = vss + aux;
        return arreglar3(vss);
    }
}

string hash2(string original) {
    vector<int> v(8,0);
    int i = 0;
    int j = 0;
    while(i < original.length()) {
        v[j] = v[j] + (int)original[i];
        ++i;
        ++j;
        if(j == 8) j = 0;
    }
    vector<string> v8bits(8);
    for(int t = 0; t < 8; ++t) {
        v8bits[t] = dec_to_hex(v[t]);
    }
    string hashed = v8bits[0] + v8bits[1] + v8bits[2] + v8bits[3] + v8bits[4] + v8bits[5] + v8bits[6] + v8bits[7];
    hashed = arreglar3(hashed);
    return hashed;
}

string hash3(string original) {
    vector<int> v(8,0);
    int i = 0;
    int j = 7;
    while(i < original.length()) {
        v[j] = v[j] + (int)original[i];
        ++i;
        --j;
        if(j == -1) j = 7;
    }
    vector<string> v8bits(8);
    for(int t = 0; t < 8; ++t) {
        v8bits[t] = dec_to_hex(v[t]);
    }
    string hashed = v8bits[0] + v8bits[1] + v8bits[2] + v8bits[3] + v8bits[4] + v8bits[5] + v8bits[6] + v8bits[7];
    arreglar2(hashed);
    return hashed;
}

string hash4(string original) {
    return hash2(hash3(original));
}

void actBloom(vector<bool> &bloom, string s) { //O(1)
    stringstream ss;
    int j = 0;
    int value;
    for (int i = 0; i < 16; ++i) {
        value = stoi(s.substr(j,4),0,16);
        bloom[value] = true;
        j = j + 4;
    }
}

stack<int> tobinary(long x) {
    stack<int> psvl;
    while(x>0) {
        psvl.push(x%2);
        x/=2;
        
    }
    return psvl;
}

int todec(queue<int> s) {
    int a_ret = 0;
    while(not s.empty()) {
        int x = pow(2,s.size()-1);
        a_ret += s.front()*x;
        s.pop();
    }
    return a_ret;
}


long todecfromhexa(string x) {
	long answer = 0;
	int j = 7;
	for (int i = 0; i<8; ++i) {
		int tmp = 0;
		if (x[j] == 'a') tmp = 10;
		else if (x[j] == 'b') tmp = 11;
		else if (x[j] == 'c') tmp = 12;
		else if (x[j] == 'd') tmp = 13;
		else if (x[j] == 'e') tmp = 14;
		else if (x[j] == 'f') tmp = 15;
		else tmp = (int)x[j]-'0';
		answer += tmp*pow(16,i);
		--j;
	}
	return answer;
}


//Pre: Rep el filtre de bloom i un string s codificat en hexa
//Post: Actualitza el filtre de bloom amb les dos posicions que et retorna la funcio de hash
void actBloom2(vector<bool> &bloom, string s) {
    long x;
    int j = 0;
     for (int i = 0; i < 64; i+=8) {
		string sd = s.substr(i,8);
		x = todecfromhexa(sd); 
        stack<int> a_tractar = tobinary(x);
        queue<int> parell;
        queue<int> impar;
        while(not a_tractar.empty()) {
            impar.push(a_tractar.top());
            a_tractar.pop();
            if (not a_tractar.empty()){
                parell.push(a_tractar.top());
                a_tractar.pop();
            }
        }
        bloom[todec(impar)%bloom.size()] = true;
        bloom[todec(parell)%bloom.size()] = true;
    }
}


//Pre: Rep filtre de bloom i string s a analitzar si hi es
//Post: Retorna true si la paraula "pot estar" al filtre de bloom i false si no hi es
bool testBloom2(vector<bool> &bloom, string s) {
    long x;
    int j = 0;
 	for (int i = 0; i < 64; i+=8) {
		string sd = s.substr(i,8);
		x = todecfromhexa(sd); 
        stack<int> a_tractar = tobinary(x);
        queue<int> parell;
        queue<int> impar;
        while(not a_tractar.empty()) {
            impar.push(a_tractar.top());
            a_tractar.pop();
            if (not a_tractar.empty()){
                parell.push(a_tractar.top());
                a_tractar.pop();
            }
        }
        if (!bloom[todec(impar)%bloom.size()]) return false;
        if(!bloom[todec(parell)%bloom.size()]) return false;
        return true;
    }
}


void actBloom3(vector<vector<bool> > &bloom, string s) { 
    stringstream ss;
    int j = 0;
    int value;
    for (int i = 0; i < 16; ++i) {
        value = stoi(s.substr(j,4),0,16);
        bloom[i][value] = true;
        j = j + 4;
    }
}
 
bool testBloom3(const vector<vector<bool> > &bloom, string s) {
    stringstream ss;
    int j = 0;
    int value;
    for (int i = 0; i < 16; ++i) {
        value = stoi(s.substr(j,4),0,16);
        if(!bloom[i][value]) return false;
        j = j + 4;
    }
    return true;
}



bool testBloom(const vector<bool> &bloom, string s) { //O(1)
    stringstream ss;
    int j = 0;
    int value;
    for (int i = 0; i < 16; ++i) {
        value = stoi(s.substr(j,4),0,16);
        if(!bloom[value]) return false;
        j = j + 4;
    }
    return true;
}
    
bool truePositiu(stack<string> ss, string s) { //O(tamany de ss)
    string aux;
    while(not ss.empty()) {
        aux = ss.top();
        if(s == aux) return true;
        ss.pop();
    }
    return false;
}
