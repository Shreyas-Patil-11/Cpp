// Youhave3towersandNdisksofdifferentsizeswhichcanslideontoanytower.Thepuzzlestartswithdiskssortedinascendingorderofsizefromtoptobottom(i.e.,eachdisksitsontopofanevenlargerone).Youhavethefollowingconstraints:(1)Onlyonediskcanbemovedatatime.(2)Adiskisslidoffthetopofonetowerontoanothertower.(3)Adiskcannotbeplacedontopofasmallerdisk.WriteaprogramtomovethedisksfromthefirsttowertothelastusingStacks.

#include<iostream>
#include<string>

using namespace std;

void towerOfHandoi(int n,string src, string helper, string dest){
    if(n ==1){
        cout << "transfer disk" << n << " from "<< src <<" to "<< dest<<endl;
        return;
    }

    // transfer top n-1 from src to helper using dest as 'helper'
    towerOfHandoi(n-1, src, dest, helper);

    //transfer nth from src to dest
    cout << "transfer disk" << n << " from "<< src << " to "<< helper << endl;

    //transfer n-1 from helper to dest using src as 'helper'
    towerOfHandoi(n-1, helper, src, dest);
}

int main(){
    int n = 3;

    towerOfHandoi(4, "A","B","C");
    return 0;
}