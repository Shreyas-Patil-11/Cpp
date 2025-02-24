#include<iostream>
#include<string>

using namespace std;

void removeDublicate(string str, string ans, int i, int map[26]){
    if(i == str.size()){
        cout<< "ans : "<<ans<<endl;
        return;
    }

    char ch = str[i];
    int mapIdx =(int) ch- 'a';

    if (map[mapIdx] == true)
    {
        removeDublicate(str, ans, i+1, map);
    }else
    {
        map[mapIdx] =true;
        removeDublicate(str, ans+str[i], i+1, map);
    }
}

int main(){
    string str= "aaabbbccc";
    string ans = "";
    int map[26] = {false};
    removeDublicate(str, ans, 0, map);
    return  0;
}