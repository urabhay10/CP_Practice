//https://leetcode.com/problems/word-search/
class Solution {
public:
    bool termExist(vector<vector<char>> &board,string word,int i, int j,vector<vector<bool>> &vis){
        // cout<<"searching "<<word<<" at "<<i<<" "<<j<<endl;
        
        // for(auto &vec:vis){
        //     for(auto e:vec){
        //         cout<<e<<" ";
        //     }
        //     cout<<"\n";
        // }
        if(word.length()==0){
            return true;
        }
        vis[i][j] = true;
        bool ans = false;
        int m = board.size();
        int n = board[0].size();
        if(i<m-1 && board[i+1][j]==word[0] && !vis[i+1][j]){
            ans = termExist(board,word.substr(1),i+1,j,vis);
            if(ans){
                vis[i][j]=false;
                return ans;
            }   
        }
        if(j<n-1 && board[i][j+1]==word[0] && !vis[i][j+1]){
            ans = termExist(board,word.substr(1),i,j+1,vis);
            if(ans){
                vis[i][j]=false;
                return ans;
            }    
        }
        if(i>0 && board[i-1][j]==word[0] && !vis[i-1][j]){
            ans = termExist(board,word.substr(1),i-1,j,vis);
            if(ans){
                vis[i][j]=false;
                return ans;
            }
        }
        if(j>0 && board[i][j-1]==word[0] && !vis[i][j-1]){
            ans = termExist(board,word.substr(1),i,j-1,vis);
            if(ans){
                vis[i][j]=false;
                return ans;
            }
        }
        vis[i][j]=false;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,0));
        bool ans = false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    ans = termExist(board,word.substr(1),i,j,vis);
                    if(ans){
                        return ans;
                    }
                }
            }   
        }
        return false;
    }
};
