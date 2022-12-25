#ifndef MRAV_H
#define MRAV_H

#include <iostream> 
#include <string>
#include <list>
#include <cmath> 

using namespace std; 

class mrav {
public:
	static int Opasnost; 
    static int zaliha;
    static list<mrav*> svimravi; 

    int x2, y2;
	int x1, y1;
    int x, y; 
    int snaga;
    int koraci;
    string ime; 
    bool patrolira;
	bool skuplja;
	bool nosi;   

    mrav() {
        patrolira = false;
        skuplja = false;
        nosi = false;
        x = 0; x1 = 0; x2 = 0;
        y = 0; y1 = 0; y2 = 0;
        koraci = 0;
        svimravi.push_back(this); 
    }  

    mrav(const mrav &A)
    {
        patrolira = false;
        skuplja = false;
        nosi = false;
        x = 0; x1 = 0; x2 = 0;
        y = 0; y1 = 0; y2 = 0;
        koraci = 0;
        svimravi.push_back(this);
    }

    int gdjeX() const;
	int gdjeY() const;
    int presao() const; 
    string oznaka() const; 
	mrav& najblizi();
    virtual void pomakZa(int dx, int dy) = 0;
    static void opasnost(int k = 1);
    static list<mrav*> Svi();
    static void vrijeme(int k = 1); 
    
};

class radnik : public mrav {
public:    
    radnik() {
        zaliha--;
        skuplja = false;
        nosi = false; 
        x = 0; x1 = 0; x2 = 0;
        y = 0; y1 = 0; y2 = 0; 
        koraci = 0;
		snaga = 1; 
        ime = string("radnik");
    }

    void pomakZa(int dx, int dy); 
    void sakupljaj(int x, int y);
};

class vojnik : public mrav {
 public:  
    vojnik() {
        zaliha--; 
        patrolira = false; 
        x = 0; x1 = 0; x2 = 0;
        y = 0; y1 = 0; y2 = 0;
        koraci = 0;
		snaga = 2; 
        ime = string("vojnik"); 
    }

    void pomakZa(int dx, int dy); 
    void patroliraj(int x, int y);

};

int udaljenost(int x1, int y1, int x2, int y2); 

#endif
