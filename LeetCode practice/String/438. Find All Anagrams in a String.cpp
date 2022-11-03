// https://leetcode.com/problems/find-all-anagrams-in-a-string/



// Method 1 : pop anagrams and check for all sub-strings : TLE 

class Solution {
public:
    
    set<string> allAnagrams;
    
    void populateAnagrams(string& s, int i, int n) {
        if(i==n) {
            allAnagrams.insert(s);
        } else {
            for(int j=i; j<n; j++) {
                swap(s[i], s[j]);
                populateAnagrams(s, i+1, n);
                swap(s[i], s[j]);
            }
        }
    }

    vector<int> findAnagrams(string s, string p) {
        
        allAnagrams.clear();
        int lenS = s.length(), lenP = p.length();
        if(lenS < lenP) {
            return {};
        }
        
        populateAnagrams(p, 0, lenP);
        vector<int> ans;
        
        for(int i=0; i+lenP<=lenS; i++){
            string tempS(s.begin()+i, s.begin()+i+lenP);
            if(allAnagrams.find(tempS) != allAnagrams.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};


// Method 2: char count. If all non zero then anagram and add to lit of indices
// cpp soln
typedef long long ll;

class Solution {
public:
    
    void populateCharCount(string &s, vector<int>& charCount, int &nonZeroCount) {
        for(auto c : s) {
            int index = c-'a';
            if(!charCount[index]) {
                nonZeroCount++;
            }
            charCount[index]++;
        }
    }
    
    void decreaseCharCount(int i, string &s, vector<int>& charCount, int &nonZeroCount) {
        int index = s[i]-'a';
            if(charCount[index]==1){
                nonZeroCount--;
            } else if(!charCount[index]){
                nonZeroCount++;
            }
            charCount[index]--;
    }
    
    vector<int> reduceCharCount(string &s, vector<int>& charCount, int &nonZeroCount, int tarLength, int sLen) {
        int i=0;
        vector<int> anagramIndices;
        anagramIndices.clear();
        
        while(i<tarLength) {
            // decreaseCharCount(i, s, charCount, nonZeroCount);
            int index = s[i]-'a';
            if(charCount[index]==1){
                nonZeroCount--;
            } else if(!charCount[index]){
                nonZeroCount++;
            }
            charCount[index]--;
            i++;
        }
        
        if(!nonZeroCount) {
            anagramIndices.push_back(i-tarLength);
        }
        
        while(i<sLen) {
            int rIndex = s[i]-'a';
            int lIndex = s[i-tarLength]-'a';
            
            // decreaseCharCount(rIndex, s, charCount, nonZeroCount);
            //reduce
            if(charCount[rIndex]==1){
                nonZeroCount--;
            } else if(!charCount[rIndex]){
                nonZeroCount++;
            }
            charCount[rIndex]--;
            
            if(charCount[lIndex]==-1){
                nonZeroCount--;
            } else if(!charCount[lIndex]){
                nonZeroCount++;
            }
            charCount[lIndex]++;
            
            if(!nonZeroCount) {
                anagramIndices.push_back(i-tarLength+1);
            }
            i++;
        }
        return anagramIndices;
    }
    
    vector<int> findAnagrams(string s, string p) {
        vector<int> charCount(26,0);
        int nonZeroCount=0, sLen=s.length(), pLen=p.length();
        
        if(!pLen || sLen<pLen){
            return {};
        }
        
        populateCharCount(p, charCount, nonZeroCount);
        return reduceCharCount(s, charCount, nonZeroCount, pLen, sLen);
    }
};



// java soln
class Solution {
    
    private void clearArray(int[] arr){
        int i, n=arr.length;
        for(i=0;i<n;i++) arr[i]=0;
    } 
    
    private void eval(int[] charCount, String s, String t) {
        
        int n= t.length();
        for(int i=0;i<n;i++) {
            charCount[s.charAt(i)-'a']--;
            charCount[t.charAt(i)-'a']++;
        }
    }
    
    public List<Integer> findAnagrams(String s, String t) {
        int sLen = s.length(), tLen = t.length(), i;
        List<Integer> indices = new ArrayList();
        if(sLen<tLen) return indices;
        
        
        int[] charCount = new int[26];
        clearArray(charCount);
        
        String sub = s.substring(0,tLen);
        eval(charCount, sub, t);
        
        for(i=tLen;i<sLen+1;++i) {
            
            boolean isAnagram = true;
            for(int k=0;k<26;k++){
                if(charCount[k]!=0) isAnagram = false;
            }
            if(isAnagram) indices.add(i-tLen);
            if(i != sLen) {
                charCount[s.charAt(i-tLen)-'a']++;
                charCount[s.charAt(i)-'a']--;    
            }
        }
        
        return indices;
    }
}