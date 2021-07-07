#include<iostream>
#include <vector>
using namespace std;

const int SUITORS_COUNT = 6;

void fillVector(vector<int>& v);
void print(vector<int> v);
int elemenate(vector<int>& v);

int main(){

    vector<int> suitors;
    fillVector(suitors);

    print(suitors);     /*Print*/

    elemenate(suitors);

    print(suitors);


    return 0;
}

void fillVector(vector<int>& v){    /*Filling vektor*/
    for(int i=0;i<SUITORS_COUNT;i++) {
        v.push_back(i+1);
    }
}

int elemenate(vector<int>& v){
    vector<int>::iterator itr;
    int j =0;
   while (v.size()>2)
   {
     for(int i = j;i<v.size();i++){
        if((i+1)%3 == 0 && i>=2)
        {
            v.erase(v.begin()+i); /*elemenate vektor elements according to rules*/
        }
     }
     print(v);   
   }
       return 1;
   }

void print(vector<int> v){
    for(int i=0;i<v.size();i++){
      
        cout<<v[i];
        
     }

    cout<<endl;
}