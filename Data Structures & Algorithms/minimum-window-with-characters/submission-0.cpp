class Solution {
public:
    string minWindow(string s, string t) {
        // Edge case: if t is bigger than s, impossible
        if (t.size() > s.size()) return "";

        // Step 1: Build frequency map of t
        unordered_map<char, int> tFreq;
        for (char c : t) {
            tFreq[c]++;
        }

        // Number of unique characters we need to satisfy
        int required = tFreq.size();

        // Sliding window pointers
        int left = 0, right = 0;

        // This will track how many characters are currently satisfied
        int formed = 0;

        // Frequency map for current window
        unordered_map<char, int> windowFreq;

        // Answer tracking
        int minLen = INT_MAX;
        int startIndex = 0; // where the best window starts

        // Step 2: Start expanding the window
        while (right < s.size()) {
            char c = s[right];

            // Add current character to window
            windowFreq[c]++;

            // If this character is needed AND its frequency just matched
            if (tFreq.count(c) && windowFreq[c] == tFreq[c]) {
                formed++; // we satisfied one required character
            }

            // Step 3: Try shrinking the window when valid
            while (left <= right && formed == required) {

                // Update minimum window if smaller
                if ((right - left + 1) < minLen) {
                    minLen = right - left + 1;
                    startIndex = left;
                }

                // Now try to shrink from the left
                char leftChar = s[left];

                // Remove it from window
                windowFreq[leftChar]--;

                // If removing breaks the requirement → window becomes invalid
                if (tFreq.count(leftChar) && 
                    windowFreq[leftChar] < tFreq[leftChar]) {
                    formed--; // no longer valid
                }

                // Move left forward (shrink)
                left++;
            }

            // Expand window
            right++;
        }

        // If no valid window found
        if (minLen == INT_MAX) return "";

        // Return smallest window substring
        return s.substr(startIndex, minLen);
    }
};