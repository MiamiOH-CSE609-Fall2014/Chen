#include <iostream>
#include <vector>
using namespace std;
int main()
{
  int row1,column1,row2,column2,temp,i;
  std::vector<int> v1,v2,v3;
  cout<<"please input the number of rows of the first matrix: ";
  cin>>row1;
  cout<<"please input the number of columns of the first matrix: ";
  cin>>column1;
  cout<<"please input the number of rows of the second matrix: ";
  cin>>row2;
  cout<<"please input the number of columns of the second matrix: ";
  cin>>column2;
  if(column1!=row2){
  cout<<"Invalid Input";
  return 1;
  }
  else{ 
  for (i=0;i<row1*column1;i++){
  cout<<"please input the next number of matrix one: ";
  cin>>temp;
  v1.push_back(temp);
  }
  for (i=0;i<row2*column2;i++){
  cout<<"please input the next number of matrix two: ";
  cin>>temp;
  v1.push_back(temp);
  }
  }
  cout<<v1.back();
  return 0;
}
