#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <sstream>
#include <set>
#include <queue>


int main() {

std::priority_queue<char, std::vector<char>, std::greater<char>> pq;


pq.push('z');
pq.push('f');

pq.push('b');
pq.push('d');
pq.push('a');
pq.pop();

  while(!pq.empty()) {
    std::cout << pq.top() << " ";   
    pq.pop();
  }
  std::cout << std::endl;
  
}