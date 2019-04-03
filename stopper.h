#ifndef _STOPPER_H_
#define _STOPPER_H_

#include <time.h>

/** stopper tipus*/
typedef struct stopper
{
  clock_t begin; /// stopper futasanak kezdete
  clock_t end;	/// stopper futasanak vege
} stopper;

/** stoppper inditasa
 * @param st az inditando stopper cime
 */ 
void startS(stopper* st);

/** stopper megallitasa
 * @param st a megallitando stopper cime
 */ 
void stopS(stopper* st);

/** idotartamot kiiro printf
 * @param st az idointervallumot tartalmazo stopper cime
 * @param fmt a printf-hez hasonlo ertelemben vett formatumsztring
 * @return a kiirt karakterek szama
 */ 
int tprintf(stopper* st, const char* fmt, ...);

#endif
