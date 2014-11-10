#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <map>
#include "digramFreqMatrix.h"

using namespace std;

vector< vector<int> > digramFreqMatrix(map<string,int> freq){
  vector< vector<int> > freqm;
  vector<int> tv;
  tv.push_back(freq["AA"]);
  tv.push_back(freq["AG"]);
  tv.push_back(freq["AC"]);
  tv.push_back(freq["AT"]);
  freqm.push_back(tv);
  tv.clear();
  tv.push_back(freq["GA"]);
  tv.push_back(freq["GG"]);
  tv.push_back(freq["GC"]);
  tv.push_back(freq["GT"]);
  freqm.push_back(tv);
  tv.clear();
  tv.push_back(freq["CA"]);
  tv.push_back(freq["CG"]);
  tv.push_back(freq["CC"]);
  tv.push_back(freq["CT"]);
  freqm.push_back(tv);
  tv.clear();
  tv.push_back(freq["TA"]);
  tv.push_back(freq["TG"]);
  tv.push_back(freq["TC"]);
  tv.push_back(freq["TT"]);
  freqm.push_back(tv);
  tv.clear();
  return freqm;
}
