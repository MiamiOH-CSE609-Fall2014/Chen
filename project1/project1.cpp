#include <iostream>
#include <vector>
using namespace std;
int main()
{
  int row1,column1,row2,column2,temp,i,r,c;
  vector<int> v1,v2,v3;
  //cout<<"please input the number of rows of the first matrix: ";
  cin>>row1;
  //cout<<"please input the number of columns of the first matrix: ";
  cin>>column1;
  //cout<<"please input the number of rows of the second matrix: ";
  cin>>row2;
  //cout<<"please input the number of columns of the second matrix: ";
  cin>>column2;
  if(column1!=row2||row1<1||row2<1||column1<1||column2<1){
    cout<<"Invalid Input"<<endl;
  return 1;
  }
  else{ 
  for (i=0;i<row1*column1;i++){
    //cout<<"please input the next number of matrix one: ";
  cin>>temp;
  v1.push_back(temp);
  }
  for (i=0;i<row2*column2;i++){
    //cout<<"please input the next number of matrix two: ";
  cin>>temp;
  v2.push_back(temp);
  }
  }

for (r=0;r<row1;r++){
  for (c=0;c<column2;c++){
    temp = 0;
  for (i=0;i<column1;i++){
    temp += v1.at(i+r*column1)*v2.at(c+i*column2);
  }
    v3.push_back(temp);
  }
 }

for (r=0;r<row1;r++){
  for (c=0;c<column1;c++){
    cout<<v1.at(r*column1+c)<<" ";
  }
  cout<<endl;
 }
cout<<endl;
for (r=0;r<row2;r++){
  for (c=0;c<column2;c++){
    cout<<v2.at(r*column2+c)<<" ";
  }
  cout<<endl;
 }
cout<<endl;
for (r=0;r<row1;r++){
  for (c=0;c<column2;c++){
    cout<<v3.at(r*column2+c)<<" ";
  }
  cout<<endl;
 }

  return 0;
}
