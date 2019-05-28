# Custom Vector class

Sukurta custom vector klasė. 
 - 1oji dalis, funkcijos: 
 ```sh
 void push_back(const_reference sth)
    {
        if(capacity_ == size_)
        {
            capacity_ = 2*size_+2;
            type * temp = new type[capacity_];
            for(int x = 0; x < size_; ++x)
            {
                temp[x] = stlstart[x];
            }
            if(size_!=0)
            {
                delete[] stlstart;
            }
            stlstart= temp;
        }
        stlstart[size_] = sth;
        ++size_;
    }
```
Tai viena pagrindinių funkcijų, kuri prideda 1 elementą į konteinerio galą. Ji patikrina capacity (ar yra allocatinta pakankamai vietos) ir jei vietos nepakanka padidina capacity 2 kartus.

```sh
void clear()
        {
            if(capacity_ != 0)
            {
                delete[] stlstart;
                capacity_ = 0;
            }
            size_ = 0;
        }
```
Ši funkcija ištrina visus konteinerio elementus, bei atlaisvina atmintį.
```sh
void erase(iterator sth)
        {
            while(sth != stlstart+size_)
            {
                swap(*sth, *(sth+1));
                ++sth;
            }
            --size_;
        }
```
Ši funkcija ištrina vieną elementą pagal jo pointerį. Elementas yra nukeliamas į konteinerio galą ir pažymima kad ten yra laisva vieta. Atmintis neatlaisvinama.
```sh
void resize(unsigned int n)
        {
            if(n != capacity_)
            {
                type * temp = new type[n];
                if(n > size_)
                {
                    for(int x = 0; x < size_; ++x)
                    {
                        temp[x] = stlstart[x];
                    }
                }
                else
                {
                    for(int x = 0; x < n; ++x)
                    {
                        temp[x] = stlstart[x];
                    }
                }
                size_ = n;
                if(capacity_ != 0)
                {
                delete[] stlstart;
                }
                stlstart = temp;
                capacity_ = n;
            }
```
Ši funkcija pakeičia konteinerio capacity bei dydį į norimą. Jei dydis skiriasi nuo norimo atliekama būtina realokacija.
```sh
void shrink_to_fit()
        {
            if(capacity_ > size_)
            {
                type * temp = new type[size_];
                    for(int x = 0; x < size_; ++x)
                    {
                        temp[x] = stlstart[x];
                    }
                delete[] stlstart;
                stlstart = temp;
                capacity_ = size_;
            }
        }
```
Ši funkcija capacity sumažina iki size dydžio tuo atveju jei capacity yra didesnė. Taip išsaugoma atminties.
Yra funkcijos kurios grąžina tam tikrus dydžius, referencus ir pan. arba kažką daro:
```sh
        void swap(type& x, type& y)
        iterator end()
        iterator end()const
        iterator begin()
        iterator begin()const
        iterator back()
        iterator back()const
```
Operatoriai:
```sh
    reference operator [] (unsigned int n){return *(stlstart+n);}
    
    const_reference operator [](unsigned int n)const{return *(stlstart+n);}
    
    Vector<type>& operator=(const Vector<type>& v) {
        if (&v == this) return *this;
        type* newElem = new type[v.size_];
        std::copy(v.begin(), v.back(), &newElem[0]);
        if(capacity_!=0)
        {
        delete[] stlstart;
        }
        stlstart = v.stlstart;
        size_ = v.size_;
        capacity_ = v.capacity_;
        return *this;
    };

Vector<type>& operator=(Vector<type>&& v) noexcept {

        if( &v == this)
            return *this;
        if(capacity_!=0)
        {
        delete[] stlstart;
        }
        stlstart = v.stlstart;
        size_ = v.size_;
        capacity_ = v.capacity_;
        v.stlstart = nullptr;
        v.size_ = 0;
        v.capacity_ = 0;
        return *this;
```
Konstruktoriai ir destruktorius:
```sh
Vector(){size_ = 0;capacity_ = 0; stlstart = NULL;}
        explicit Vector(unsigned int n){stlstart = new type[n]; size_ = n; capacity_ = n;}

        Vector(std::initializer_list<type> _list) : size_(_list.size()), capacity_(_list.size()), stlstart(new type[_list.size()]) { cout << "initializerlist";std::copy(_list.begin(), _list.end(), stlstart); }

        Vector(const Vector<type>& v) : stlstart{new type[v.size_]}, size_{v.size_}, capacity_{v.capacity_} {
        std::copy(v.begin(), v.back(), (*this).begin());}

        Vector(Vector&& v) noexcept : size_{v.size_}, capacity_{v.capacity_} , stlstart{v.stlstart} {v.stlstart = nullptr; v.size_=0; v.capacity_=0;}
        ~Vector(){if(capacity_!=0){delete[] stlstart;}}
```
 - 2oji dalis, spartos analizė: 
Su int:

| Nr | El. sk. | std::vector laikas| Vector laikas |
| ------ | ------ | ------ | ------ |
| 1 | 1M | 0.007 |  0.011|
| 2 |1M  | 0.008|  0.011 |
| 3 | 1M | 0.007|  0.011 |
| 4 | 10M | 0.087| 0.08  |
| 5 | 10M |  0.098|   0.087|
| 6 | 10M | 0.09|  0.091 |
| 7 | 100M | 0.706|  0.683 |
| 8 |100M  |  0.706|  0.748 |
| 9 |100M  |0.661 | 0.681  |

Su studentas klase:

| Nr | El. sk. | std::vector laikas| Vector laikas |
| ------ | ------ | ------ | ------ |
| 1 |100k | 0.109 |  0.062|
| 2 |100k  | 0.093|  0.047 |
| 3 | 100k | 0.109|  0.078 |
| 4 | 1M | 0.83|0.536  |
| 5 | 1M |  0.848|   0.557|
| 6 | 1M | 0.832|  0.531 |
| 7 | 3M | 2.707|  1.804 |
| 8 |3M  |  2.759|  1.783 |
| 9 |3M  |2.816 | 2.086  |

Taigi matome, kad su mažom klasėm mažesnius elementų kiekius std::vector prideda šiek tiek greičiau, tačiau prie didesnių kiekų Vector greitis išsilygina arba netgi tampa didesnis, tačiau su didelėm klasėm Vector veikia pastebimai greičiau nei std::vector.
 - 3oji užduotis: reallocationu palyginimas:

>>std::vector capacity: 134217728 std::vector perskirstymu skaicius: 28
>>Vector capacity: 134217726 Vector perskirstymu skaicius:26

Vector padaro šiek tiek mažiau reallocation'u dėl šiek tiek  kitokios strategijos (capacity = old_size_*2 + 2 ).

   -  4oji užduotis: Vector pritaikymas užduočiai su studentais: 
    
Naudojant Vector bandymas 1:
>>Iveskite studentu skaiciu: 100000
Vector 100000 studentu nuskaitymas is failo ir vidurkio skaiciavimas: 2.508
Vector 100000 rusiavimas i du Vectorius tik kopijuojant: 1.152
Vector 100000 rusiavimas i du Vectorius perkeliant: 0.004
Vector 100000 visas programos laikas kopijuojant: 3.66
Vector 100000 visas programos laikas perkeliant: 2.512
    
Naudojant Vector bandymas 2:
>>Iveskite studentu skaiciu: 100000
Vector 100000 studentu nuskaitymas is failo ir vidurkio skaiciavimas: 2.634
Vector 100000 rusiavimas i du Vectorius tik kopijuojant: 1.143
Vector 100000 rusiavimas i du Vectorius perkeliant: 0.004
Vector 100000 visas programos laikas kopijuojant: 3.777
Vector 100000 visas programos laikas perkeliant: 2.638

Naudojant Vector bandymas 3:
>>Iveskite studentu skaiciu: 100000
Vector 100000 studentu nuskaitymas is failo ir vidurkio skaiciavimas: 2.615
Vector 100000 rusiavimas i du Vectorius tik kopijuojant: 1.188
Vector 100000 rusiavimas i du Vectorius perkeliant: 0.004
Vector 100000 visas programos laikas kopijuojant: 3.803
Vector 100000 visas programos laikas perkeliant: 2.619

Naudojant std::vector bandymas 1:
>>Iveskite studentu skaiciu: 100000
vector 100000 studentu nuskaitymas is failo ir vidurkio skaiciavimas: 2.601
vector 100000 rusiavimas i du vectorius tik kopijuojant: 1.16
vector 100000 rusiavimas i du vectorius perkeliant: 0.002
vector 100000 visas programos laikas kopijuojant: 3.761
vector 100000 visas programos laikas perkeliant: 2.603

Naudojant std::vector bandymas 2:
>>Iveskite studentu skaiciu: 100000
vector 100000 studentu nuskaitymas is failo ir vidurkio skaiciavimas: 2.579
vector 100000 rusiavimas i du vectorius tik kopijuojant: 1.174
vector 100000 rusiavimas i du vectorius perkeliant: 0.003
vector 100000 visas programos laikas kopijuojant: 3.753
vector 100000 visas programos laikas perkeliant: 2.582

Naudojant std::vector bandymas 3:
>>Iveskite studentu skaiciu: 100000
vector 100000 studentu nuskaitymas is failo ir vidurkio skaiciavimas: 2.596
vector 100000 rusiavimas i du vectorius tik kopijuojant: 1.19
vector 100000 rusiavimas i du vectorius perkeliant: 0.003
vector 100000 visas programos laikas kopijuojant: 3.786
vector 100000 visas programos laikas perkeliant: 2.599

Taigi matome kad rezultatai beveik nesiskiria, gal std::vector veikia šiek tiek greičiau.
