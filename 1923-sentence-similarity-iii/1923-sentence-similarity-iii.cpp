class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {

        deque<string> s1, s2;

        for (int i = 0; i < sentence1.length(); i++) {
            int j = i;
            string temp;
            while (j < sentence1.length() && sentence1[j] != ' ')
                temp.push_back(sentence1[j++]);

            i = j;
            s1.push_back(temp);
        }

        for (int i = 0; i < sentence2.length(); i++) {
            int j = i;
            string temp;
            while (j < sentence2.length() && sentence2[j] != ' ')
                temp.push_back(sentence2[j++]);

            i = j;
            s2.push_back(temp);
        }

        int i = 0;

        while (!s1.empty() && !s2.empty()) {
            if (s1.front() != s2.front())
                break;

            s1.pop_front();
            s2.pop_front();
        }

        while (!s1.empty() && !s2.empty()) {
            if (s1.back() != s2.back())
                break;

            s1.pop_back();
            s2.pop_back();
        }

        return (s1.empty() || s2.empty());
    }
};