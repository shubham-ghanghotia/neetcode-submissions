class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int m = piles.size();
        int end = piles[0];
        int sum = piles[0];

        // calculate max and sum
        for(int i = 1; i < m; i++){
           end = max(end, piles[i]);
           sum += piles[i];
        }

        if(m == h) return end;

        int start = ceil((double)sum / h);

        while(start <= end){
            int mid = start + (end - start) / 2;

            int total = 0;
            for(int i = 0; i < m; i++){
                total += ceil((double)piles[i] / mid);
            };

            if(total > h){
                start = mid + 1;
            } else{
                end = mid - 1;
            } 
        }


        return start;
    }
};
