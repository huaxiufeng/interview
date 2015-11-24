#include <iostream>
#include <vector>
#include <list>
#include <boost/timer.hpp>
using namespace std;
using namespace boost;

void insert_vector(int count)
{
    vector<char> vt;
    do {
        cout<<"insert "<<count<<" items into vector ..."<<endl;
        timer t;
        for (int i = 0; i < count; ++i) {
            for (int j = 0; j < 1024; j++) {
                vt.push_back(1);
            }
        }
        cout<<"insert "<<count<<" items into vector cost "<<t.elapsed()<<"s"<<endl;
    } while(0);

    do {
        cout<<"delete "<<count<<" items from vector ..."<<endl;
        timer t;
        while (vt.begin() != vt.end()) {
            vt.erase(vt.end()-1);
        }
        cout<<"delete "<<count<<" items from vector cost "<<t.elapsed()<<"s"<<endl;
    } while(0);
}

void insert_list(int count)
{
    list<char> lt;
    do {
        cout<<"insert "<<count<<" items into list ..."<<endl;
        timer t;
        for (int i = 0; i < count; ++i) {
            for (int j = 0; j < 1024; j++) {
                lt.push_back(1);
            }
        }
        cout<<"insert "<<count<<" items into list cost "<<t.elapsed()<<"s"<<endl;
    } while(0);
    
    do {
        cout<<"delete "<<count<<" items from list ..."<<endl;
        timer t;
        while (lt.begin() != lt.end()) {
            lt.erase(lt.begin());
        }
        cout<<"delete "<<count<<" items from list cost "<<t.elapsed()<<"s"<<endl;
    } while(0);

}


int main()
{
    insert_vector(100);
    insert_list(100);
    return 1;
}

