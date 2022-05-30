#ifndef trap_h
#define trap_h


typedef struct inf_t{
     IP *A;
     IP *B;
     IP *C;
     IP *D;
} IT;

IT *createTrap(IP *p1, IP *p2, IP *p3, IP *p4);
void delitTrap(IT *t);
void printTrap(IT *t);
int inputC(char a, char b);
float S(IT *t);
void help();

#endif