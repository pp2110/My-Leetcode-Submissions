class Solution {
public:
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        stack<int> st;
        
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
        
        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            for(auto iter : graph[node]){
                    indegree[iter]--;
                    if(indegree[iter] == 0)
                        q.push(iter);
                
            }
        }
        
        return (count == numCourses);
    }
};