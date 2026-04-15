class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int for_dist=1;
        int back_dist=1;

        if(target==words[startIndex]) return 0;

        int index=(startIndex+1)%words.size();

        while(index<words.size()){
            if(words[index]==target){
                break;
            }
            index=(index+1)%words.size();
            for_dist++;

            if(for_dist>words.size()-1){
                return -1;
            }
        }

        

        index=(startIndex-1+words.size())%words.size();

        while(index<words.size()){
            if(words[index]==target){
                break;
            }
            index=(index-1+words.size())%words.size();
            back_dist++;
        }

        return min(for_dist,back_dist);
    }
};