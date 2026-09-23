class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;  // acts as our directory stack
        int n = path.size();
        int i = 0;
        
        while (i < n) {
            // Skip consecutive slashes
            while (i < n && path[i] == '/') i++;
            
            // Extract the component between slashes
            string component = "";
            while (i < n && path[i] != '/') {
                component += path[i];
                i++;
            }
            
            if (component.empty() || component == ".") {
                // Empty (trailing slash) or current directory: skip
                continue;
            } else if (component == "..") {
                // Parent directory: pop from stack (if not empty)
                if (!stack.empty()) {
                    stack.pop_back();
                }
                // If stack is empty (already at root), ".." is a no-op
            } else {
                // Valid directory/file name: push to stack
                stack.push_back(component);
            }
        }
        
        // Build the result: "/" + components joined by "/"
        string result = "";
        for (const string& dir : stack) {
            result += "/" + dir;
        }
        
        // Handle root case (empty stack)
        return result.empty() ? "/" : result;
    }
};