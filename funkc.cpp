#include "funkc.h"
     double timee = 0;
     bool counting = false;
     clock_t start = clock();
float input(string textToOutput, int minvalue, int maxvalue)
{
    float temp;
    cout << textToOutput;
    while(!(cin >> temp)||temp < minvalue || temp > maxvalue)
    {
        cin.clear();
        cin.ignore(INT_MAX,'\n');
        cout << textToOutput;
    }
    return temp;
}
float input(string textToOutput, int minvalue)
{
    float temp;
    cout << textToOutput;
    while(!(cin >> temp)||temp < minvalue)
    {
        cin.clear();
        cin.ignore(INT_MAX,'\n');
        cout << textToOutput;
    }
    return temp;
}
double playPause()
{
    switch (counting)
    {
    case true:
        {
        timee = timee +(-start + clock())*1.0/ CLOCKS_PER_SEC;
        counting = false;
        }
    case false:
        {
        start = clock();
        counting = true;
        }
    }
return timee;
}
double random(int min, int max)
{
    return rand()%(max+1-min)+min;
}
int laikai::printlaikai(ostream &stream)
{
    laikas[4] = laikas[0] + laikas[1] + laikas[2];
    laikas[5] = laikas[0] + laikas[1] + laikas[3];

    stream << konteineriotipas<< " "<< studsk<<" studentu nuskaitymas is failo ir vidurkio skaiciavimas: " << laikas[0] << endl;
    stream << konteineriotipas<< " "<< studsk<<" rusiavimas i du Vectorius tik kopijuojant: " << laikas[2] << endl;
    stream << konteineriotipas<< " "<< studsk<<" rusiavimas i du Vectorius perkeliant: " << laikas[3] << endl;
    stream << konteineriotipas<< " "<< studsk<<" visas programos laikas kopijuojant: " << laikas[4] << endl;
    stream << konteineriotipas<< " "<< studsk<<" visas programos laikas perkeliant: " << laikas[5] << endl;


}
laikai::laikai()
{
    for(int x = 0; x < 6; ++x)
    {
        laikas.push_back(0);
    }
}
void sortf(Vector <studentas> &studentai)
{
    sort(studentai.begin(), studentai.end());
}
void sortf(deque <studentas> &studentai)
{
    sort(studentai.begin(), studentai.end());

}
void sortf(list <studentas> &studentai)
{
    studentai.sort();

}
void add (list <studentas> &studentai)
{
    int tempint;
    studentas studtemp;
    string ttemp;
    bool notdone = true;
    int x = 0;
    while (notdone)
    {
cout << "Parasykite varda: ";
cin >>ttemp;
studtemp.name(ttemp);
cout << endl << "Parasykite pavarde: ";
cin >> ttemp;
studtemp.secondN(ttemp);
cout << endl <<endl<< "Rasykite namu darbu pazymius, jei norite kad sugeneruotu atsitiktinai rasykite rand,\n kai surasysite visus rasykite done:";
string temp;
while(temp != "done")
{
    cin >> temp;
    if(temp == "done")
    {
        cout <<"Namu darbu pazymiai surasyti" << endl;
    }
    else if (temp == "rand")
    {
        int y = random(1, 10);
        for(int xx = 0; xx < y; ++xx)
        {
            studtemp.addNd(random(1, 10));
        }
        temp  = "done";
    }
    else
    {
        studtemp.addNd(stod(temp));
    }
}
cout << "iveskite egzamino pazymi: ";
cin >> tempint;
studtemp.changeEgz(tempint);
cout <<endl<< "Mokinys ivestas, jei norite baigti rasykite done, \njei ne, parasykite bet ka: "<< endl;
cin >> ttemp;

if(ttemp == "done")
{
    notdone = false;
}
else
{
    cout << "irasomas naujas studentas: "<< endl;
studentai.push_back(studtemp);
    ++x;
}
    }
}
void add (deque <studentas> &studentai)
{
   int tempint;
    studentas studtemp;
    string ttemp;
    bool notdone = true;
    int x = 0;
    while (notdone)
    {
cout << "Parasykite varda: ";
cin >>ttemp;
studtemp.name(ttemp);
cout << endl << "Parasykite pavarde: ";
cin >> ttemp;
studtemp.secondN(ttemp);
cout << endl <<endl<< "Rasykite namu darbu pazymius, jei norite kad sugeneruotu atsitiktinai rasykite rand,\n kai surasysite visus rasykite done:";
string temp;
while(temp != "done")
{
    cin >> temp;
    if(temp == "done")
    {
        cout <<"Namu darbu pazymiai surasyti" << endl;
    }
    else if (temp == "rand")
    {
        int y = random(1, 10);
        for(int xx = 0; xx < y; ++xx)
        {
            studtemp.addNd(random(1, 10));
        }
        temp  = "done";
    }
    else
    {
        studtemp.addNd(stod(temp));
    }
}
cout << "iveskite egzamino pazymi: ";
cin >> tempint;
studtemp.changeEgz(tempint);
cout <<endl<< "Mokinys ivestas, jei norite baigti rasykite done, \njei ne, parasykite bet ka: "<< endl;
cin >> ttemp;

if(ttemp == "done")
{
    notdone = false;
}
else
{
    cout << "irasomas naujas studentas: "<< endl;
studentai.push_back(studtemp);
    ++x;
}
    }
}
void add (Vector <studentas> &studentai)
{
    int tempint;
    studentas studtemp;
    string ttemp;
    bool notdone = true;
    int x = 0;
    while (notdone)
    {
cout << "Parasykite varda: ";
cin >>ttemp;
studtemp.name(ttemp);
cout << endl << "Parasykite pavarde: ";
cin >> ttemp;
studtemp.secondN(ttemp);
cout << endl <<endl<< "Rasykite namu darbu pazymius, jei norite kad sugeneruotu atsitiktinai rasykite rand,\n kai surasysite visus rasykite done:";
string temp;
while(temp != "done")
{
    cin >> temp;
    if(temp == "done")
    {
        cout <<"Namu darbu pazymiai surasyti" << endl;
    }
    else if (temp == "rand")
    {
        int y = random(1, 10);
        for(int xx = 0; xx < y; ++xx)
        {
            studtemp.addNd(random(1, 10));
        }
        temp  = "done";
    }
    else
    {
        studtemp.addNd(stod(temp));
    }
}
cout << "iveskite egzamino pazymi: ";
cin >> tempint;
studtemp.changeEgz(tempint);
cout <<endl<< "Mokinys ivestas, jei norite baigti rasykite done, \njei ne, parasykite bet ka: "<< endl;
cin >> ttemp;

if(ttemp == "done")
{
    notdone = false;
}
else
{
    cout << "irasomas naujas studentas: "<< endl;
studentai.push_back(studtemp);
    ++x;
}
    }
}
void filtertomassive(Vector <studentas> &studentai, Vector <studentas> &vargsiukai, Vector <studentas> &kietekai, int way)
{
    /*
    1 copy
    2 perkelti, studentai lieka kietekai
    3 copy fast with swap
    4 perkelti fast with swap
    */
    int size = studentai.size();
    switch (way)
    {
    case 1:
        {
            for (int x = 0; x < size; ++x)
            {
                if(studentai[x].printGal() < 5)
                {
                    vargsiukai.push_back(studentai[x]);
                }
                else
                {
                    kietekai.push_back(studentai[x]);
                }
            }
        }
        break;
    case 2:
        {
            Vector<studentas>::const_iterator first = studentai.begin();
            Vector<studentas>::const_iterator curr = studentai.end();
            --curr;
            --first;
            while (curr != first)
            {
                if(curr->printGal() < 5)
                {
                    vargsiukai.push_back(*curr);
                    --curr;
                    studentai.erase(curr+1);
                }
                else
                {
                    --curr;
                }
            }
        }
        break;
    case 3:
        {
    int y = kietekai.size()-1;
    int x = 0;
    if(vargsiukai.size()>0)
    {
        vargsiukai.clear();
    }
    while(x != y)
    {
        if(kietekai[y].printGal() > 5)
        {
            if(kietekai[x].printGal() <= 5)
            {
                kietekai.swap(kietekai[x], kietekai[y]);
            }
            else
            {
                ++x;
            }
        }
        else
        {
            --y;
        }
    }
    if(kietekai[x].printGal() >5)
    {
        ++x;
    }
    print(kietekai, "test1.txt");
    copy(kietekai.begin()+x, kietekai.end(), back_inserter(vargsiukai));
    kietekai.resize(x);
        }
    break;
    case 4:
        {
    int y = studentai.size()-1;
    int x = 0;
    if(vargsiukai.size()>0)
    {
        vargsiukai.clear();
    }
    while(x != y)
    {
        if(studentai[y].printGal() > 5)
        {
            if(studentai[x].printGal() <= 5)
            {
                swap(studentai[x], studentai[y]);
            }
            else
            {
                ++x;
            }
        }
        else
        {
            --y;
        }
    }
    if(studentai[x].printGal() >5)
    {
        ++x;
    }
    copy(studentai.begin()+x, studentai.end(), back_inserter(vargsiukai));
    studentai.resize(x);
        }
    }
}

void filtertomassive(deque <studentas> &studentai, deque <studentas> &vargsiukai, deque <studentas> &kietekai, int way)
{
    /*
    1 to copy
    2 to delete
    */
    int size = studentai.size();
    switch (way)
    {
    case 1:
        {
            for (int x = 0; x < size; ++x)
            {
                if(studentai[x].printGal() < 5)
                {
                    vargsiukai.push_back(studentai[x]);
                }
                else
                {
                    kietekai.push_back(studentai[x]);
                }
            }
        }
    case 2:
        {
            deque<studentas>::const_iterator first = studentai.begin();
            for (int x = 0; x < size; ++x)
            {
                if(studentai[x].printGal() < 5)
                {
                    vargsiukai.push_back(studentai[x]);
                    studentai.erase(first + x);
                    --size;
                }

            }
        }
case 3:
        {
    int y = studentai.size()-1;
    kietekai = studentai;
    int x = 0;
    if(vargsiukai.size()>0)
    {
        vargsiukai.clear();
    }
    while(x != y)
    {
        if(kietekai[y].printGal() > 5)
        {
            if(kietekai[x].printGal() <= 5)
            {
                swap(kietekai[x], kietekai[y]);
            }
            else
            {
                ++x;
            }
        }
        else
        {
            --y;
        }
    }
    if(kietekai[x].printGal() >5)
    {
        ++x;
    }
    copy(kietekai.begin()+x, kietekai.end(), back_inserter(vargsiukai));
    kietekai.resize(x);
        }
    case 4:
        {
    int y = studentai.size()-1;
    int x = 0;
    if(vargsiukai.size()>0)
    {
        vargsiukai.clear();
    }
    while(x != y)
    {
        if(studentai[y].printGal() > 5)
        {
            if(studentai[x].printGal() <= 5)
            {
                swap(studentai[x], studentai[y]);
            }
            else
            {
                ++x;
            }
        }
        else
        {
            --y;
        }
    }
    if(studentai[x].printGal() >5)
    {
        ++x;
    }
    copy(studentai.begin()+x, studentai.end(), back_inserter(vargsiukai));
    studentai.resize(x);
        }
    }
}
void filtertomassive(list <studentas> &studentai, list <studentas> &vargsiukai, list <studentas> &kietekai, int way)
{
    /*
    1 to copy
    2 to delete
    */
    list <studentas>::const_iterator it = studentai.end();
    --it;
    list <studentas>::const_iterator first = studentai.begin();
    list <studentas>::const_iterator previous = it;
    switch (way)
    {
    case 1:
        {
            while (it != first)
            {
               if(it->printGal() < 5)
               {
                   vargsiukai.push_back(*first);
               }
               else
               {
                   kietekai.push_back(*first);
               }
               ++first;
            }
        }
    case 2:
        {
            while (it != first)
            {
               if(it->printGal() < 5)
               {
                   vargsiukai.push_back(*it);
                   if(it == first)
                   {
                       return;
                   }
                   previous= it;
                   --it;
                   studentai.erase(previous);

               }
               else
               {
                    --it;
               }
            }
        }
    }
}

