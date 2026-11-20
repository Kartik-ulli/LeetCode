class Solution {
public:
    bool isVowel(char ch){
        return ch=='a' || ch=='e' || ch=='o' || ch=='i' || ch=='u';
    }
    long long atLeast(string word,int k){
        int left=0;
        int n=word.size();
        int right=0;
        int cons=0;
        long long  ans=0;
        unordered_map<char,int> mp;
        while(right<n){
            if(isVowel(word[right])){
                mp[word[right]]++;
            }else{
                cons++;
            }
            while(mp.size()==5 && cons>=k){
                ans+=n-right;
                if(isVowel(word[left])){
                    mp[word[left]]--;
                    if(mp[word[left]]==0){
                        mp.erase(word[left]);
                    }
                }else{
                    cons--;
                }
                left++;
            }
            right++;
        }
    return ans;
    }
    int countOfSubstrings(string word, int k) {
        return atLeast(word,k)-atLeast(word,k+1);
    }
};