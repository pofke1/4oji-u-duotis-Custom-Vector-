#include "fileFuncions.h"

int main()
{

int studsk = 10;
int tempint = 0;
string tempstring;
srand(time(NULL));

Vector <laikai> laikaii (3);

deque <studentas> studentaideq;
Vector <studentas> studentaivec;
list <studentas> studentaili;

deque <studentas> vargsiukaideq;
deque <studentas> kietekaideq;
Vector <studentas> vargsiukaivec;
Vector <studentas> kietekaivec;
list <studentas> vargsiukailist;
list <studentas> kietekailist;

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);

tempint = input("Iveskite studentu skaiciu: ", 1);


laikaii[0].studsk = tempint;
laikaii[1].studsk = tempint;
laikaii[2].studsk = tempint;

generatefile(tempint, "kursiokai.txt");
laikaii[0].konteineriotipas = "Vector";
playPause();
addfromfile(studentaivec, "kursiokai.txt");
playPause();
laikaii[0].laikas[0] = timee;
timee = 0;
playPause();
filtertomassive(studentaivec, vargsiukaivec, studentaivec, 3);
playPause();
vargsiukaivec.clear();
laikaii[0].laikas[2] = timee;
timee = 0;
playPause();
filtertomassive(studentaivec, vargsiukaivec, kietekaivec, 4);
playPause();
laikaii[0].laikas[3] = timee;
timee = 0;
laikaii[0].printlaikai(cout);
studentaivec.clear();
vargsiukaivec.clear();
kietekaivec.clear();
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);

laikaii[1].konteineriotipas = "deque";
playPause();
//cout << "adding from file: ";
addfromfile(studentaideq, "kursiokai.txt");
//cout << "added sucessfully" <<endl;
playPause();
laikaii[1].laikas[0] = timee;
timee = 0;
playPause();
filtertomassive(studentaideq, vargsiukaideq, kietekaideq, 3);
playPause();
vargsiukaideq.clear();
laikaii[1].laikas[2] = timee;
timee = 0;
playPause();
filtertomassive(studentaideq, vargsiukaideq, kietekaideq, 4);
playPause();
laikaii[1].laikas[3] = timee;
timee = 0;
laikaii[1].printlaikai(cout);
studentaideq.clear();
vargsiukaideq.clear();
kietekaivec.clear();
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);

laikaii[2].konteineriotipas = "list";
playPause();
addfromfile(studentaili, "kursiokai.txt");
playPause();
laikaii[2].laikas[0] = timee;
timee = 0;
playPause();
filtertomassive(studentaili, vargsiukailist, kietekailist, 1);
playPause();
vargsiukailist.clear();
laikaii[2].laikas[2] = timee;
timee = 0;
playPause();
filtertomassive(studentaili, vargsiukailist, kietekailist, 2);
playPause();
laikaii[2].laikas[3] = timee;
timee = 0;
laikaii[2].printlaikai(cout);
studentaili.clear();
vargsiukailist.clear();
kietekailist.clear();
    system("PAUSE");
    return 0;
}
