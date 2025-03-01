#include <iostream>
#include <string>

using namespace std;


int A[4] = {0, 1, 2, 3};
int B[4] = {0, 1, 2, 3};

std::string bin[4] = {"00","01","10","11"};


int main()
{
  
  printf("A B a0a1 b0b1 %s\n", "A+B" );
  
  int result;
  
  for(int i=0; i < 4; ++i)
  {
    for(int j=0; j<4; ++j)
    {
      result = A[i] + B[j];
      cout <<A[i] << " " << B[j] << " " <<bin[i] << "   " << bin[j] << "   " << result << endl;
    }
  }
  
  
  return 0;
}
