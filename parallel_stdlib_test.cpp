#include <iostream>
#include <chrono>
#include <vector>
#include <random>
//#include <algorithm>
#include <parallel/algorithm>
#include <functional>
#include <boost/progress.hpp>

void sp(std::vector<int>& v); 
void ss(std::vector<int>& v2); 

int main() {

boost::progress_timer t_main;

int n = 50000000;
std::vector<int> v(n);
//v.reserve(n);
printf("filling with random\n");
unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();   
std::mt19937 gen(seed1); 
std::uniform_int_distribution<int> dis(0, n*10);
auto myrnd = std::bind(dis, gen);

std::generate(v.begin(), v.end(), myrnd);
std::cout << "before sorting, first five of v contains:";
for (std::vector<int>::iterator it=v.begin(); it!=v.begin()+5; ++it)
  std::cout << ' ' << *it;
std::cout << '\n';
printf("sorting\n");
printf("v length = %i\n", (int)v.size());

std::vector<int> v2(v);

// do the sort
//std::sort(v.begin(), v.end());
//std::sort(v.begin(), v.end(), std::greater<int>());

sp(v);
ss(v2);

std::cout << "first five of v after sorting contains:";
for (std::vector<int>::iterator it=v.begin(); it!=v.begin()+5; ++it)
  std::cout << ' ' << *it;
std::cout << '\n';

printf("first = %u\n", v[0]);
printf("last  = %u\n", v[n-1]);
return 0;
}

void sp(std::vector<int>& v) {
boost::progress_timer t;
std::sort(v.begin(), v.end());
printf("timing is wrong! it sums time for each thread, but this interestingly gives estimate of the threading overhead");
}

void ss(std::vector<int>& v2) {
boost::progress_timer t;
std::sort(v2.begin(), v2.end(), __gnu_parallel::sequential_tag());
}

