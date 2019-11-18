//
// Created by Sarah Nicholls on 11/17/19.
//


#include "Data.h"


//overloaded comparison operator
bool Data::operator<(const Data &rhs) const {
    if(danceability < rhs.danceability){
        return true;
    }else{
        return false;
    }
}

//overloaded output stream
ostream &operator<<(ostream &os, const Data &d) {
    return os<<d.songName<<" "<<d.artist<<" "<<d.danceability<<" "<<d.energy<<endl;
}

//constructor
Data::Data(string n, string a, double d, double e) {
    songName=n;
    artist=a;
    danceability=d;
    energy=e;
}
