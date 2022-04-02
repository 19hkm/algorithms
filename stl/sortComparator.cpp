#include<bits/stdc++.h>
using namespace std;

class Interval{
    public: 
    int start;
    int end;
    Interval(int s, int e) {
        this->start = s;
        this->end = e;
    }
};

void printInterval(vector<Interval*> &intVec) {
    for(auto e : intVec) {
        cout<<e->start<<" "<<e->end<<endl;
    }
}

bool descSortComp(Interval* i1, Interval* i2){
    bool isGreater = i1->start > i2->start ;
    if(i1->start == i2->start) {
        isGreater = i1->end <= i2->end;
    }
    return isGreater;
}

int main() {
    Interval* i1 = new Interval(1,10);
    Interval* i2 = new Interval(2,5);
    Interval* i3 = new Interval(2,12);

    vector<Interval*> intVec;
    intVec.push_back(i1);
    intVec.push_back(i2);
    intVec.push_back(i3);
    
    sort(intVec.begin(), intVec.end(), descSortComp);
    printInterval(intVec);

    return 0;
}