class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>Restrict(deadends.begin(), deadends.end());
        unordered_set<string>visited;
        queue<string> q;
        string start = "0000";
        if(Restrict.count(start)) return -1;

        q.push(start);
        visited.insert(start);
        int steps = 0;

        while(!q.empty()){
            int level = q.size();

            for(int i = 0; i< level; ++i){
                string current = q.front();
                if(current == target) return steps;
                q.pop();

                for(int pos = 0; pos < 4; ++pos){
                    string up = current;
                    string down = current;

                    up[pos] = (current[pos]=='9')? '0': current[pos] + 1;
                    down[pos] = (current[pos] == '0')? '9': current[pos] - 1;

                    if(!Restirct.count(up) && !visited.count(up)){
                        q.push(up);
                        visited.insert(up);
                    }
                    
                    if(!Restrict.count(down) && !visited.count(down)){
                        q.push(down);
                        visited.insert(down);
                    }

                }
                
               
            }

            steps++;

        }
//check the steps it might increase but returning might cause something bad.
//is

        return -1;

    
    }
};
