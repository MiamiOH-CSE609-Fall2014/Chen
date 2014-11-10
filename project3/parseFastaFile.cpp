#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <map>
#include "parseFastaFile.h"

using namespace std;

ReturnedData parseFastaFile(string path ) {
  fstream dataFile;
  dataFile.open(path, fstream::in);
  ReturnedData R;
  char buf[200];
  while ( dataFile.getline(buf, 200) )
    {
      if(buf[0]=='>'){
	R.head = buf;}
      else if(buf[0]==';'){
	R.comm.push_back(buf);}
      else R.seq = R.seq + buf;
    }
  return R;
}
