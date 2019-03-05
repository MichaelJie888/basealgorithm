bool Find(int target,vector<vector<int>> array){
    int a=array.size();
    int b=array[0].size()-1;//size记录的是全部的长度，所以必须减一
    int ln=0,lm=0;
    bool found=false;
    while(ln< a && b>=0){//这个地方，ln必须小于a，要不然还会越界
        if(array[ln][b]==target){
            found= true;
            break;
        } else if(array[ln][b]>target){
            b--;
        }else{
            ln++;
        }
    }

    return found;
}