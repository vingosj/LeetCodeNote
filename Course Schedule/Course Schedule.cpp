#include <algorithm>
#include <queue>

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>(0));
        int indegree[numCourses] = {0};
        
        if(prerequisites.size() == 0) return true;
        
        for(auto p : prerequisites){
            graph[p.second].push_back(p.first);
            indegree[p.first]++;
        }
        
        queue<int> stack;
        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0) stack.push(i);
        }
        
        while(stack.size() != 0)
        {
            for(auto i : graph[stack.front()]){
                if(--indegree[i] == 0) stack.push(i);
            }
            stack.pop();
        }
        
        for(auto i : indegree)
        {
            if(i != 0) return false;
        }
        
        return true;
    }
};