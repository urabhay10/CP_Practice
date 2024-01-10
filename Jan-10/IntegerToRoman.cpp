//https://leetcode.com/problems/integer-to-roman/
//i figured out that in order to get int to roman i need to concatination of each digits roman equivalent 
//so i kinda hard coded all the possible "face values" and stored in a function then i called it for each digits place value and appended to the res string
class Solution {
public:
    string oneIntToRoman(int num){
        if(num>=1000){
            string s="";
            for(int i=0;i<num/1000;i++){
                s+="M";
            }
            return s;
        }
        else if(num==900){
            return "CM";
        }else if(num>=500){
            string s="D";
            for(int i=0;i<(num-500)/100;i++){
                s+="C";
            }
            return s;
        }else if(num==400){
            return "CD";
        }else if (num>=100){
            string s="C";
            for(int i=0;i<(num-100)/100;i++){
                s+="C";
            }
            return s;
        }else if(num==90){
            return "XC";
        }else if(num>=50){
            string s="L";
            for(int i=0;i<(num-50)/10;i++){
                s+="X";
            }
            return s;
        }else if(num==40){
            return "XL";
        }else if(num>=10){
            string s="X";
            for(int i=0;i<(num-10)/10;i++){
                s+="X";
            }
            return s;
        }else if (num==9){
            return "IX";
        }else if(num>=5){
            string s="V";
            for(int i=0;i<(num-5);i++){
                s+="I";
            }
            return s;
        }else if(num==4){
            return "IV";
        }else if(num>=1){
            string s="I";
            for(int i=0;i<(num-1);i++){
                s+="I";
            }
            return s;
        }else{
            return "";
        }
    }
    string intToRoman(int num) {
        int digits=log(num)+1;
        string res="";
        for(int i=0;i<digits;i++){
            int place_val=((num/int(pow(10,i)))%10)*pow(10,i);
            res=oneIntToRoman(place_val)+res;
        }
        return res;
    }
};