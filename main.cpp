#include <iostream>
#include<fstream>
#include<stack>
#include<queue>
#include "Data.h"
using namespace std;



int main() {

    ifstream inFile;
    ofstream outFile;
    inFile.open("../SpotifyCleaned.csv");
    outFile.open("../stacked.txt");
    if(!inFile.is_open()) {
        cout << "file does not exist";
        return 1;//indicates error
    }

    stack<Data> s;
    queue<Data> q;
    priority_queue<Data> sl;

    cout<<"Reading ../SpotifyCleaned.csv..."<<endl;
    //while loop to read csv file while adding to linked lists
    while(!inFile.eof()){
        string songName;
        string artist;
        string danceabilityTemp;
        string energyTemp;
        double danceability;
        double energy;
        //takes in separate data members
        getline(inFile,songName ,',');
        getline(inFile, artist, ',' );
        getline(inFile,danceabilityTemp,',');
        getline(inFile, energyTemp) ;

        //changes string data into doubles
        danceability=stod(danceabilityTemp);
        energy=stod(energyTemp);
        //adds new data to stack, queue, and the sorted linked list
        Data temp= Data(songName, artist, danceability, energy);
        s.push(temp);
        q.push(temp);
        sl.push(temp);
    }

    cout<<"Writing data in stack inserted at head into stacked.txt"<<endl;
    //output for stack

    while(!s.empty()){
        outFile<<s.top()<<endl;
        s.pop();
    }

    inFile.close();
    outFile.close();

    cout<<"Writing data in queue inserted at tail into queued.txt"<<endl;
    //output using queued
    outFile.open("../queued");
    while(!q.empty()){
        outFile<<q.front()<<endl;
        q.pop();
    }
    outFile.close();

    cout<<"Writing data in sorted linked list sorted by danceability into sorted.txt"<<endl;
    //output sorted linked list
    outFile.open("../sorted");
    while(!sl.empty()){
        outFile<<sl.top()<<endl;
        sl.pop();
    }
    outFile.close();

    return 0;
}