// class Solution {
// public:
//     string reverseVowels(string s) {
//         int n=s.size();
//         int l=0;
//         int r=n-1;

//         set<char> vowels={'a','e','i','o','u','A','E','I','O','U'};

//         while(l<r){
//             if(vowels.find(s[l])!=vowels.end() && vowels.find(s[r])!=vowels.end()){
//                 swap(s[l],s[r]);
//                 l++;
//                 r--;
//             }
//             else if(vowels.find(s[l])!=vowels.end()){
//                 r--;
//             }
//             else{
//                 l++;
//             }
//         }

//         return s;
//     }
// };

class Solution {
public:
    string reverseVowels(string s) {
        // Convert the input string to a character array.
        string word = s;
        int start = 0;
        int end = s.length() - 1;
        string vowels = "aeiouAEIOU";
        
        // Loop until the start pointer is no longer less than the end pointer.
        while (start < end) {
            // Move the start pointer towards the end until it points to a vowel.
            while (start < end && vowels.find(word[start]) == string::npos) {
                start++;
            }
            
            // Move the end pointer towards the start until it points to a vowel.
            while (start < end && vowels.find(word[end]) == string::npos) {
                end--;
            }
            
            // Swap the vowels found at the start and end positions.
            swap(word[start], word[end]);
            
            // Move the pointers towards each other for the next iteration.
            start++;
            end--;
        }
        
        // Return the modified string.
        return word;
    }
};