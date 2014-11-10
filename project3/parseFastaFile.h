#include <string>
#include <vector>

using namespace std;

class ReturnedData {
public:
  string head,seq;
  vector<string> comm;
};

ReturnedData parseFastaFile(string);
