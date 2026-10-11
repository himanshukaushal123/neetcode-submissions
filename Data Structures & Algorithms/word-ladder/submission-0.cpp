class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Queue stores {word, sequence length}
        queue<pair<string, int>> qe;

        // Convert wordList into a set for fast word lookup and deletion
        set<string> wlist(wordList.begin(), wordList.end());

        // If endWord is not in wordList, transformation is impossible
        if (wlist.find(endWord) == wlist.end()) return 0;

        // Start BFS with beginWord and sequence length 1
        qe.push({beginWord, 1});

        // Perform Breadth-First Search (BFS)
        while (!qe.empty()) {
            // Get the current word and its sequence length
            auto [word, steps] = qe.front();
            qe.pop();

            // Create a temporary copy to generate neighboring words
            string temp = word;

            // Try changing each character of the current word
            for (int i = 0; i < beginWord.size(); i++) {
                // Save the original character so we can restore it later
                char original = temp[i];

                // Replace the current character with every letter from 'a' to 'z'
                for (char j = 'a'; j <= 'z'; j++) {
                    temp[i] = j;

                    // Skip if the generated word is the same as the current word
                    if (temp == word) continue;

                    // If endWord is reached, return the sequence length
                    if (temp == endWord) return steps + 1;

                    // Check whether the generated word exists in wordList
                    if (wlist.find(temp) != wlist.end()) {
                        // Add the valid word to the queue with an increased length
                        qe.push({temp, steps + 1});

                        // Remove it from the set to prevent revisiting it
                        wlist.erase(temp);
                    }
                }

                // Restore the original character before changing the next position
                temp[i] = original;
            }
        }

        // Return 0 if no valid transformation sequence exists
        return 0;
    }
};