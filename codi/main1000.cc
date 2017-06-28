#include "funcs2punt0.cc"
#include "tiempo.c"
#include "isha256.cpp"

int main() {
    vector<bool> Bloom1(0xFFFF,false);
    vector<bool> Bloomsha256(0xFFFF,false);
    vector<bool> Bloom1dos(0xFFFF,false);
    vector<bool> Bloomsha256dos(0xFFFF,false);
    vector<vector<bool> > Bloom1bidimensional(16, vector<bool>(0xFFFF,false));
    vector<vector<bool> > Bloomsha256bidimensional(16, vector<bool>(0xFFFF,false));
    float tact11, tact21, tactT1;
    float tact1sha256, tact2sha256, tactTsha256;
    float tactT1dos, tactTsha256dos;
    float tactT1tres, tactTsha256tres;
    tactT1 = 0;
    tactTsha256 = 0;
    tactT1dos = 0;
    tactTsha256dos = 0;
    tactT1tres = 0;
    tactTsha256tres = 0;
    ifstream myfile;
    myfile.open ("claus/inp_1000pw.txt");
    stack<string> allWords;
    string sAux;
    while (myfile >> sAux) {
        tact11 = GetTime();
        actBloom(Bloom1,hash2(sAux));
        tact21 = GetTime();
        tactT1 += tact21 - tact11;
        ///
        tact11 = GetTime();
        actBloom2(Bloom1dos,hash2(sAux));
        tact21 = GetTime();
        tactT1dos += tact21 - tact11;
        ///
        tact11 = GetTime();
        actBloom3(Bloom1bidimensional,hash2(sAux));
        tact21 = GetTime();
        tactT1tres += tact21 - tact11;
        ////CHANGE
        tact1sha256 = GetTime();
        actBloom(Bloomsha256,to_sha256(sAux)); 
        tact2sha256 = GetTime();
        tactTsha256 += tact2sha256 - tact1sha256;
        ///
        tact1sha256 = GetTime();
        actBloom2(Bloomsha256dos,to_sha256(sAux)); 
        tact2sha256 = GetTime();
        tactTsha256dos += tact2sha256 - tact1sha256;
        ///
        tact1sha256 = GetTime();
        actBloom3(Bloomsha256bidimensional,to_sha256(sAux)); 
        tact2sha256 = GetTime();
        tactTsha256tres += tact2sha256 - tact1sha256;
        /////
        allWords.push(sAux);
    }
    cout << "APLICAN EL HASH FH1 A LES CLAUS: " << endl;
    cout << "Temps en actualitzar el filtre de bloom utilitzan el primer algorisme: " << tactT1 << " ms" << endl;
    cout << "Temps en actualitzar el filtre de bloom aplican a les claus un nou hash posterior: " << tactT1dos << " ms" << endl;
    cout << "Temps en actualitzar el filtre de bloom bidimensional: " << tactT1tres << " ms" << endl << endl << endl;
    
    cout << "APLICAN SHA256 PER ENCRIPTAR LES CLAUS: " << endl;
    cout << "Temps en actualitzar el filtre de bloom: " << tactTsha256 << " ms" << endl;
    cout << "Temps en actualitzar el filtre de bloom aplican a les claus un nou hash posterior: " << tactTsha256dos << " ms" << endl;
    cout << "Temps en actualitzar el filtre de bloom bidimensional: " << tactTsha256tres << " ms" << endl << endl << endl;
    myfile.close();
double trues = 0;
	for (int i = 0; i<Bloom1.size(); ++i) if (Bloom1[i]) ++trues;
	cout << "EL FILTRE DE BLOOM AMB EL PRIMER ALGORISME I APLICANT FH1 ES: " << (trues/65535)*100 << " %" << endl;
	trues = 0;
	for (int i = 0; i<Bloomsha256.size(); ++i) if (Bloomsha256[i]) ++trues;
	cout << "EL FILTRE DE BLOOM AMB EL PRIMER ALGORISME I APLICANT SHA256 ES: " << (trues/65535)*100 << " %" << endl << endl;		
	trues = 0;	
	for (int i = 0; i<Bloom1dos.size(); ++i) if (Bloom1dos[i]) ++trues;
	cout << "EL FILTRE DE BLOOM AMB EL SEGON ALGORISME I APLICANT FH1 ES: " << (trues/65535)*100 << " %" << endl;
	trues = 0;
	for (int i = 0; i<Bloomsha256dos.size(); ++i) if (Bloomsha256dos[i]) ++trues;
	cout << "EL FILTRE DE BLOOM AMB EL SEGON ALGORISME I APLICANT SHA256 ES: " << (trues/65535)*100 << " %" << endl << endl;
	trues = 0;
	for (int i = 0; i<Bloom1bidimensional.size(); ++i) {	
		for(int j = 0;j<Bloom1bidimensional[i].size(); ++j) {
			if (Bloom1bidimensional[i][j]) ++trues;
		}
	}
	cout << "EL FILTRE DE BLOOM AMB EL TERCER ALGORISME I APLICANT FH1 ES: " << (trues/1048560)*100 << " %" << endl;
	trues = 0;
	for (int i = 0; i<Bloomsha256bidimensional.size(); ++i) {	
		for(int j = 0;j<Bloomsha256bidimensional[i].size(); ++j) {
			if (Bloomsha256bidimensional[i][j]) ++trues;
		}
	}
	cout << "EL FILTRE DE BLOOM AMB EL TERCER ALGORISME I APLICANT SHA256 ES: " << (trues/1048560)*100 << " %" << endl << endl;
    string s;
    double total = 0;
    double fals1 = 0;
    double falssha256 = 0;
    double truesha256 = 0;
    double true1 = 0;
    double fals1dos = 0;
    double falssha256dos = 0;
    double truesha256dos = 0;
    double true1dos = 0;
    double fals1tres = 0;
    double falssha256tres = 0;
    double truesha256tres = 0;
    double true1tres = 0;
    while(cin >> s) {
        if(testBloom(Bloomsha256,to_sha256(s))) {
            if(!truePositiu(allWords,s)) ++falssha256;
            else ++truesha256;
        }
        if(testBloom(Bloom1,hash2(s))) {
            if(!truePositiu(allWords,s)) ++fals1;
            else ++true1;
        }
        if(testBloom2(Bloomsha256dos,to_sha256(s))) {
            if(!truePositiu(allWords,s)) ++falssha256dos;
            else ++truesha256dos;
        }
        if(testBloom2(Bloom1dos,hash2(s))) {
            if(!truePositiu(allWords,s)) ++fals1dos;
            else ++true1dos;
        }
        if(testBloom3(Bloomsha256bidimensional,to_sha256(s))) {
            if(!truePositiu(allWords,s)) ++falssha256tres;
            else ++truesha256tres;
        }
        if(testBloom3(Bloom1bidimensional,hash2(s))) {
            if(!truePositiu(allWords,s)) ++fals1tres;
            else ++true1tres;
        }
        ++total;
    }
    double mitjana1 = (fals1/total)*100;
    double mitjanasha256;
    double tmitjana1 = (true1/total)*100;
    double fmitjanasha256;
    cout << "RESULTATS DEL HASH FH1 EN UN DOCUMENT DE 1000 CLAUS: " << endl;
    cout << "El percentatge de Fals Positiu utilitzant el primer algorisme: " << mitjana1 << "%" << endl;
    cout << "I el percentatge de Positius es: " << ((fals1+true1)/total)*100 << "%" << endl;
    mitjana1 = (fals1dos/total)*100;
    tmitjana1 = (true1dos/total)*100;
    cout << "El percentatge de Fals Positiu aplican un hash posterior al FH1 (segon algorisme): " << mitjana1 << "%" << endl;
    cout << "I el percentatge de Positius es: " << ((true1dos+fals1dos)/total)*100 << "%" << endl;
    mitjana1 = (fals1tres/total)*100;
    tmitjana1 = (true1tres/total)*100;
    cout << "El percentatge de Fals Positiu actualitzan el filtre de bloom bidimensional: " << mitjana1 << "%" << endl;
    cout << "I el percentatge de Positius es: " << ((fals1tres+true1tres)/total)*100 << "%" << endl << endl;
    cout << "I el percentatge de Positius REAL es: " << tmitjana1 << "%" << endl;
    
    cout << "------------------------------------------------------------------------" << endl;
    
    cout << "RESULTATS DEL SHA256 EN UN DOCUMENT DE 1000 CLAUS: " << endl;
    mitjanasha256 = (falssha256/total)*100;
    fmitjanasha256 = (truesha256/total)*100;
    cout << "El percentatge de Fals Positiu actualitzant el bloom amb el primer algorisme: " << mitjanasha256 << "%" << endl;
    cout << "I el percentatge de Positius es: " << ((falssha256+truesha256)/total)*100 << "%" << endl;
    mitjanasha256 = (falssha256dos/total)*100;
    fmitjanasha256 = (truesha256dos/total)*100;
    cout << "El percentatge de Fals Positiu del sha256 aplican un hash posterior es : " << mitjanasha256 << "%" << endl;
    cout << "I el percentatge de Positius es: " << ((truesha256dos+falssha256dos)/total)*100 << "%" << endl;
    mitjanasha256 = (falssha256tres/total)*100;
    fmitjanasha256 = (truesha256tres/total)*100;
    cout << "El percentatge de Fals Positiu actualitzan el filtre de bloom bidimensional: " << mitjanasha256 << "%" << endl;
    cout << "I el percentatge de Positius es: " << ((truesha256tres+falssha256tres)/total)*100 << "%" << endl<< endl;
    cout << "I el percentatge de Positius REAL es: " << fmitjanasha256 << "%" << endl;
    
    cout << "------------------------------------------------------------------------" << endl;
}
