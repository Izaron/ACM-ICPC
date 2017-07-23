// The solution of the problem was written by Izaron
// Date: 18:39:11   20 May 2016
// Execution time: 0.015

// Please do not copy-paste the solution.
// Try to understand what is happening here and write your own.

#include <iostream>
#include <vector>
#include <string>
int corrections = 0;
bool words_match(const std::string& w1, const std::string& w2);
void process_word(const std::vector<std::string>& dict, const std::string& word);

int main(){
    std::vector<std::string> dictionary;
    std::string curr_dict_word;
    std::getline(std::cin, curr_dict_word);
    while(curr_dict_word != "#"){
        dictionary.push_back(curr_dict_word);
        std::getline(std::cin, curr_dict_word);
    }
    char c;
    std::string cword;
    while(std::cin.read(&c,1)){
        if('a'<=c && 'z'>=c){
            cword.insert(cword.end(), c);
            continue;
        }
        else if(!cword.empty()){
            process_word(dictionary, cword);
            cword = "";
        }
        std::cout << c;
    }
    if(!cword.empty()){
        process_word(dictionary, cword);
    }
    std::cout << corrections << std::endl;
    return 0;
}
bool words_match(const std::string& w1, const std::string& w2){
    if(w1.length() != w2.length()){
        return false;
    }
    bool mismatch = false;
    for(int i = 0; i < w1.length(); ++i){
        if(w1[i] != w2[i]){
            if(mismatch){
                return false;
            }
            mismatch = true;
        }
    }
    return mismatch;
}
void process_word(const std::vector<std::string>& dict, const std::string& word){
        for(int i = 0; i < dict.size(); ++i){
            if(words_match(dict[i], word)){
                std::cout << dict[i];
                ++corrections;
                return;
            }
        }
        std::cout << word;
}