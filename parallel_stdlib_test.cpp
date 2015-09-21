#include <vector>
#include <random>
#include <parallel/algorithm>
//#include <algorithm>

int main() {
//force parallel with the last argument:

int n = 10000000;
std::vector<int> v;
v.reserve(n);
printf("filling with random\n");
//std::generate(v.begin(), v.end(), std::rand);
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> dis(0, 1000000000);
//std::generate(v.begin(), v.end(), dis(gen));
int i;
//#pragma omp parallel for
for(i=0; i!=n; ++i){
  v[i] = dis(gen);
}
printf("sorting\n");
std::sort(v.begin(), v.end());
//std::sort(v.begin(), v.end(), __gnu_parallel::sequential_tag());
printf("first = %u\n", v[0]);
printf("last  = %u\n", v[n-1]);
return 0;
}
