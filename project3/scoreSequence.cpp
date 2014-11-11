#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <map>
#include "scoreSequence.h"

using namespace std;

pair<int,int> scoreSequence(string haystack,string needle,vector< vector<int> > sm){
  map<string,int> smap;
  int maxscore=0;
  int maxpos = 0;
  smap["AA"] = sm.at(0).at(0);
  smap["AG"] = sm.at(0).at(1);
  smap["AC"] = sm.at(0).at(2);
  smap["AT"] = sm.at(0).at(3);
  smap["GA"] = sm.at(1).at(0);
  smap["GG"] = sm.at(1).at(1);
  smap["GC"] = sm.at(1).at(2);
  smap["GT"] = sm.at(1).at(3);
  smap["CA"] = sm.at(2).at(0);
  smap["CG"] = sm.at(2).at(1);
  smap["CC"] = sm.at(2).at(2);
  smap["CT"] = sm.at(2).at(3);
  smap["TA"] = sm.at(3).at(0);
  smap["TG"] = sm.at(3).at(1);
  smap["TC"] = sm.at(3).at(2);
  smap["TT"] = sm.at(3).at(3);
  for(int i=0;i<haystack.size()-needle.size();i++){
    int sum=0;
    string ts = "";
    for(int ii=0;ii<needle.size();ii++){
      ts = ts+haystack[i+ii]+needle[ii];
      sum = sum+smap[ts];
      ts = "";
    }
    //cout<<sum<<endl;
    if(sum>=maxscore){
      maxscore = sum;
      maxpos = i;
    }
  }
  pair<int,int> posscore;
  posscore.first = maxpos;
  posscore.second = maxscore;
  cout<<"needle: "<<needle<<"  maxposition: "<<maxpos<<"  maxscore: "<<maxscore<<endl;
  return posscore;
}
