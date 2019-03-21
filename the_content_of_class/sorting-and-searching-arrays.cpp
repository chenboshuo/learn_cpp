// 7.18 sorting and searching arrays
#include <iostream>
#include <iomanip>
#include <array>
#include <algorithm> // contains sort and binary_search
using namespace std;

int main(int argc, char const *argv[]) {
  const size_t arraySize = 7; // size of array colors
  array< string, arraySize > colors = {"red", "orange", "yellow",
      "green", "blue", "indigo", "violet"};

  // output original array
  std::cout << "Unsorted array:" << '\n';
  for (string color : colors) {
    std::cout << color << ' ';
  }

  sort(colors.begin(), colors.end()); // sort contents of colors

  // output sorted array
  std::cout << "\n\nSorted array:" << '\n';
  for( string item : colors){
    std::cout << item << ' ';
  }

  // search for "indigo" in clors 
  bool found = binary_search( colors.begin(), colors.end(), "indigo");
  std::cout << "\n\n'indigo'" << ( found ? "was" : "was not") <<
    " found in colors "<< '\n';
  
  // search for "cyan" in clors 
  found = binary_search( colors.begin(), colors.end(), "cyan");
  std::cout << "'cyan'" << ( found ? "was" : "was not") <<
    " found in colors "<< '\n';
  return 0;
}
// Finished in 4 ms
// Unsorted array:
// red orange yellow green blue indigo violet 

// Sorted array:
// blue green indigo orange red violet yellow 

// 'indigo'was found in colors 
// 'cyan'was not found in colors 
