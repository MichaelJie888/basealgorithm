struct stuentInfo(){
    int id;
    char gender;
    char name[20];
    char major[20];
}Alice,Bob,stu[1000],*p;

//结构体中不能够定义自身类型数据，但是能够定义自身类型的指针变量
//指针变量型p，普通变量Bob


//结构体内的构造函数

struct studentInfo{
    int id;
    char gender;
    studentInfo(int _id,char _gender){
        id=_id;
        gender=_gender;
    }
};
//结构体构造函数使用
studentInfo stua=studentInfo(10084,'M');

//结构体的另外一种写法
struct studentIn{
    int id;
    char gender;
    studentIn(int _id,char _gender):id_id,gender(_gender) {}

};

//可以不经过初始化就能够定义变量还能够享受初始化带来的便利

struct studentinfo{
    int id;
    char gender;
    studentinfo(){}

    studentinfo(char _gender){
        gender=_gender;
    }

    studentinfo(int _i,char _gend):id(_i),gender(_gend) {}
};