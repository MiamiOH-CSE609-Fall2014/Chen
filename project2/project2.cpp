#include <iostream>
#include<stdexcept>
#include<string>
#include<cfloat>
#include<vector>
#include<cmath>

using namespace std;

float scorejudge()
{
  float input;
  cin>>input;
  while(cin.fail()){
    cout<<"Invalid Input, try again"<<endl;
    cin.clear();
    cin.ignore(256,'\n');
    cin>>input;
      }
  if(input<0){
    throw out_of_range("must be non-negative");
  }
  else if(input>100){
    throw out_of_range("can not be higher than 100");
  }
  else if((input<=100)&(input>=0)){
    return input;
  }
}

float scoreinput(){
  float inputscore;
  cin.clear();
  cout<<"type in the score for him/her"<<endl;
  try{
    inputscore = scorejudge();
  }
  catch(out_of_range e){
    cout<<e.what()<<endl;
    cout<<"try again"<<endl;
    inputscore = scoreinput();
  }
  return inputscore;
}

int i,num=0;
string name,grades = "ABCDE";
float score,meansc=0,varsc=0;
vector<float> scores;
vector<string> names;
int main(){
  while(1){
    cin.clear();
    cout<<"type in the name"<<endl;
    //cout<<cin<<endl;
    getline (cin,name);
    while(cin.fail()){
      cout<<"Invalid Name"<<endl;
      cin.clear();
      cin.ignore(256,'\n');
      getline(cin,name);;
    }
    if((name!="none")&&(!name.empty())){
      names.push_back(name);
      score = scoreinput();
      scores.push_back(score);
      cout<<name<<" is "<<score<<endl;
      num++;
      meansc+=score;
    }
    else if(name.empty()){
      cout<<"name can not be empty"<<endl;
    }
    else break;
  }
    meansc/=num;
    for(i=0;i<num;i++){
      varsc+=pow(scores.at(i)-meansc,2);
    }
    varsc = sqrt(varsc);
    cout<<"Grading Scale"<<endl;
    cout<<"A  Above "<<meansc+1.5*varsc<<"%"<<endl;
    cout<<"B  "<<meansc+0.5*varsc<<"% - "<<meansc+1.5*varsc<<"%"<<endl;
    cout<<"C  "<<meansc-0.5*varsc<<"% - "<<meansc+0.5*varsc<<"%"<<endl;
    cout<<"D  "<<meansc-0.5*varsc<<"% - "<<meansc-1.5*varsc<<"%"<<endl;
    cout<<"E  Below "<<meansc-1.5*varsc<<"%"<<endl<<endl;
    cout<<"Name   "<<"Score  "<<"Grade"<<endl;
    for(i=0;i<num;i++){
      cout<<names.at(i)<<"  "<<scores.at(i)<<"  "<<grades.at((2*((scores.at(i)-meansc)<=0)-1)*fmin(int(2*abs(scores.at(i)-meansc)/varsc),2)+2)<<endl;
    }
    cout<<endl<<"Class Average  "<<meansc<<endl;
    cout<<"Standard Deviation  "<<varsc<<endl;

  //return 0;
}
