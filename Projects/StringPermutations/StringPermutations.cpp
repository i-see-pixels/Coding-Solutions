#include <iostream>
#include <vector>
#include <set>

using namespace std;

set<string> Result;

void swap(char& c1, char& c2){
    char temp;
    temp = c1;
    c1 = c2;
    c2 = temp;
}

void perm(string s, int l){
    static int h = s.length() - 1;
    int i;
    if(l == h){
        Result.insert(s);
    }
    else{
        for(i = l; i <= h ; i++){
            swap(s[l], s[i]);
            perm(s, l + 1);
            swap(s[l], s[i]);
        }
    }
}

int main(){
    string s;
    cout<<"Enter a string: ";
    cin>>s;
    cout<<endl;
    perm( s, 0 );
    for(auto elem : Result){
        cout<<elem<<" ";
    }
    
    cout<<Result.size();
    cin.get();
    return 0;
}