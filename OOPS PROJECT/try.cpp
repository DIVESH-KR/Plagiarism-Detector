#include<fstream>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<cstring>
#include<string.h>
#include<graphics.h>
#include<conio.h>
using namespace std;
void horilal(int j,int i)
    {
        int gd = DETECT, gm, midx, midy;

       initgraph(&gd, &gm, "C:\\TC\\BGI");

       setcolor(MAGENTA);
       rectangle(0,40,639,450);
       settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
       setcolor(WHITE);
     //  outtextxy(275,10,"Pie Chart");

       midx = getmaxx()/2;
       midy = getmaxy()/2;

       int total=j+i;
       float individual=360/(float)total;
       cout<<individual;


       setcolor(WHITE);
       rectangle(20,60,70,100);
       setfillstyle(LINE_FILL,BLUE);
       floodfill(30,70,WHITE);
       outtextxy(80, 70,"COPIED" );


       setcolor(WHITE);
       setfillstyle(LINE_FILL,BLUE);
       pieslice(midx, midy, 0, individual*j, 100);

       setcolor(WHITE);
       rectangle(20,110,70,150);
       setfillstyle(XHATCH_FILL,RED);
       floodfill(30,120,WHITE);
       outtextxy(80, 115, "NOT COPIED");


       setfillstyle(XHATCH_FILL,RED);
       pieslice(midx, midy, individual*j, 360, 100);

    }
class assignment
{

};
class findchor
{
public:
    int copywala;
    int copykar;
    getdata(int x,int y)
    {
        copywala=x;
        copykar=y;
    }
    display()
    {
        cout<<"copywala"<<copywala<<"    "<<"copykar"<<copykar<<endl;
    }
};
int counter(char *s)
{
    int t=0;
    while(*s!='\0')
    {
        if(*s==' '){t++;}s=s+1;
    }t=t+1;
    return t;
}
int main()
{
    int no,give;
    cout<<"ENTER THE TOTAL NUMBER OF FILES : ";cin>>give;
    cout<<"ENTER THE NUMBER TO DETECT THE ACCURACY : "<<endl;
    cin>>no;
    float minn;
    cout<<"ENTER THE MIN PERCENTAGE : "<<endl;
    cin>>minn;
    findchor f[3];
    int p=0;
    cin.ignore();
    //ifstream fin,sin;
    for(int file=1;file<=give;file++)
    {
     //float sum=0;
     string z;
     stringstream cri;
      cri<<file;
       if(file<10)
       {z="try0"+cri.str()+".txt";}
       else
       {z="try"+cri.str()+".txt";}
       cout<<z;
   /* int n=0,checker=0;
    int count1=0,count2=0;
    string str,atr;
    ifstream fin;
    fin.open(z.c_str());*/




    for(int files=file+1;files<=give;files++)
    {string q;
    ifstream fin;
    fin.open(z.c_str());
    float sum=0;
    ifstream sin;
    int n=0,checker=0;
    int count1=0,count2=0;
    string str,atr;
     string cry;
      cry =(char)files;
       if(files<10)
       {q="try0"+cry+".txt";}
       else
       {q="try"+cry+".txt";}
       cout<<q;



    sin.open(q.c_str());
    getline(sin,str);
    getline(fin,atr);
    cout<<str;
    int in=str.length();
    int out=atr.length();
    int t1=counter(&str[0]);
    string* s1 = new string[t1];
    int wc=0 ;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]!=' ')
            s1[wc] = s1[wc] + str[i] ;
        else if(str[i]==' ')
            wc++ ;
    }
    int t2=counter(&atr[0]);
    string* s2 = new string[t2];
    int wk=0 ;
    for(int i=0;i<atr.length();i++)
    {
        if(atr[i]!=' ')
            s2[wk] = s2[wk] + atr[i] ;
        else if(atr[i]==' ')
            wk++ ;
    }
    for(int i=0,j=0;(i<t1-no+1)&&(j<t2-no+1);i++,j++)
       {
           int txt,tell=no,m=0+i;
           while(tell!=0)
           {
               if(s1[m]==s2[m]){n++;}tell--;m++;
           }
           if(n==no){checker++;}
           else
       {
           if(checker>0)
           {
           sum+=checker+(no-1);
           checker=0;
           n=0;
           }
       }
       n=0;
       }
       if(checker>0)
    {
        sum+=checker+(no-1);
        checker=0;
    }
    float per;
    per=sum/t1;
    per=per*100;
    cout<<per<<"%"<<endl;
    fin.close();
    sin.close();



    if(per>=minn)
    {
        f[p].getdata(file,files);
        p++;
    }
    }
    }
    for(int i=0;i<p;i++)
    {
        f[i].display();
    }
    horilal(p+1,give-p-1);//give ko counter se replace
    getch();
    return 0;
}
