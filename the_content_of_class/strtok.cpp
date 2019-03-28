#include <iostream>
#include <cstring>// prototype for strtok
using namespace std;


int main(int argc, char const *argv[]) {
  char sentence[] = "This is a sentence with 7 tokens";
  char *tokenPtr;

  std::cout << "The string to be tokensized is:\n"
    << sentence << "\n\nThe tokens are\n"<< '\n';

  // begin tokenization of sentence
  tokenPtr = strtok(sentence, " ");

  // continue tokenizing sentence until tokenPtr becomes NULL
  while (tokenPtr) {
    std::cout << tokenPtr << '\n';
    tokenPtr = strtok(NULL, " ");
  }

  std::cout << "\nAfter strtok, sentence = "<< sentence << '\n';
  return 0;
}
/**
 * The string to be tokensized is:
 * This is a sentence with 7 tokens
 *
 * The tokens are
 *
 * This
 * is
 * a
 * sentence
 * with
 * 7
 * tokens
 *
 * After strtok, sentence = This
 */
