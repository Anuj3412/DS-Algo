/*

Map - Type of Data stucture which stores data in form of (key value) pairs
map<int , int >
map <int , string> 
map<string , bool> 
map<node* , bool>   -- here node* is form linked list

for iteration --
-- we make a pointer and then iteratre it thorugh map
-- to access value in map we use pointer-> first and pointer-> second

*/


#include<bits/stdc++.h>
using namespace std;



int main(){


    map<int , string> mp;
    mp[1] = "One";
    mp[2] = "Two";
    mp[3] = "Three";
    mp[4] = "Four";
    mp[5] = "Five";

    cout<<mp.size()<<endl;
    // map<int, string>::iterator it = mp.begin(); // desciptive way to get pointer in map 
    auto it = mp.begin();  // using auto in place of map<int , string> :: iterator it = mp.begin();
    while(it!=mp.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }
    return 0;
}