#include <iostream>
#include<stdexcept>
#include<string>
#include<cfloat>
#include<vector>
#include<cmath>
#include<iomanip>
#include<stdio.h>

using namespace std;

float scorejudge()
{
  float input;
  string null;
  cin>>input;
  while(cin.fail()){
    cout<<"Invalid Input, try again"<<endl;
    cout<<"type in the score for him/her"<<endl;
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
  string null;
  cin.clear();
  cout<<"type in the score for him/her"<<endl;
  try{
    inputscore = scorejudge();
    getline(cin,null);
  }
  catch(out_of_range e){
    cout<<e.what()<<", try again"<<endl;
    inputscore = scoreinput();
  }
  return inputscore;
}

int i,num=0,namesize,namesizemax=0;
string name,grades = "ABCDE";
float score,meansc=0,varsc=0;
vector<float> scores;
vector<string> names;
int main(){
  while(1){
    cin.clear();
    cout<<"type in the name or type 'none' to finish input"<<endl;
    getline (cin,name);
    if((name!="none")&&(!name.empty())){
      namesize = name.size();
      namesizemax = max(namesizemax,namesize);
      names.push_back(name);
      score = scoreinput();
      scores.push_back(score);
      cout<<name<<"'s score is "<<score<<endl;
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
    varsc = sqrt(varsc/num);
    cout<<endl<<"Grading Scale"<<endl;
    cout<<"A  Above "<<showpoint<<min(100.00,meansc+1.5*varsc)<<"%"<<endl;
    cout<<"B  "<<showpoint<<max(0.00,meansc+0.5*varsc)<<"% - "<<min(100.00,meansc+1.5*varsc)<<"%"<<endl;
    cout<<"C  "<<showpoint<<max(0.00,meansc-0.5*varsc)<<"% - "<<min(100.00,meansc+0.5*varsc)<<"%"<<endl;
    cout<<"D  "<<showpoint<<max(0.00,meansc-1.5*varsc)<<"% - "<<min(100.00,meansc-0.5*varsc)<<"%"<<endl;
    cout<<"E  Below "<<showpoint<<max(0.00,meansc-1.5*varsc)<<"%"<<endl<<endl;
    cout<<setfill(' ')<<left<<setw(namesizemax)<<"Name"<<"    Score  "<<"Grade"<<endl;
    for(i=0;i<num;i++){
      cout<<noshowpoint<<left<<setw(max(4,namesizemax))<<names.at(i)<<"   ";
      printf("%6.2f",scores.at(i));
      cout<<"    "<<grades.at((2*((scores.at(i)-meansc)<=0)-1)*fmin(int(2*abs(scores.at(i)-meansc)/varsc),2)+2)<<endl;
    }
    cout<<endl<<"Class Average  "<<meansc<<endl;
    cout<<"Standard Deviation  "<<varsc<<endl<<endl;

  //return 0;
}
