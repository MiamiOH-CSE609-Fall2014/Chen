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

tuple<int,int,string> findHighScore(string seq, vector<string> needles,vector< vector<int> > sm);


int main(){
  string path;
  int nn;
  string nd;
  cout<<"input the file path: ";
  cin>>path;
  ReturnedData R = parseFastaFile(path);
  map<string,int> freq = digramFreqScores(R.seq);
  vector< vector<int> > freqm = digramFreqMatrix(freq);
  for(vector<int> tv: freqm){
    for(int ti: tv){
      cout<<ti<<"  ";
    }
    cout<<endl;
  }

  cout<<"input the scoring path: ";
  cin>>path;
  vector< vector<int> > sm = parseScoringFile(path);
  for(vector<int> tv: sm){
    for(int ti: tv){
      cout<<ti<<"  ";
    }
    cout<<endl;
  }
  cout<<"how many needles: ";
  cin>>nn;
  vector<string> needles;
  for(int i=0;i<nn;i++){
    cout<<"input needle "<<i+1<<" : ";
    cin>>nd;
    needles.push_back(nd);
  }
  tuple<int,int,string> highps = findHighScore(R.seq, needles, sm);
  cout<<"maxneedle: "<<get<2>(highps)<<"  maxposition: "<<get<0>(highps)<<"  maxscore: "<<get<1>(highps)<<endl;
}


tuple<int,int,string> findHighScore(string seq, vector<string> needles,vector< vector<int> > sm){
  pair<int,int> tposscore;
  tuple<int,int,string> highps;
  for(int i=0;i<needles.size();i++){
    tposscore = scoreSequence(seq,needles.at(i),sm);
    //cout<<"maxposition: "<<tposscore.first<<endl;
    //cout<<"maxscore: "<<tposscore.second<<endl;
    if(tposscore.second > get<1>(highps)){
      get<0>(highps) = tposscore.first;
      get<1>(highps) = tposscore.second;
      get<2>(highps) = needles.at(i);
    }
  }
  return highps;
}
