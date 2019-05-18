#pragma once
#include <studentas.h>
using namespace std;
void print(Vector <studentas> studentai, string filename);

    extern double timee;
     extern bool counting;
     extern clock_t start;
double playPause();
double random(int min, int max);
class studentas;
struct laikai
{
    laikai();
    int studsk;
    string konteineriotipas;
    Vector <double> laikas;
    printlaikai(ostream &stream);
};
void sortf(Vector <studentas> &studentai);
void sortf(deque <studentas> &studentai);
void sortf(list <studentas> &studentai);
void add (list <studentas> &studentai);
void add (deque <studentas> &studentai);
void add (Vector <studentas> &studentai);
void filtertomassive(Vector <studentas> &studentai, Vector <studentas> &vargsiukai, Vector <studentas> &kietekai, int way);
void filtertomassive(deque <studentas> &studentai, deque <studentas> &vargsiukai, deque <studentas> &kietekai, int way);
void filtertomassive(list <studentas> &studentai, list <studentas> &vargsiukai, list <studentas> &kietekai, int way);
float input(string textToOutput, int minvalue, int maxvalue);
float input(string textToOutput, int minvalue);


