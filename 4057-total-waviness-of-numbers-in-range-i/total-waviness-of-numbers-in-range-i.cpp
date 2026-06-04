class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int count=0;

        for(long long i=(long long)num1;i<=(long long)num2;i++){
            count+=waviness(i);
        }

        return count;
    }
private:
    int waviness(long long num){
        int peak=0;
        int valley=0;

        int prev_digit=num%10;
        num=num/10;
        int curr_digit=num%10;
        num=num/10;
        if(num<=0) return 0;
        int next_digit=num%10;
        num=num/10;

        if(curr_digit>next_digit && curr_digit>prev_digit){
            peak++;
        }
        else if(curr_digit<next_digit && curr_digit<prev_digit){
            valley++;
        }

        while(num>0){
            prev_digit=curr_digit;
            curr_digit=next_digit;
            next_digit=num%10;
            num=num/10;

            if(curr_digit>next_digit && curr_digit>prev_digit){
                peak++;
            }
            else if(curr_digit<next_digit && curr_digit<prev_digit){
                valley++;
            }

        }

        return peak+valley;
    }

};