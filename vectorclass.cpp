#include "vectorclass.h"

using namespace std;

// int main()
// {
    
// // Pradėti v1 užpildymo laiko matavimą
// unsigned int sz = 100000000;  // 100000, 1000000, 10000000, 100000000
// vector<int> v1;
// int k1=0, k2=0;
// auto start = std::chrono::high_resolution_clock::now(); auto st=start;
// for (int i = 1; i <= sz; ++i)
// {
//   if(v1.size() == v1.capacity())
//   {
//     k1++;
//   }
//   v1.push_back(i);
// }
  
// // Baigti v1 užpildymo laiko matavimą

// auto end = std::chrono::high_resolution_clock::now();
// std::chrono::duration<double> diff = end-start; /// Difference (s)
// cout << "Failo v1 užpildymas užtruko: "<< diff.count() << " s." << endl;  
// /////////////////////////////////////////////////////////////////////////////////////////////
// start = std::chrono::high_resolution_clock::now();
// // Pradėti v2 užpildymo laiko matavimą

// vectorclass<int> v2;
// for (int i = 1; i <= sz; ++i)
// {
//   if(v2.size_() == v2.capacity_())
//   {
//     k2++;
//   }
//   v2.push_back(i);
// }
// // Baigti v2 užpildymo laiko matavimą
// end = std::chrono::high_resolution_clock::now();
// diff = end-start; // Skirtumas (s)
// cout << "Failo v2 užpildymas užtruko: "<< diff.count() << " s." << endl;  

// cout << "Perskirstymai v1: " << k1 << endl;
// cout << "Perskirstymai v2: " << k2 << endl;


// }

int main()
{
  vectorclass<int> v;
  vectorclass<char> v1;
  v.push_back(10);
  v.push_back(20);
  v.push_back(30);
  v.push_back(40);
  v.push_back(50);
  v1.push_back('a');
  v1.push_back('b');
  v1.push_back('c');
  v1.push_back('d');
 
  cout << "Vector size : " << v.size_() << endl;
  cout << "Vector capacity : " << v.capacity_() << endl;
  cout << "Vector elements of v: ";
  v.print();

  cout << "Vector elements of v1: ";
  v1.print();
 
  v.push_back(100, 1);
  v1.insert('y', 2);
 
  cout << "/////////////////////" << endl;
 
  cout << "Vector elements of v: " << endl;
  v.print();
  cout << "Vector elements of v1 : " << endl;
  v1.print();
  cout << "Element at 1st index of v: " << v.front()<< endl;
  cout << "Element at 1st index of v1: " << v1.front() << endl;
  cout << "Element at last index of v: " << v.back()<< endl;
  cout << "Element at last index of v1: " << v1.back() << endl;
 
  v.pop_back();
  v1.pop_back();
 
  cout << "\nAfter deleting last element" << endl;
 
  cout << "Vector size of v: " << v.size_() << endl;
  cout << "Vector size of v1: " << v1.size_()<< endl;
  cout << "Vector capacity of v: " << v.capacity_() << endl;
  cout << "Vector capacity of v1: " << v1.capacity_() << endl;
  cout << "Vector v max size: " << v.max_size() << endl;
  cout << "Vector v1 max size: " << v1.max_size() << endl;
 
  cout << "Vector elements of v: ";
  v.print();
  cout << "Vector elements of v1: ";
  v1.print();


  cout << "Vector v resize: ";
  v.resize(11, 1);
  cout << v.size_() << endl;
  v.print();

  cout << "Vector v1 erase 2nd element: ";
  v.erase(1);
  v.print();

  cout << "Vector v clearing: ";
  v.clear();
  v.print();


  cout << "Vector v1 clearing: ";
  v1.clear();
  v1.print();
}