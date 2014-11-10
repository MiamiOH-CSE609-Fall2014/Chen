#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <map>
#include "digramFreqScores.h"

using namespace std;

map<string,int> digramFreqScores(string seq){
  map<string,int> freq;
  int ti;
  string ts;
  for(int i=0;i<seq.size()-1;i++){
    ts = "";
    ts = ts+seq[i]+seq[i+1];
    ti = freq[ts];
    //cout<<ts<<endl;
    freq[ts] = ti+1;
  }
  return freq;
}
