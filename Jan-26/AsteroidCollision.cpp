//https://leetcode.com/problems/asteroid-collision
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int i=0;
        while(i<int(asteroids.size()-1)){
            if(i<0){
                i=0;
            }
            cout<<i<<" ";
            if((asteroids[i]>0 && asteroids[i+1]<0)){
                if(asteroids[i]>abs(asteroids[i+1])){
                    asteroids.erase(asteroids.begin()+i+1);
                }else if(asteroids[i]<abs(asteroids[i+1])){
                    asteroids.erase(asteroids.begin()+i);
                    i--;
                }else{
                    asteroids.erase(asteroids.begin()+i+1);
                    asteroids.erase(asteroids.begin()+i);
                    i--;
                }
            }else{
                i++;
            }
            if(i<0){ 
                i=0;
            }
        }
        return asteroids;
    }
};