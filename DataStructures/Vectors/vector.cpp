//David Lau
//Testing Vectors in C++

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>


using namespace std;

int main(){
    vector<int> first;
    first.push_back(1);
    first.push_back(2);
    first.push_back(0);
    sort(first.begin(), first.end());
    cout << "Elements of Vector" << endl;
    for(const int&it:first){
        cout << it << endl;
    }

    cout << "Elements of Vector with Index" << endl;
    for(auto i=first.begin(); i<first.end(); i++){
        cout << *i << endl;
    }
    return 0;
}
