#include "ladder.h"

int main(){
    set<string> word_list;
    load_words(word_list, "../src/words.txt");
    cout << "enter start word: ";
    string start;
    cin >> start;
    cout << "enter end word: ";
    string end;
    cin >> end;

    vector<string> ladder = generate_word_ladder(start, end, word_list);
    print_word_ladder(ladder);
}