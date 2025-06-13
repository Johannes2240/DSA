class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int n = rooms.size();
        vector<bool>visited(n, false);
        visited[0]= true;
        queue<int> q;
        q.push(0);

        while(!q.empty()){
            int room = q.front();
            q.pop();
            for(int key: rooms[room]){
                if(!visited[key]){
                visited[key] = true;
                q.push(key);

                }

            }

        }
        for(bool seen: visited){
            if(!seen) return false;
        }

        return true;

    }
};
