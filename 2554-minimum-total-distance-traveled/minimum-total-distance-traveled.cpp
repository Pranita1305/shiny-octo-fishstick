class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());

        int m=robot.size();

        vector<long long>fac_pos;

        for(int i=0;i<factory.size();i++){
            int limit=factory[i][1];
            int position=factory[i][0];

            for(int j=0;j<limit;j++){
                fac_pos.push_back(position);
            }
        }

        int n=fac_pos.size();
        vector<vector<long long>> t(m+1,vector<long long>(n+1,-1));

        return solve(0,0,robot,fac_pos,t);
    }
private:
    long long solve(int rob,int fac,vector<int>& robot, vector<long long>& factory,vector<vector<long long>>& t){
        if(robot.size()<=rob){
            return 0;
        }

        if(factory.size()<=fac){
            return 1e12;
        }

        if(t[rob][fac]!=-1){
            return t[rob][fac];
        }

        long long take=abs(robot[rob]-factory[fac])+solve(rob+1,fac+1,robot,factory,t);
        long long skip=solve(rob,fac+1,robot,factory,t);

        return t[rob][fac]=min(take,skip);
    }
};