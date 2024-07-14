class Solution {
public:
    int charToInt(char c) {
        return c - '0';
    }

    string countOfAtoms(string formula) {
        stack<unordered_map<string, int>> indicesStack; 
        unordered_map<string, int> currentAtoms; 
        int i = 0;

        while (i < formula.length()) {
            if (isupper(formula[i])) {
                string atom;
                atom += formula[i];
                ++i;
                while (i < formula.length() && islower(formula[i])) {
                    atom += formula[i];
                    ++i;
                }
                int count = 0;
                while (i < formula.length() && isdigit(formula[i])) {
                    count = count * 10 + charToInt(formula[i]);
                    ++i;
                }
                count = max(1, count); 
                currentAtoms[atom] += count;
            } else if (formula[i] == '(') {
                indicesStack.push(currentAtoms); 
                currentAtoms.clear();
                ++i;
            } else if (formula[i] == ')') {
                int count = 0;
                ++i;
                while (i < formula.length() && isdigit(formula[i])) {
                    count = count * 10 + charToInt(formula[i]);
                    ++i;
                }
                count = max(1, count); 
                for (auto& entry : currentAtoms) {
                    entry.second *= count;
                }

                if (!indicesStack.empty()) {
                    auto& prevAtoms = indicesStack.top();
                    for (const auto& entry : currentAtoms) {
                        prevAtoms[entry.first] += entry.second;
                    }
                    currentAtoms = prevAtoms; 
                    indicesStack.pop();
                }
            } else {
                ++i;
            }
        }

        string ans;
        vector<string> atoms;
        for (auto& entry : currentAtoms) {
            atoms.push_back(entry.first);
        }
        sort(atoms.begin(), atoms.end());

        for (const string& atom : atoms) {
            ans += atom;
            if (currentAtoms[atom] > 1) {
                ans += to_string(currentAtoms[atom]);
            }
        }

        return ans;
    }
};