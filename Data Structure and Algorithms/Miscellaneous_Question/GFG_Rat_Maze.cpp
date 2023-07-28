    /* RAT IN MAZE PROBLEM*/
/*  here we keep the visited places record so as not to trace them again in way
    we keep every choice for movement and check whether the next position is safe to go or not
*/   
   
   
    #include <bits/stdc++.h>
    using namespace std;

    bool isSafe(int x, int y, vector<vector<int>> &m, int n, vector<vector<int>> &visited)
    {

        if (x >= 0 and x <= n - 1 and y >= 0 and y <= n - 1 and m[x][y] == 1 and visited[x][y] == 0)
        {

            return true;
        }
        else
        {

            return false;
        }
    }

    void solve(vector<vector<int>> &m, int n, int x, int y, string path, vector<string> &ans, vector<vector<int>> &visited)
    {
        // base condition
        if (x >= n - 1 and y >= n - 1)
        {

            ans.push_back(path);
            return;
        }

        // since we are at x , y --> mark it as visited
        visited[x][y] = 1;

        // 4 option h jaane k liye

        // down
        if (isSafe(x + 1, y, m, n, visited))
        {

            path.push_back('D');
            solve(m, n, x + 1, y, path, ans, visited);

            path.pop_back();
        }
        // up
        if (isSafe(x - 1, y, m, n, visited))
        {
            path.push_back('U');
            solve(m, n, x - 1, y, path, ans, visited);
            path.pop_back();
        }
        // right
        if (isSafe(x, y + 1, m, n, visited))
        {
            path.push_back('R');
            solve(m, n, x, y + 1, path, ans, visited);
            path.pop_back();
        }
        // left
        if (isSafe(x, y - 1, m, n, visited))
        {
            path.push_back('L');
            solve(m, n, x, y - 1, path, ans, visited);
            path.pop_back();
        }
        visited[x][y] = 0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Write your code here.
        vector<string> ans;
        if(m[0][0]==0) return ans; // boundary case 
        vector<vector<int>> visited = m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                visited[i][j] = 0;
            }
        }
        string path = "";
        int x = 0;
        int y = 0;
        solve(m, n, x, y, path, ans, visited);
        sort(ans.begin(), ans.end());
        return ans;
    }

    int main()
    {

        vector<vector<int>> m{
            {1, 0, 0},
            {1, 1, 0},
            {0, 1, 1}};
        int n = 3;
        vector<string> ans = findPath(m, n);

        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }

        return 0;
    }
