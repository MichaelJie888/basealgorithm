class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int c[100]={0};
        int pos[100]={0};
        for(int i=0;i<str.size();i++){
            c[str[i]-'A']++;
            pos[str[i]-'A']=i;
        }
        for(int j=0;j<str.size();j++){
            if(c[str[j]-'A']==1){
                return pos[str[j]-'A'];
            }
        }
        
        return -1;
    }
};