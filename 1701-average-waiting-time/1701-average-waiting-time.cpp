class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int current_time = 0;
        double total_waiting_time = 0;
        
        for (const auto& customer : customers) {
            int arrival = customer[0];
            int time = customer[1];
            
            // Chef starts when either he is free or when customer arrives, whichever is later
            current_time = max(current_time, arrival);
            
            // Calculate finish time of the current customer
            int finish_time = current_time + time;
            
            // Calculate waiting time for the current customer
            int waiting_time = finish_time - arrival;
            
            // Update total waiting time
            total_waiting_time += waiting_time;
            
            // Update the current time to the finish time of the current order
            current_time = finish_time;
        }
        
        // Return the average waiting time
        return total_waiting_time / customers.size();
    }
};