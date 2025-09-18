class TaskManager {
public:
    // task --> purani id taki mai usse search kr pau user ID wale mai
    // task --> userId
    // userId --> {priority , taskId}
    unordered_map<int , int> taskToUser;
    unordered_map<int , int> old_priority;
    map<int , set<pair<int , int>>> tasks;  // userId -> {priority , taskId}
    set<pair<int , pair<int , int>>> st;  // {priority , {taskId , userId}}
    TaskManager(vector<vector<int>>& yo) {
        // userId , taskId , priority
        for(vector<int>& vec : yo){
            tasks[vec[0]].insert(make_pair(vec[2] , vec[1]));
            taskToUser[vec[1]] = vec[0];
            old_priority[vec[1]] = vec[2];
            st.insert({vec[2] , {vec[1] , vec[0]}});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        tasks[userId].insert({priority , taskId});
        st.insert({priority , {taskId , userId}});
        old_priority[taskId] = priority;
        taskToUser[taskId] = userId;
    }
    
    void edit(int taskId, int newPriority) {
        int userId = taskToUser[taskId];
        int old = old_priority[taskId];

        tasks[userId].erase({old , taskId});
        st.erase({old , {taskId , userId}});
        tasks[userId].insert({newPriority , taskId});
        st.insert({newPriority , {taskId , userId}});
        old_priority[taskId] = newPriority;
    }
    
    void rmv(int taskId) {
        int userId = taskToUser[taskId];
        int old = old_priority[taskId];

        tasks[userId].erase({old , taskId});
        st.erase({old , {taskId , userId}});
    }
    
    int execTop() {
        if(st.empty()) return -1;

        auto p = *st.rbegin();

        int priority = p.first;
        int taskId = p.second.first;
        int userId = p.second.second;

        st.erase(prev(st.end()));
        tasks[userId].erase({priority , taskId});


        return userId;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */