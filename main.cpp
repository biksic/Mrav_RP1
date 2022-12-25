#include<iostream>
#include<list>

#include "mrav.h"

using namespace std;
int main() {

    list<mrav*> S;
    list<mrav*> ::iterator i;

    vojnik v1, v2, v3; 
    radnik r1, r2, r3; 

    v1.pomakZa(20, 20); v2.pomakZa(20, 20); v3.patroliraj(10, 20); 
    r1.pomakZa(4, 54); r2.sakupljaj(-10, -20); r3.sakupljaj(7, -7);
    
    S = mrav::Svi();
    mrav::vrijeme(60);
 
    for(i=S.begin(); i!=S.end(); ++i) 
    cout<<(*i)->oznaka()<<" na "<<(*i)->gdjeX()<<","<<(*i)->gdjeY()<<endl;

    cout<<endl<<r1.presao()<<" "<<v3.presao()<<" "<<r2.presao()<<endl; 

    mrav& pom=v1.najblizi();cout<<endl;
    cout<<endl<<pom.oznaka()<<" na "<<pom.gdjeX()<<","<<pom.gdjeY()<<endl;

    mrav::opasnost(10); 
    cout<<endl<<mrav::Opasnost<<endl; 
    
    mrav::vrijeme(5); 
    S = mrav::Svi();

    cout<<endl; 
    cout<<mrav::Opasnost<<endl; 

    for(i=S.begin(); i!=S.end(); ++i) 
    cout<<(*i)->oznaka()<<" na "<<(*i)->gdjeX()<<","<<(*i)->gdjeY()<<endl;

    cout<<"//"<<v3.presao()<<endl; 

    cout<<endl<<mrav::zaliha<<endl; 

    v2.patroliraj(30, 30); 
    v3.pomakZa(30, 30); 
    r1.sakupljaj(5, 10); 
    r2.pomakZa(6, 7); 
    radnik r4;
    r4.sakupljaj(1, -1); 

    mrav::vrijeme(3); 
    S=mrav::Svi(); 

    for(i=S.begin(); i!=S.end(); ++i) 
    cout<<(*i)->oznaka()<<" na "<<(*i)->gdjeX()<<","<<(*i)->gdjeY()<<endl;

    r4.pomakZa(2, 0); 

    mrav::vrijeme(5); 

    cout<<endl; 

    for(i=S.begin(); i!=S.end(); ++i) 
    cout<<(*i)->oznaka()<<" na "<<(*i)->gdjeX()<<","<<(*i)->gdjeY()<<endl;


    cout<<endl<<r1.nosi<<r4.nosi<<endl; 
}
