class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses+1, false);
        
        vector<vector<int>> graph(numCourses, vector<int>());
        
        vector<int> indegree(numCourses, 0);
        for(auto iter : prerequisites){
            graph[iter[1]].push_back(iter[0]);
            indegree[iter[0]]++;
        }
        
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        
        vector<int> ans;
        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            ans.push_back(node);
            
            for(auto iter : graph[node]){
                indegree[iter]--;
                if(indegree[iter] == 0)
                    q.push(iter);
            }
        }
        if(numCourses == count)
            return ans;
        vector<int> emp;
        return emp;
    }
};