#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <map>
#include "parseFastaFile.h"
#include "digramFreqScores.h"
#include "digramFreqMatrix.h"
#include "parseScoringFile.h"
#include "scoreSequence.h"

using namespace std;

int main(){
  string path;
  cin>>path;
  ReturnedData R = parseFastaFile(path);
  map<string,int> freq = digramFreqScores(R.seq);
  vector< vector<int> > freqm = digramFreqMatrix(freq);
  cin>>path;
  vector< vector<int> > sm = parseScoringFile(path);
  pair<int,int> posscore = scoreSequence(R.seq,"TAATCTCAGCACTTT",sm);
  cout<<posscore.first<<"  "<<posscore.second<<endl;
  //cout<<sm.at(3).at(3)<<endl;
}
