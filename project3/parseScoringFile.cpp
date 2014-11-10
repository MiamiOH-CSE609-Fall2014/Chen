#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <map>
#include "parseScoringFile.h"

using namespace std;

vector< vector<int> > parseScoringFile(string path ) {
  fstream dataFile;
  dataFile.open(path, fstream::in);
  vector< vector<int> > R;
  vector<int> tv;
  char buf[200];
  while ( dataFile.getline(buf, 200, ',') )
    {
      tv.push_back(stoi(buf));
      dataFile.getline(buf, 200, ',');
      tv.push_back(stoi(buf));
      dataFile.getline(buf, 200, ',');
      tv.push_back(stoi(buf));
      dataFile.getline(buf, 200);
      tv.push_back(stoi(buf));
      R.push_back(tv);
      tv.clear();
    }
  return R;
}
