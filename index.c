//Author:zhuxi
//Rebulider:KanyoChen
//MakingTime:
//EndingTime:

#include<stdio.h>
#include<windows.h>

typedef struct {
    int number;
    char name[50];
    int age;
    int class;
}student_info;//定义结构体

int number;
char name[100];
int age;
int class;
char loginname[20]={"admin"};
char loginpasswd[15]={"123456"};
int theNumber = 0;
//定义全局常用变量

student_info *p;
student_info list[1000];
//初始化结构体

int startdb();//初始化数据阵列
int printallinfo();//输出阵列中的所有数据
int savedb();//将阵列中的所有数据向文件输出
int cleardb();//删除所有数据
int nextpage();//下一页跳转页面
int delinfo();//删除部分数据
int search();//搜索功能首页
int searchnumber();//搜索学生编号
int searchname();//搜索学生姓名
int searchage();//搜索学生年龄
int searchclass();//搜索学生班级
int searchimage();//综合搜索
int printtaitou();//输出所有信息

int copyright(){
    Sleep(2000);
    system("cls");
    printf("This is made by Zhuxi[ZJFY-202805208]\nRecoded by kanyoChen\n");
}//版权信息

int crunthinfo(){
    int i=0,want=0;
    scanf("%d",&want);
    for( i=0;i<=want;i++){
        student_info list[] = {
        {i,"chenfeng",12,2012},
        };
    }
    return 0;
}

int login(){
    char userName[20],passWord[15];
    int Errortime=0;
    no1:printf("==->USERNAME:");
    scanf("%s",userName);
    printf("==->PASSWORD:");
    scanf("%s",passWord);
    if ((strcmp(userName,loginname)==0)&&(strcmp(passWord,loginpasswd)==0)){
        printf("OK Welcome to here!\n");
        Sleep(2000);
        system("cls");
        return 0;
    }
    else{
        printf("Wrong USERNAME or PASSWORD");
        Errortime=Errortime+1;
        if (Errortime==3){
            return 0;
        }
        else{
            goto no1;
        }
    }
}

int loginpage(){
    Sleep(2000);
    system("cls");
    printf("=================================\n");
    printf("===                           ===\n");
    printf("===          Welcome          ===\n");
    printf("===                           ===\n");
    printf("=================================\n");
    Sleep(2000);
    system("cls");
    printf("=================================\n");
    printf("===  This is student info db  ===\n");
    login();
    return 0;
}

int search(){
    int witch1;
    Sleep(2000);
    system("cls");
    printf("Search infomation whith this ! \n");
    printf("===1:search with number                             ===\n");
    printf("===2:search with name                               ===\n");
    printf("===3:search with age                                ===\n");
    printf("===4:search with class                              ===\n");
    printf("===5:search with line image                         ===\n");
    scanf("%d",&witch1);
    switch (witch1){
    case 1:
        searchnumber();
        break;

    case 2:
        searchname();
        break;

    case 3:
        searchage();
        break;
    
    case 4:
        searchclass();
        break;

    case 5:
        searchimage();
        break;

    default:
        printf("You are a bad boy ! \n");
        break;
    }
    return 0;
}

int searchnumber(){
    int getnumber1,getnumber2,i,n;
    printf("1:a<info\n");
    printf("2:info<a\n");
    printf("3:a<info<b\n");
    printf("Witch one do you need? :");
    scanf("%d",&n);
    switch (n){
    case 1:
        printf("a:");
        scanf("%d",&getnumber1);
        printtaitou();
        for ( i = getnumber1; ; i++){
            p = &list[i];
            if(p->number==0)
                break;
            printf("%6d\t%6s\t%6d\t%6d\n",p->number,p->name,p->age,p->class);  
        }
        
        break;
    
    case 2:
        printf("a:");
        scanf("%d",&getnumber2);
        printtaitou();
        for ( i = 0; i <= getnumber2 ; i++){
            p = &list[i];
            if(p->number==0)
                break;
            printf("%6d\t%6s\t%6d\t%6d\n",p->number,p->name,p->age,p->class);  
        }
        break;

    case 3:
        printf("a:");
        scanf("%d",&getnumber1);
        printf("b:");
        scanf("%d",&getnumber2);       
        printtaitou();
        for ( i = getnumber1; i <= getnumber2 ; i++){
            p = &list[i];
            if(p->number==0)
                break;
            printf("%6d\t%6s\t%6d\t%6d\n",p->number,p->name,p->age,p->class);  
        }
        break;

    default:
        break;
    }
}

int searchname(){
    char getname[100];
    int i;
    printf("Who is ? :");
    scanf("%s",getname);
    for ( i = 0; i < 1000; i++){
        if (list[i].number==0){
            printf("\n");
            break;
        }
        if (strcmp(getname,list[i].name)==0){
            printtaitou();
            printf("%6d\t%6s\t%6d\t%6d\n",list[i].number,list[i].name,list[i].age,list[i].class); 
        }else{

        }
    }
    return 0;
}

int searchage(){

}

int searchclass(){

}

int searchimage(){

}

int startdb(){
    int i;
    FILE *fp;
    fp=fopen("info.txt","w+");
    fp=fopen("info.txt","r");
    if(fp==NULL){
        printf("The database has READING ERROR\nPlease check your FILES and MAKE SURE that the FILES are complete.\nThen, try again when you restart the StudentManageSystem application\nNow, press any key to continue(shutdown the SMS)");
        system("pause>>sbrh");
        exit(0);
    }
    for ( i = 0; i < 100; i++)
    {
        fscanf(fp,"%d%s%d%d",&list[i].number,&list[i].name,&list[i].age,&list[i].class);
        if(fp==NULL){
            printf("The database has READING ERROR\nPlease check your FILES and MAKE SURE that the FILES are complete.\nThen, try again when you restart the StudentManageSystem application\nNow, press any key to continue(shutdown the SMS)");
            system("pause>>sbrh");
            exit(0);
            break;
        }
    }
    return 0;
}

int savedb(){
    int i;
    FILE *fp;
    fp=fopen("info.txt","w+");
    if(fp==NULL){
        printf("1The database has READING ERROR\nPlease check your FILES and MAKE SURE that the FILES are complete.\nThen, try again when you restart the StudentManageSystem application\nNow, press any key to continue(shutdown the SMS)");
        system("pause>>sbrh");
        exit(0);
    }
    for ( i = 0; i < 100; i++)
    {
        fprintf(fp,"%d\n%s\n%d\n%d\n",&list[i].number,&list[i].name,&list[i].age,&list[i].class);
        if(fp==NULL){
            printf("2The database has READING ERROR\nPlease check your FILES and MAKE SURE that the FILES are complete.\nThen, try again when you restart the StudentManageSystem application\nNow, press any key to continue(shutdown the SMS)");
            system("pause>>sbrh");
            exit(0);
            break;
        }
    }
    return 0;
}

int cleardb(){
    int i;
    FILE *fp;
    fp=fopen("info.txt","w");
    if(fp==NULL){
        printf("The database has READING ERROR\nPlease check your FILES and MAKE SURE that the FILES are complete.\nThen, try again when you restart the StudentManageSystem application\nNow, press any key to continue(shutdown the SMS)");
        system("pause>>sbrh");
        exit(0);
    }
    for ( i = 0; i < 100; i++){
        fprintf(fp,"%d\n%s\n%d\n%d\n",NULL,NULL,NULL,NULL);
        if(fp==NULL){
            printf("The database had been clear now. There was nothing in it.\nPlase enter any key to shutdown the application");
            system("pause>>sbrh");
            exit(0);
            break;
        }
    }
    return 0;
}

int printtaitou(){
    printf("Number\t");
    printf("Name  \t");
    printf("Age   \t");
    printf("Class \n");
    printf("------------------------------------------------\n");
    return 0;
}

int printallinfo(){
    int nu;
    printf("Number\t");
    printf("Name  \t");
    printf("Age   \t");
    printf("Class \n");
    printf("------------------------------------------------\n");
    for ( nu = 0; nu < 100; nu++)
    {
        p = &list[nu];
        if(p->number==0)
            break;
        printf("%6d\t%6s\t%6d\t%6d\n",p->number,p->name,p->age,p->class);
    }
    return 0;
}

int nextpage(){
    char stu[1];
    back11:printf("GO to the meru?[Y/N]");
    scanf("%s",stu);
    if(strcmp(stu,"N")==0){
        savedb();
        return 0;
    }else{
        if (strcmp(stu,"Y")==0){
            system("cls");
            return 1;
        }else{
            printf("Sorry, we can't understand on this way! Please enter again.\n");
            goto back11;
        }
    }
}

int delinfo(){
    int num,i;
    printf("Whitch one ? Please sent the info's number:");
    scanf("%d",&num);
    FILE *fp;
    fp=fopen("info.txt","w+");
    if(fp==NULL){
        printf("The database has READING ERROR\nPlease check your FILES and MAKE SURE that the FILES are complete.\nThen, try again when you restart the StudentManageSystem application\nNow, press any key to continue(shutdown the SMS)");
        system("pause>>sbrh");
        exit(0);
    }
    // for ( i = num; i < 100; i++){
    //     fprintf(fp,"%d\n%s\n%d\n%d\n",&list[i].number,&list[i].name,&list[i].age,&list[i].class);
    //     if(fp==NULL){
    //         printf("The database has READING ERROR\nPlease check your FILES and MAKE SURE that the FILES are complete.\nThen, try again when you restart the StudentManageSystem application\nNow, press any key to continue(shutdown the SMS)");
    //         system("pause>>sbrh");
    //         exit(0);
    //         break;
    //     }
    // }
    // for ( i = num-1; i < 100; i++)
    // {
    //     fscanf(fp,"%d\n%s\n%d\n%d\n",&list[i].number,&list[i].name,&list[i].age,&list[i].class);
    //     if(fp==NULL){
    //         printf("The database has READING ERROR\nPlease check your FILES and MAKE SURE that the FILES are complete.\nThen, try again when you restart the StudentManageSystem application\nNow, press any key to continue(shutdown the SMS)");
    //         system("pause>>sbrh");
    //         exit(0);
    //         break;
    //     }
    // }
    for ( i = 0; i < 100; i++)
    {
        if (i+1==list[num-1].number)
        {
            for (int j = i; j < 99; j++)
            {
                // list[j].number = list[j + 1].number;
                sprintf(list[j].name,"%s",list[j + 1].name);
                list[j].age = list[j + 1].age;
                list[j].class = list[j + 1].class;
            }            
            // list[i].number = 0;
            // sprintf(list[i].name,"");
            // list[i].age = 0;
            // list[i].class = 0;
        }
        if(fp==NULL){
            printf("The database has READING ERROR\nPlease check your FILES and MAKE SURE that the FILES are complete.\nThen, try again when you restart the StudentManageSystem application\nNow, press any key to continue(shutdown the SMS)");
            system("pause>>sbrh");
            exit(0);
            break;
        }
    }

    return 0;
}

int main()
{
    int i;
    char stu[1];
    startdb();
    // loginpage();
    // copyright();
    back2:printf("============Witch one did you want?==========\n");
    printf("===1:see infomation                             ===\n");
    printf("===2:add infomation                             ===\n");
    printf("===3:del infomation                             ===\n");
    printf("===4:search infomation                          ===\n");
    printf("===5:del all infomation                         ===\n");
    printf("===6:ready to the databases                     ===\n");
    back1:printf("witch one?:");
    scanf("%d",&i);
    switch (i){
    case 1:
        printf("THis is all of the infomation:\n");
        printallinfo();
        break;
    
    case 2:
        // printallinfo();
            p=&list[theNumber];
            if (p->number==0){
                printf("student number is: %d\n",list[theNumber].number=theNumber+1);
                printf("Student name is:");
                // scanf("%s",list[theNumber].name);
                scanf("%s",list[theNumber].name);
                printf("Student age is:");
                scanf("%d",&list[theNumber].age);
                printf("Student class is:");
                scanf("%d",&list[theNumber].class);
                savedb();
                printf("OK\n");
            }
            theNumber++;
            printallinfo();
            break;

    case 3:
        delinfo();
        break;
    
    case 4:
        search();
        break;

    case 5:
        cleardb();
        break;

    case 6:
        Sleep(2000);
        system("cls");
        back3:printf("Are you sure?[Y/N]?");
        scanf("%s",stu);
        if(strcmp(stu,"Y")==0){
            startdb();
            printallinfo();
        }else{
            if(strcmp(stu,"N")==0){
                printf("Are you sure?[Y/N]?");
                scanf("%s",stu);
                if(strcmp(stu,"Y")==0){
                    goto back2;
                }else{
                    if(strcmp(stu,"N")==0){
                        goto back3;
                    }else{
                        printf("I don't know! Please again.");
                        goto back3;
                    }
                }
            }else{
                printf("I don't know! Please again.");
                goto back3;
            }
        }
        if(nextpage()==1)
            goto back2;
        break;

    default:
        printf("Plese sent it ahain Bad boy!");
        goto back1;
        break;
    }
    if(nextpage()==1){
        goto back2;
    }
    return 0;
}