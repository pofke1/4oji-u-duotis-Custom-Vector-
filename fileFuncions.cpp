#include "fileFuncions.h"
void print(Vector <studentas> studentai, ostream &stream)
{
    string temp;
    int vecsize;
    stream << "Pavarde\t\tVardas\t\tGalutinis (Vid.)\tGalutinis (Med.)" << endl << "-----------------------------------------------------------------------" << endl;
    vecsize = studentai.size();
    for(int x = 0; x < vecsize; ++x)
    {
        stream << studentai[x].secondN("") << "\t\t"<<studentai[x].name("") << "\t\t";
        stream.precision(3);
        stream.fixed;
        stream << studentai[x].printGal() <<"\t\t";
        stream.precision(3);
        stream.fixed;
        stream << studentai[x].printMed() << endl;
    }
}
void print(Vector <studentas> studentai, string filename)
{
    string temp;
    int vecsize;
    ofstream file;
    file.open(filename);
    file << "Pavarde\t\tVardas\t\tGalutinis (Vid.)\tGalutinis (Med.)" << endl << "-----------------------------------------------------------------------" << endl;
    vecsize = studentai.size();
    for(int x = 0; x < vecsize; ++x)
    {
        file << studentai[x].secondN("") << "\t\t"<<studentai[x].name("") << "\t\t";
        file.precision(3);
        file.fixed;
        file << studentai[x].printGal() <<"\t\t";
        file.precision(3);
        file.fixed;
        file << studentai[x].printMed() << endl;
    }



}
void print(deque <studentas> studentai, ostream &stream)
{
    string temp;
    int vecsize;
    stream << "Pavarde\t\tVardas\t\tGalutinis (Vid.)\tGalutinis (Med.)" << endl << "-----------------------------------------------------------------------" << endl;
    vecsize = studentai.size();
    for(int x = 0; x < vecsize; ++x)
    {
        stream << studentai[x].secondN("") << "\t\t"<<studentai[x].name("") << "\t\t";
        stream.precision(3);
        stream.fixed;
        stream << studentai[x].printGal() <<"\t\t";
        stream.precision(3);
        stream.fixed;
        stream << studentai[x].printMed() << endl;
    }



}
void print(deque <studentas> studentai, string filename)
{
    string temp;
    int vecsize;
    ofstream file;
    file.open(filename);
    file << "Pavarde\t\tVardas\t\tGalutinis (Vid.)\tGalutinis (Med.)" << endl << "-----------------------------------------------------------------------" << endl;
    vecsize = studentai.size();
    for(int x = 0; x < vecsize; ++x)
    {
        file << studentai[x].secondN("") << "\t\t"<<studentai[x].name("") << "\t\t";
        file.precision(3);
        file.fixed;
        file << studentai[x].printGal() <<"\t\t";
        file.precision(3);
        file.fixed;
        file << studentai[x].printMed() << endl;
    }



}
void print(const list <studentas> studenta, ostream &stream)
{
    list <studentas>::const_iterator studentai = studenta.begin();
    string temp;
    stream << "Pavarde\t\tVardas\t\tGalutinis (Vid.)\tGalutinis (Med.)" << endl << "-----------------------------------------------------------------------" << endl;
    while(studentai != studenta.end())
    {
        stream << studentai->secondN() << "\t\t"<<studentai->name() << "\t\t";
        stream.precision(3);
        stream.fixed;
        stream << studentai->printGal() <<"\t\t";
        stream.precision(3);
        stream.fixed;
        stream << studentai->printMed() << endl;
        ++studentai;
    }
}
void print(const list <studentas> studenta, string filename)
{
    ofstream file;
    file.open(filename);
    list <studentas>::const_iterator studentai = studenta.begin();
    string temp;
    file << "Pavarde\t\tVardas\t\tGalutinis (Vid.)\tGalutinis (Med.)" << endl << "-----------------------------------------------------------------------" << endl;
    while(studentai != studenta.end())
    {
        file << studentai->secondN() << "\t\t"<<studentai->name() << "\t\t";
        file.precision(3);
        file.fixed;
        file << studentai->printGal() <<"\t\t";
        file.precision(3);
        file.fixed;
        file << studentai->printMed() << endl;
        ++studentai;
    }
}
void addfromfile(Vector <studentas> &studentai, string filename)
{
    ifstream file;
    file.open(filename);
    if(!file)
    {
        cout << "failas neatidarytas, nuskaitymas nepavyko" << endl;
    }
    if (studentai.size() > 0)
    {
        studentai.clear();
    }
    string temp;
    double tempd;
    file >> temp;
    int x = 0;
    studentas studtemp;
        while(temp != "Egzaminas")
        {
            file >> temp;
        }

    while(temp != "")
    {

        if(temp == "Egzaminas")
        {
        file >> temp;
        }

        studtemp.secondN(temp);
        file >> temp;
        studtemp.name(temp);
        file >> tempd;
        studtemp.addNd(tempd);
        file >> tempd;
        studtemp.addNd(tempd);
        file >> tempd;
        studtemp.addNd(tempd);
        file >> tempd;
        studtemp.addNd(tempd);
        file >> tempd;
        studtemp.addNd(tempd);
        file >> tempd;
        studtemp.changeEgz(tempd);
        studtemp.calc();
        ++x;
        temp = "";
        file >> temp;
        //cout <<"neveikia, pradedama push back funkcija"<< studentai.size()<<endl;
        studentai.push_back(studtemp);
        studtemp.resetNd();
        //cout << "veikia pb pabaigta"<<endl;
    }
}
void addfromfile(deque <studentas> &studentai, string filename)
{
    ifstream file;
    file.open(filename);
    if(!file)
    {
        cout << "failas neatidarytas, nuskaitymas nepavyko" << endl;
    }
    if (studentai.size() > 0)
    {
        studentai.clear();
    }
    string temp;
    double tempd;
    file >> temp;
    int x = 0;
    studentas studtemp;
        while(temp != "Egzaminas")
        {
            file >> temp;
        }

    while(temp != "")
    {

        if(temp == "Egzaminas")
        {
        file >> temp;
        }

        studtemp.secondN(temp);
        file >> temp;
        studtemp.name(temp);
        file >> tempd;
        studtemp.addNd(tempd);
        file >> tempd;
        studtemp.addNd(tempd);
        file >> tempd;
        studtemp.addNd(tempd);
        file >> tempd;
        studtemp.addNd(tempd);
        file >> tempd;
        studtemp.addNd(tempd);
        file >> tempd;
        studtemp.changeEgz(tempd);
        studtemp.calc();
        ++x;
        temp = "";
        file >> temp;
        //cout <<"neveikia, pradedama push back funkcija"<< studentai.size()<<endl;

        studentai.push_back(studtemp);
        studtemp.resetNd();
        //cout << "veikia pb pabaigta"<<endl;
    }
}
void addfromfile(list <studentas> &studentai, string filename)
{
    ifstream file;
    file.open(filename);
    if(!file)
    {
        cout << "failas neatidarytas, nuskaitymas nepavyko" << endl;
    }
    if (studentai.size() > 0)
    {
        studentai.clear();
    }

    string temp;
    double tempd;
    file >> temp;
    int x = 0;
    studentas studtemp;

        while(temp != "Egzaminas")
        {
            file >> temp;
        }

    while(temp != "")
    {

        if(temp == "Egzaminas")
        {
        file >> temp;
        }

        studtemp.secondN(temp);
        file >> temp;
        studtemp.name(temp);
        file >> tempd;
        studtemp.addNd(tempd);
        file >> tempd;
        studtemp.addNd(tempd);
        file >> tempd;
        studtemp.addNd(tempd);
        file >> tempd;
        studtemp.addNd(tempd);
        file >> tempd;
        studtemp.addNd(tempd);
        file >> tempd;
        studtemp.changeEgz(tempd);
        studtemp.calc();
        ++x;
        temp = "";
        file >> temp;
        //cout <<"neveikia, pradedama push back funkcija"<< studentai.size()<<endl;

        studentai.push_back(studtemp);
        studtemp.resetNd();
        //cout << "veikia pb pabaigta"<<endl;
    }
}
void generatefile(int studentai, string filename)
{
    ofstream file;
    file.open(filename);
    file << "Pavarde\t\tVardas\t\tND1\tND2\tND3\tND4\tND5\tEgzaminas" << endl;
    string temp1, temp2;

    for(int x = 0; x < studentai; ++x)
    {
    ostringstream ostring;
        ostring << x;
        temp1 = ostring.str();
        temp2 = "Pavarde";
        temp2+=temp1;
        file << temp2 << "\t";
        temp2 = "Vardas";
        temp2+= temp1;
        file << temp2 << "\t\t";
        for(int xx = 0; xx < 6; ++xx)
        {
            file << random(1, 10) << "\t";
        }
        file << endl;
    }
    file.close();
}
void printtofile(ofstream &file, studentas studentas)
{
        file << studentas.secondN() << "\t\t"<<studentas.name() << "\t\t";
        file.precision(3);
        file.fixed;
        file << studentas.printGal() <<"\t\t";
        file.precision(3);
        file.fixed;
        file << studentas.printMed() << endl;
}
void filtertofile(const Vector <studentas> studentai)
{
    ofstream file1;
    ofstream file2;
    file1.open("vargsiukai.txt");
    file2.open("kietiakai.txt");
    file1 << "Pavarde\t\tVardas\t\tGalutinis (Vid.)\tGalutinis (Med.)" << endl << "-----------------------------------------------------------------------" << endl;
    file2 << "Pavarde\t\tVardas\t\tGalutinis (Vid.)\tGalutinis (Med.)" << endl << "-----------------------------------------------------------------------" << endl;
    int vecsize = studentai.size();
    for(int x = 0; x < vecsize; ++x)
    {
        if(studentai[x].printGal() < 5)
        {
            printtofile(file1, studentai[x]);
        }
        else
        {
            printtofile(file2, studentai[x]);
        }
    }
    file1.close();
    file2.close();
}
void filtertofile(const list <studentas> studentai)
{
    ofstream file1;
    ofstream file2;
    list <studentas>::const_iterator studit = studentai.begin();
    file1.open("vargsiukai.txt");
    file2.open("kietiakai.txt");
    file1 << "Pavarde\t\tVardas\t\tGalutinis (Vid.)\tGalutinis (Med.)" << endl << "-----------------------------------------------------------------------" << endl;
    file2 << "Pavarde\t\tVardas\t\tGalutinis (Vid.)\tGalutinis (Med.)" << endl << "-----------------------------------------------------------------------" << endl;
    while(studit != --studentai.end())
    {
        if(studit->printGal() < 5)
        {
            printtofile(file1, *studit);
        }
        else
        {
            printtofile(file2, *studit);
        }
        studit++;
    }
    file1.close();
    file2.close();

}
void filtertofile(const deque <studentas> studentai)
{
    ofstream file1;
    ofstream file2;
    file1.open("vargsiukai.txt");
    file2.open("kietiakai.txt");
    file1 << "Pavarde\t\tVardas\t\tGalutinis (Vid.)\tGalutinis (Med.)" << endl << "-----------------------------------------------------------------------" << endl;
    file2 << "Pavarde\t\tVardas\t\tGalutinis (Vid.)\tGalutinis (Med.)" << endl << "-----------------------------------------------------------------------" << endl;
    int vecsize = studentai.size();
    for(int x = 0; x < vecsize; ++x)
    {
        if(studentai[x].printGal() < 5)
        {
            printtofile(file1, studentai[x]);
        }
        else
        {
            printtofile(file2, studentai[x]);
        }
    }
    file1.close();
    file2.close();
}
