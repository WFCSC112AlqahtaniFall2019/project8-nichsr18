//
// Created by Sarah Nicholls on 11/17/19.
//

#ifndef PROJECT8_DATA_H
#define PROJECT8_DATA_H

#include<iostream>
#import<string>
using namespace std;
class Data{
public:

    string songName;
    string artist;
    double danceability;
    double energy;
    friend ostream& operator<<(ostream& os, const Data& d);
    bool operator<(const Data &rhs) const;
    Data(string n= "", string a="", double d=0.0, double e=0.0);

};



#endif //PROJECT8_DATA_H
