#include <iostream>

using namespace std;

int powering_number(int a, int n){
  if (n == 1){
    return a;
  }
  if(n%2 == 0){
    return powering_number(a,n/2)*powering_number(a,n/2);
  }
  else{
    return powering_number(a,(n-1)/2)*powering_number(a,(n-1)/2)*a;
  }

}

int main() {
  cout << powering_number(2,5);
}