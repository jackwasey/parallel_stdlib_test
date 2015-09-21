#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <parallel/algorithm>
#include <functional>
//#include <algorithm>


bool myfunction (int i,int j) { return (i<j); }

struct myclass {
  bool operator() (int i,int j) { return (i<j);}
} myobject;

int main() {

int n = 10;
std::vector<int> v(n);
//v.reserve(n);
printf("filling with random\n");
unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();   
std::mt19937 gen(seed1); 
std::uniform_int_distribution<int> dis(0, n*10);
auto myrnd = std::bind(dis, gen);

std::generate(v.begin(), v.end(), myrnd);
//for(int i = 0; i != n; ++i){
//  v.push_back(myrnd());
//}
std::cout << "before sorting, first five of v contains:";
for (std::vector<int>::iterator it=v.begin(); it!=v.begin()+5; ++it)
  std::cout << ' ' << *it;
std::cout << '\n';
printf("sorting\n");
printf("v length = %i\n", (int)v.size());

// do the sort
//std::sort(v.begin(), v.end());
//std::sort(v.begin(), v.end(), std::greater<int>());
//force parallel with the last argument:
std::sort(v.begin(), v.end(), __gnu_parallel::sequential_tag());

std::cout << "first five of v after sorting contains:";
for (std::vector<int>::iterator it=v.begin(); it!=v.begin()+5; ++it)
  std::cout << ' ' << *it;
std::cout << '\n';

printf("first = %u\n", v[0]);
printf("last  = %u\n", v[n-1]);
return 0;
}

