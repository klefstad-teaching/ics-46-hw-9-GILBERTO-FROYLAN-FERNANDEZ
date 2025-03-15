#include "ladder.h"
#include <algorithm>
void error(string word1, string word2, string msg){
    cerr << "error on " << word1 << " and " << word2 << " with message: " << msg << endl;
}
void load_words(set<string> & word_list, const string& file_name){
    ifstream file(file_name);
    string curr;
    while (file >> curr)
        word_list.insert(curr);
    file.close();
}

void print_word_ladder(const vector<string>& ladder){
    for (string e : ladder) cout << e << " ";
    cout << endl;
}

void verify_word_ladder(){
    // string prev;
    // for ()
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    // if (d < 0) return false;
    // if (str1.size() == 0) return d - str2.size() >= 0;
    // if (str2.size() == 0) return d - str1.size() >= 0;

    // if (str1.size() > str2.size()) return edit_distance_within(str1.substr(1), str2, d);
    // else if (str2.size() > str1.size()) return edit_distance_within(str1, str2.substr(1), d);
    // else return edit_distance_within(str1.substr(1), str2.substr(1), d);

    ///////////////////////////////////
    int m = str1.size();
    int n = str2.size();
    int* top = new int[n + 1];
    int* bottom = new int[n + 1];
    for (int i = 0; i <= n; ++i)
        top[i] = i;
    for (int i = 0; i < m; ++i){
        bottom[0] = i + 1; // left side
        for (int j = 0; j < n; ++j){
            int sub_cost = (str1[i] == str2[j]) ? top[j] : top[j] + 1;
            bottom[j + 1] = std::min({top[j + 1] + 1, bottom[j] + 1, sub_cost});
        }
        std::swap(top, bottom); // put bottom into top in O(1);
    }
    // for (int v : bottom) cout << v;
    // cout << endl;
    delete[] top; delete[] bottom;
    return top[n] <= d;
    ///////////////////////////////////

    // if (abs(n - m) > d){
    //     return false;
    // }
    // int arr[n++ + 1][m++ + 1];
    // for (int i = 0; i < n; ++i)
    //     arr[i][0] = i;
    
    // for (int j = 0; j < m; ++j)
    //     arr[0][j] = j;

    // for (int j = 1; j < m; ++j){
    //     for (int i = 1; i < n; ++i){
    //         int sub_cost = (str1[i-1] == str2[j-1]) ? 0 : 1;
    //         // cout << "sub= " << sub_cost;
    //         arr[i][j] = std::min({
    //             arr[i-1][j] + 1,
    //             arr[i][j-1] + 1,
    //             arr[i-1][j-1] + sub_cost});
    //         if (i == j && arr[i][j] > d) return false;
    //     }
    // }
    // return arr[n-1][m-1] <= d;
}

bool is_adjacent(const string& word1, const string& word2){
    return edit_distance_within(word1, word2, 1);
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
    queue<vector<string>> ladder_queue;
    vector<string> begin_container{begin_word};
    ladder_queue.push(begin_container);
    set<string> visited;
    visited.insert(begin_word);
    vector<string> ladder;
    while (!ladder_queue.empty()){
        ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = ladder.back();
        for (string word : word_list){
            if (is_adjacent(last_word, word)){
                // cout << "found adjacent" << endl;
                if (visited.find(word) == visited.end()){ // if word is not in visited
                    visited.insert(word);
                    vector<string> new_ladder(ladder);
                    new_ladder.push_back(word);
                    if (word == end_word){
                        cout << "found match" << endl;
                        return new_ladder;
                        }
                    ladder_queue.push(new_ladder);
                }
            }
        }
    }
    return {};
}