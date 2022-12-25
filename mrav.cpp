#include <iostream> 
#include <string> 
#include <list> 
#include <cmath>

#include "mrav.h"

using namespace std; 


int mrav::Opasnost = 0; 
int mrav::zaliha = 20;
list<mrav*> mrav::svimravi;

int mrav::gdjeX() const {
    return x; 
}

int mrav::gdjeY() const {
    return y; 
}

int mrav::presao() const {
    return koraci; 
}

string mrav::oznaka() const {
    return ime; 
}

int udaljenost(int x1, int y1, int x2, int y2) {
    return abs(x1-x2)+abs(y1-y2); 
}

mrav& mrav::najblizi() {
    list<mrav*>::iterator li = mrav::svimravi.begin(); 
	mrav *m; 

	if(*li!=this)
    	m = *li;
	else
	{
		li++; 
		m=*li; 
	}
    for(li = mrav::svimravi.begin(); li!=mrav::svimravi.end(); li++) {
        if (*li!=this) {
            if (udaljenost(this->x, this->y, (*li)->gdjeX(), (*li)->gdjeY()) < udaljenost(this->x, this->y, m->gdjeX(), m->gdjeY())) {
                m = *li;
            }
        }
    }
    
    return *m;
}

void radnik::pomakZa(int dx, int dy) {
    skuplja = false; 
    nosi = false;
    
    if (dx >= 0) {
    	if (x + dx > 50) {
    		x1 = 50;
    		x2 = x1;
		} else {
			x1 = x + dx;
			x2 = x1;
		}
	} else {
		if (x + dx < -50) {
			x1 = -50;
			x2 = x1; 
		} else {
			x1 = x + dx;
			x2 = x1;
		}
	}
	
	if (dy >= 0) {
    	if (y + dy > 50) {
    		y1 = 50;
    		y2 = y1;
		} else {
			y1 = y + dy;
			y2 = y1;
		}
	} else {
		if (y + dy < -50) {
			y1 = -50;
			y2 = y1;
		} else {
			y1 = y + dy;
			y2 = y1;
		}
	}
}

void vojnik::pomakZa(int dx, int dy) {
    patrolira = false;

	if (dx >= 0) {
    	if (x + dx > 50) {
    		x1 = 50;
    		x2 = x1;
		} else {
			x1 = x + dx;
			x2 = x1;
		}
	} else {
		if (x + dx < -50) {
			x1 = -50;
			x2 = x1;
		} else {
			x1 = x + dx;
			x2 = x1;
		}
	}
	
	if (dy >= 0) {
    	if (y + dy > 50) {
    		y1 = 50;
    		y2 = y1;
		} else {
			y1 = y + dy;
			y2 = y1;
		}
	} else {
		if (y + dy < -50) {
			y1 = -50;
			y2 = y1;
		} else {
			y1 = y + dy;
			y2 = y1;
		}
	}
}

void radnik::sakupljaj(int x, int y) {

	if (nosi) {
    	x2 = x; x1=0; 
    	y2 = y; y1=0; 
	} else {
		x1 = x; x2 = 0;
		y1 = y; y2 = 0;
	}
	skuplja = true;
}

void vojnik::patroliraj(int x, int y) { 
	
    this->x1 = x; this->x2 = 0; 
    this->y1 = y; this->y2 = 0;
		
    this->patrolira = true;
}

void mrav::opasnost(int k) {
    mrav::Opasnost += k; 
}

list<mrav*> mrav::Svi() {
    return mrav::svimravi; 
}

void mrav::vrijeme(int k) {
    while(k) {
        list<mrav*>::iterator li = mrav::svimravi.begin(); 
		
		int s = 0;
        for(li = mrav::svimravi.begin(); li != mrav::svimravi.end(); li++) {
        	if ((*li)->gdjeX() == 0 && (*li)->gdjeY() == 0) {
        		s += (*li)->snaga;
			}
        }
        if (s >= mrav::Opasnost) {
        	mrav::Opasnost = 0;
        	for(li = mrav::svimravi.begin(); li != mrav::svimravi.end(); li++) {
				if ((*li)->oznaka() == string("radnik")) {
            		if ((*li)->x < (*li)->x1) { (*li)->x++; (*li)->koraci++; }
            		else if ((*li)->x > (*li)->x1) { (*li)->x--; (*li)->koraci++; }
            		else if ((*li)->y < (*li)->y1) { (*li)->y++; (*li)->koraci++; }
            		else if ((*li)->y > (*li)->y1) { (*li)->y--; (*li)->koraci++; }
            		
            		if ((*li)->x == (*li)->x1 && (*li)->y == (*li)->y1 && (*li)->skuplja && (*li)->x != 0 && (*li)->y != 0) {
            			(*li)->nosi = true;
            			(*li)->x2 = (*li)->x1; (*li)->x1 = 0;
            			(*li)->y2 = (*li)->y1; (*li)->y1 = 0;
					}
            	
            		if ((*li)->x == 0 && (*li)->y == 0 && (*li)->nosi) {
            			mrav::zaliha++;
            			(*li)->nosi = false;
            			(*li)->x1 = (*li)->x2; (*li)->x2 = 0;
            			(*li)->y1 = (*li)->y2; (*li)->y2 = 0;
					} 
				} else {
					if ((*li)->y < (*li)->y1) { (*li)->y++; (*li)->koraci++; }
            		else if ((*li)->y > (*li)->y1) { (*li)->y--; (*li)->koraci++; } 
					else if ((*li)->x < (*li)->x1) { (*li)->x++; (*li)->koraci++; }
            		else if ((*li)->x > (*li)->x1) { (*li)->x--; (*li)->koraci++; }
            	
            		if ((*li)->patrolira && (*li)->x == (*li)->x1 && (*li)->y == (*li)->y1 && (*li)->x != 0 && (*li)->y != 0) {
            			(*li)->x2 = (*li)->x1; (*li)->x1 = 0;
            			(*li)->y2 = (*li)->y1; (*li)->y1 = 0;
					}
					if ((*li)->patrolira && (*li)->x == 0 && (*li)->y == 0) {
						(*li)->x1 = (*li)->x2; (*li)->x2 = 0;
            			(*li)->y1 = (*li)->y2; (*li)->y2 = 0;
					}
				}
			}
		} else {
			mrav::Opasnost -= s;
			for(li = mrav::svimravi.begin(); li != mrav::svimravi.end(); li++) {
				if ((*li)->gdjeX() != 0 || (*li)->gdjeY() != 0) {  
					if ((*li)->oznaka() == string("radnik")) {
            			if ((*li)->x < (*li)->x1) { (*li)->x++; (*li)->koraci++; }
            			else if ((*li)->x > (*li)->x1) { (*li)->x--; (*li)->koraci++; }
            			else if ((*li)->y < (*li)->y1) { (*li)->y++; (*li)->koraci++; }
            			else if ((*li)->y > (*li)->y1) { (*li)->y--; (*li)->koraci++; }
            		
            			if ((*li)->x == (*li)->x1 && (*li)->y == (*li)->y1 && (*li)->skuplja && (*li)->x != 0 && (*li)->y != 0) {
            				(*li)->nosi = true;
            				(*li)->x2 = (*li)->x1; (*li)->x1 = 0;
            				(*li)->y2 = (*li)->y1; (*li)->y1 = 0;
						}
            	
            			if ((*li)->x == 0 && (*li)->y == 0 && (*li)->nosi) {
            				mrav::zaliha++;
            				(*li)->nosi = false;
            				(*li)->x1 = (*li)->x2; (*li)->x2 = 0;
            				(*li)->y1 = (*li)->y2; (*li)->y2 = 0;
						}
					} else {
						if ((*li)->y < (*li)->y1) { (*li)->y++; (*li)->koraci++; }
            			else if ((*li)->y > (*li)->y1) { (*li)->y--; (*li)->koraci++; }
						else if ((*li)->x < (*li)->x1) { (*li)->x++; (*li)->koraci++; }
            			else if ((*li)->x > (*li)->x1) { (*li)->x--; (*li)->koraci++; }
            	
            			if ((*li)->patrolira && (*li)->x == (*li)->x1 && (*li)->y == (*li)->y1 && (*li)->x != 0 && (*li)->y != 0) {
            				(*li)->x2 = (*li)->x1; (*li)->x1 = 0;
            				(*li)->y2 = (*li)->y1; (*li)->y1 = 0;
						}
						if ((*li)->patrolira && (*li)->x == 0 && (*li)->y == 0) {
							(*li)->x1 = (*li)->x2; (*li)->x2 = 0;
            				(*li)->y1 = (*li)->y2; (*li)->y2 = 0;
						}
					}
				}
			}
		}
        k--; 
    }
}





