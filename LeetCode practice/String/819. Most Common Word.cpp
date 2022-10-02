// not good prob
// use of standard built-in string libs - else too lengthy
// tolower, isalpha

class Solution {
public:
    
    vector<string> wordSplit;
    
    void makeAlphaSpacedString(string &para) {
        for(auto &c : para) {
            c = isalpha(c)? tolower(c) : ' ';
        }

    }
    
    void splitWords(string para) {
        string s="";
        for(auto c : para) {
            if(c==' ') {
                if(s.length()) {
                    wordSplit.push_back(s);
                }
                s = "";
            } else {
                s = s+c;
            }
        }
        if(s.length()) {
            wordSplit.push_back(s);
        }
    }
    
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> bannedWordSet;
        for(auto banWord: banned) {
            for(auto &c: banWord) c = tolower(c);
            bannedWordSet.insert(banWord);
        }
        
        makeAlphaSpacedString(paragraph);
            
        wordSplit.clear();
        splitWords(paragraph);
        
        map<string, int> wordCountMap;
        wordCountMap.clear();
        
        string ans;
        int countMax=0;
        
        for(auto word : wordSplit) {
            if(bannedWordSet.find(word) == bannedWordSet.end()) {
                if(wordCountMap.find(word)!=wordCountMap.end()) {
                    wordCountMap[word]++;
                }else {
                    wordCountMap[word] = 1;
                }
                
                if(wordCountMap[word]>countMax) {
                    countMax = wordCountMap[word];
                    ans= word;
                }
            }
        }
        
        return ans;
    }
};