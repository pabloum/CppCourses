#include <iostream>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;

int main()
{
  ofstream file1("file1.txt");
  ofstream file2("file2.txt");


  // Write to file1 using endl
  // To measure execution time in C++
  // refer to this article
  // https://www.geeksforgeeks.org/measure-execution-time-function-cpp/

  auto start = high_resolution_clock::now();
  for ( int i = 0; i < 100000; i++) {
    file1 << "Hello World " << std::endl ;
  }
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop-start);

  cout << "Writing to file using endl took "
    << duration.count() << " microseconds" << std::endl;

  // Write to file2 using \n

  start = high_resolution_clock::now();
  for ( int i = 0; i < 100000; i++) {
    file2 << "Hello World \n" ;
  }
  stop = high_resolution_clock::now();
  duration = duration_cast<microseconds>(stop-start);

  cout << "Writing to file using \\n took "
    << duration.count() << " microseconds"<< std::endl;

  file1.close();
  file2.close();

  return 0;
} 
