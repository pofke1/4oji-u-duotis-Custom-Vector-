#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <sstream>
#include <stdlib.h>
#include <algorithm>
#include <time.h>
#include <windows.h>
#include <fstream>
#include <ostream>
#include "Vector.h"
#pragma once

class zmogus
{
    protected:
    virtual void changeprop(string vard_, string pavard_, int gimdata_[]) = 0;
    string Vard, Pavard;
    int gimdata[];
    virtual ~zmogus() {};
public:
    zmogus()
    {
        Vard = "Vardenis ";
        Pavard = "Pavardenis";
    }
    zmogus(string vard_, string pavard_, int gimdata_[])
    {
        Vard = vard_;
        Pavard = pavard_;
        int gimdata[7];
        for(int x = 0; x < 8; ++x)
        {
            try{
                gimdata[0] = gimdata_[x];
            }
            catch(...)
            {
                if(gimdata_ != NULL)
                {
                cout << "error: in zmogus constructor failed to add date at number: " << x << endl;
                }
                return;
            }
        }
    }
};
class studentas: public zmogus
{
    private:
    //string vard, pavard;
    double vidNd, egz, galutinis;
    double mediana;
    vector <double> nd;
    public:
        studentas() : egz(0), galutinis(0),
        mediana(0), zmogus() {}
        studentas(string vard_, string pavard_, int egz_) : egz(egz_), zmogus(vard_, pavard_, NULL){}
        void changeprop(string vard_, string pavard_, int gimdata_[])
        {
            Vard = vard_;
            Pavard = pavard_;
            if(gimdata_ != NULL)
            {
        for(int x = 0; x < 8; ++x)
        {
            try{
                gimdata[0] = gimdata_[x];
            }
            catch(...)
            {
                cout << "error: in failed to change date at number: " << x << endl;
                return;
            }
        }
            }
        }


        ~studentas(){nd.clear();}

    void calc();
    void addNd(double nd_);
    void changeEgz(double egz_);
    void resetNd();
    string name(string name_);
    string secondN (string second);
    string name () const;
    string secondN() const;
    double printGal() const;
    double printMed() const;
    bool operator < (const studentas& rhs) const
    {
        return Pavard < rhs.Pavard;
    }
    bool operator > (const studentas &lhs)const
    {
        return Pavard > lhs.Pavard;
    }
    bool operator == (const studentas &stud)
    {
        return stud.galutinis == galutinis;
    }
    bool operator != (const studentas &stud)
    {
        return stud.galutinis != galutinis;
    }
    bool operator >= (const studentas &stud)
    {
        return stud.galutinis >= galutinis;
    }
    bool operator <= (const studentas &stud)
    {
        return stud.galutinis <= galutinis;
    }
    studentas& operator = (const studentas &stud)
    {
        nd = stud.nd;
        galutinis  = stud.galutinis;
        egz = stud.egz;
        Vard = stud.Vard;
        Pavard = stud.Pavard;
        mediana = stud.mediana;
    }
};
