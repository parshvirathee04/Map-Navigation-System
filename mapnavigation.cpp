#include<graphics.h>
#include<bits/stdc++.h>
#define V 15
using namespace std;
#include <stdio.h>
#include <limits.h>

int drline[15];
int k=0;

struct node
{
    int data;
    struct node *left;
    struct node *right;
    struct node *up;
    struct node *down;

}*n[16];

int ind=0;
int sol[15]={0};

bool check(node *m)
{
    if(m!=NULL)
        return true;

    return false;
}


bool buspath(node *l,int destination)
{
    if(l==NULL)
    {
        return false;
    }

    if(l->data==n[destination]->data)
    {
        sol[ind++] = l->data;
        return true;
    }

    if(check(l)== true)
    {
        sol[ind++] = l->data;

        if (buspath(l->right,destination) == true)
            return true;

        if (buspath(l->left,destination) == true)
            return true;

        if (buspath(l->up,destination) == true)
            return true;

        if (buspath(l->down,destination) == true)
            return true;

        sol[ind] = 0;
        ind--;
        return false;
    }

    return false;
}

void printsol()
{

    cout<<"Path is "<<sol[0];
    for (int i = 1; i < 15; i++)
    {
        if(sol[i]!=0)
        cout<<"-->"<<sol[i];
    }
}

bool findpath(int source,int destination)
{
    if(buspath(n[source],destination) == false)
    {
        cout<<"No path is available";
        return false;
    }

    printsol();
    return true;
}



int mindist(int dist[], bool select[])
{
    int mini = INT_MAX, min_ind=0;

    for (int v = 0; v < V; v++)
    {
        if (select[v] == false && dist[v] <= mini)
        {
            mini = dist[v], min_ind = v;
        }
    }

    return min_ind;
}


void print_path(int parent[], int j)
{
    if(parent[j] == -1)
        return;

    print_path(parent, parent[j]);
    drline[k]=parent[j];
    k++;
    cout << " -> " << j;
}

void print(int dist[], int n, int parent[], int src,int i)
{
    int mini = INT_MAX;
        cout <<"Shortest path from "<<src<< " to " <<i << " is " <<dist[i]<<endl;
        cout<<"Path is "<<src;
        for(int i=0;i<15;i++){
            drline[i]=0;
        }
        print_path(parent, i);
        drline[k]=i;
        cout << endl;
}

void dijkstra(int graph[V][V], int src, int dest)
{
    int dist[V];
    bool select[V];
    int parent[V];

    parent[src] = -1;
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        select[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V-1; count++)
    {
        int u = mindist(dist, select);

        select[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (!select[v] && graph[u][v] && dist[u]+graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v]  = u;
            }
        }
    }

    print(dist, V, parent, src, dest);
}
int main()
{
    int src,dest;
    char cont;
    int gd=0,gm;
        int x0=20+40,y0=420-20;
        int x1=100+40,y1=380-20;
        int x2=180+40,y2=340-20;
        int x3=260+40,y3=300-20;
        int x4=340+40,y4=240-20;
        int x5=420+40,y5=180-20;
        int x6=340+40,y6=140-20;
        int x7=260+40,y7=200-20;
        int x8=240,y8=220;
        int x9=180,y9=260;
        int x10=140,y10=200;
        int x11=100,y11=120;
        int x12=110,y12=290;
        int x13=260,y13=120;
        int x14=260,y14=400;

        initgraph(&gd,&gm," ");
        /*setcolor(WHITE);
        circle (x0,y0,20);
        circle (x1,y1,20);
        line(x0,y0,x1,y1);
        circle(x2,y2,20);
        line (x1,y1,x2,y2);
        circle (x3,y3,20);
        line (x2,y2,x3,y3);
        circle(x4,y4,20);
        line(x3,y3,x4,y4);
        circle(x5,y5,20);
        line (x4,y4,x5,y5);
        circle (x6,y6,20);
        line (x5,y5,x6,y6);
        circle(x7,y7,20);
        line(x6,y6,x7,y7);
        circle(x8,y8,20);
        line(x7,y7,x8,y8);
        circle(x9,y9,20);
        line(x8,y8,x9,y9);
        circle(x10,y10,20);
        line (x9,y9,x10,y10);
        circle(x11,y11,20);
        line(x10,y10,x11,y11);
        circle(x12,y12,20);
        line (x9,y9,x12,y12);
        line (x9,y9,x2,y2);
        circle(x13,y13,20);
        line(x13,y13,x7,y7);
        circle(x14,y14,20);
        line(x14,y14,x2,y2);
        outtextxy(x0,y0,"0");
        outtextxy(x1,y1,"1");
        outtextxy(x2,y2,"2");
        outtextxy(x3,y3,"3");
        outtextxy(x4,y4,"4");
        outtextxy(x5,y5,"5");
        outtextxy(x6,y6,"6");
        outtextxy(x7,y7,"7");
        outtextxy(x8,y8,"8");
        outtextxy(x9,y9,"9");
        outtextxy(x10,y10,"10");
        outtextxy(x11,y11,"11");
        outtextxy(x12,y12,"12");
        outtextxy(x13,y13,"13");
        outtextxy(x14,y14,"14");*/

        int mat[15][15]={{0,8,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {8,0,14,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,14,0,7,0,0,0,0,0,9,0,0,0,0,21},
            {0,0,7,0,10,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,10,0,7,0,13,0,0,0,0,0,0,0},
            {0,0,0,0,7,0,4,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,4,0,5,0,0,0,0,0,0,0},
            {0,0,0,0,13,0,5,0,2,0,0,0,0,8,0},
            {0,0,0,0,0,0,0,2,0,19,0,0,0,0,0},
            {0,0,9,0,0,0,0,0,19,0,15,0,4,0,0},
            {0,0,0,0,0,0,0,0,0,15,0,5,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,5,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,4,0,0,0,0,0},
            {0,0,0,0,0,0,0,8,0,0,0,0,0,0,0},
            {0,0,21,0,0,0,0,0,0,0,0,0,0,0,0}};

    for(int i=0;i<15;i++)
    {
        n[i]=new node;
        n[i]->data=i;
        n[i]->left=NULL;
        n[i]->right=NULL;
        n[i]->up=NULL;
        n[i]->down=NULL;

    }

    n[0]->right=n[1];
    n[1]->left=n[0];n[1]->right=n[2];
    n[2]->right=n[3];n[2]->left=n[1];n[2]->down=n[14];n[2]->up=n[9];
    n[3]->right=n[4];n[3]->left=n[2];
    n[4]->right=n[5];n[4]->left=n[3];n[4]->up=n[7];
    n[5]->left=n[4];
    n[6]->left=n[7];
    n[7]->right=n[6];n[7]->left=n[8];n[7]->down=n[4];n[7]->up=n[13];
    n[8]->right=n[7];n[8]->left=n[9];
    n[9]->right=n[8];n[9]->left=n[12];n[9]->down=n[2];n[9]->up=n[10];
    n[10]->down=n[9];n[10]->up=n[11];
    n[11]->down=n[10];
    n[12]->right=n[9];
    n[13]->down=n[7];
    n[14]->up=n[2];
    int choice;
    cout<<"\t\t\t//******Welcome to our transportation system******//"<<endl<<endl;
    g:
    setcolor(WHITE);
    circle (x0,y0,20);
        circle (x1,y1,20);
        line(x0,y0,x1,y1);
        circle(x2,y2,20);
        line (x1,y1,x2,y2);
        circle (x3,y3,20);
        line (x2,y2,x3,y3);
        circle(x4,y4,20);
        line(x3,y3,x4,y4);
        circle(x5,y5,20);
        line (x4,y4,x5,y5);
        circle (x6,y6,20);
        line (x5,y5,x6,y6);
        circle(x7,y7,20);
        line(x6,y6,x7,y7);
        circle(x8,y8,20);
        line(x7,y7,x8,y8);
        line(x7,y7,x4,y4);
        circle(x9,y9,20);
        line(x8,y8,x9,y9);
        circle(x10,y10,20);
        line (x9,y9,x10,y10);
        circle(x11,y11,20);
        line(x10,y10,x11,y11);
        circle(x12,y12,20);
        line (x9,y9,x12,y12);
        line (x9,y9,x2,y2);
        circle(x13,y13,20);
        line(x13,y13,x7,y7);
        circle(x14,y14,20);
        line(x14,y14,x2,y2);
        outtextxy(x0,y0,"0");
        outtextxy(x1,y1,"1");
        outtextxy(x2,y2,"2");
        outtextxy(x3,y3,"3");
        outtextxy(x4,y4,"4");
        outtextxy(x5,y5,"5");
        outtextxy(x6,y6,"6");
        outtextxy(x7,y7,"7");
        outtextxy(x8,y8,"8");
        outtextxy(x9,y9,"9");
        outtextxy(x10,y10,"10");
        outtextxy(x11,y11,"11");
        outtextxy(x12,y12,"12");
        outtextxy(x13,y13,"13");
        outtextxy(x14,y14,"14");
    cout<<"Which choice would you prefer?"<<endl;
    cout<<"1. Cab service "<<endl;
    cout<<"2. Bus transport"<<endl;
    cout<<"3. Exit"<<endl;
    //cout<<"Or press 0 to have a look at the map"<<endl;
    cout<<"Please enter your choice:"<<endl;
    cin>>choice;
    switch(choice)
    {
    case 1:
        cout<<"Enter source you want to start from: "<<endl;
        cin>>src;
        cout<<"Enter destination you want to reach to: "<<endl;
        cin>>dest;
        dijkstra(mat,src,dest);
        setcolor(RED);
        for (int j=0;j<k;j++)
        {
            if(drline[j]==0 && drline[j+1]==1 ||drline[j]==1 && drline[j+1]==0)
                line (x0,y0,x1,y1);
            if(drline[j]==1 && drline[j+1]==2 || drline[j]==2 && drline[j+1]==1)
                line (x1,y1,x2,y2);
            if(drline[j]==2 && drline[j+1]==3 || drline[j]==3 && drline[j+1]==2)
                line (x2,y2,x3,y3);
            if(drline[j]==3 && drline[j+1]==4 ||drline[j]==4 && drline[j+1]==3)
                line (x3,y3,x4,y4);
            if(drline[j]==4 && drline[j+1]==5 ||drline[j]==5 && drline[j+1]==4)
                line (x4,y4,x5,y5);
            if(drline[j]==5 && drline[j+1]==6 ||drline[j]==6 && drline[j+1]==5)
                line (x5,y5,x6,y6);
            if(drline[j]==6 && drline[j+1]==7 ||drline[j]==7 && drline[j+1]==6)
                line (x6,y6,x7,y7);
            if(drline[j]==7 && drline[j+1]==8 ||drline[j]==8 && drline[j+1]==7)
                line (x7,y7,x8,y8);
            if(drline[j]==7 && drline[j+1]==4 ||drline[j]==4 && drline[j+1]==7)
                line (x7,y7,x4,y4);
            if(drline[j]==8 && drline[j+1]==9 ||drline[j]==9 && drline[j+1]==8)
                line (x8,y8,x9,y9);
             if(drline[j]==9 && drline[j+1]==10 ||drline[j]==10 && drline[j+1]==9)
                line (x9,y9,x10,y10);
             if(drline[j]==10 && drline[j+1]==11 ||drline[j]==11 && drline[j+1]==10)
                line (x10,y10,x11,y11);
              if(drline[j]==9 && drline[j+1]==12 ||drline[j]==12 && drline[j+1]==9)
                line (x9,y9,x12,y12);
              if (drline[j]==9 && drline[j+1]==2 ||drline[j]==2 && drline[j+1]==9)
                line (x9,y9,x2,y2);
               if(drline[j]==2 && drline[j+1]==14 ||drline[j]==14 && drline[j+1]==2)
                line (x2,y2,x14,y14);
              if(drline[j]==7 && drline[j+1]==13 ||drline[j]==13 && drline[j+1]==7)
                line (x7,y7,x13,y13);
        }
    cout<<"press c to continue"<<endl;
    cin>>cont;
    if(cont=='c')
    {
        goto g;
    }
    getch();
    closegraph();
    case 2:
        cout<<"Enter source you want to start from: "<<endl;
        cin>>src;
        cout<<"Enter destination you want to reach to: "<<endl;
        cin>>dest;
        findpath(src,dest);
        setcolor(CYAN);
for (int j=0;j<ind;j++)
{
    if(sol[j]==0 && sol[j+1]==1 || sol[j]==1 && sol[j+1]==0)
        line (x0,y0,x1,y1);
    if(sol[j]==1 && sol[j+1]==2 || sol[j]==2 && sol[j+1]==1)
        line (x1,y1,x2,y2);
    if(sol[j]==2 && sol[j+1]==3 || sol[j]==3 && sol[j+1]==2)
        line (x2,y2,x3,y3);
    if(sol[j]==3 && sol[j+1]==4 || sol[j]==4 && sol[j+1]==3)
        line (x3,y3,x4,y4);
    if(sol[j]==4 && sol[j+1]==5 ||sol[j]==5 && sol[j+1]==4)
        line (x4,y4,x5,y5);
    if(sol[j]==5 && sol[j+1]==6 ||sol[j]==6 && sol[j+1]==5)
        line (x5,y5,x6,y6);
    if(sol[j]==6 && sol[j+1]==7 ||sol[j]==7 && sol[j+1]==6)
        line (x6,y6,x7,y7);
    if(sol[j]==7 && sol[j+1]==8 || sol[j]==8 && sol[j+1]==7)
        line (x7,y7,x8,y8);
    if(sol[j]==7 && sol[j+1]==4 || sol[j]==4 && sol[j+1]==7)
        line (x7,y7,x4,y4);
    if(sol[j]==8 && sol[j+1]==9 ||sol[j]==9 && sol[j+1]==8)
        line (x8,y8,x9,y9);
     if(sol[j]==9 && sol[j+1]==10 ||sol[j]==10 && sol[j+1]==9)
        line (x9,y9,x10,y10);
     if(sol[j]==10 && sol[j+1]==11 ||sol[j]==11 && sol[j+1]==10)
        line (x10,y10,x11,y11);
      if(sol[j]==9 && sol[j+1]==12 ||sol[j]==12 && sol[j+1]==9)
        line (x9,y9,x12,y12);
      if (sol[j]==9 && sol[j+1]==2 ||sol[j]==2 && sol[j+1]==9)
        line (x9,y9,x2,y2);
       if(sol[j]==2 && sol[j+1]==14 ||sol[j]==14 && sol[j+1]==2)
        line (x2,y2,x14,y14);
      if(sol[j]==7 && sol[j+1]==13 ||sol[j]==13 && sol[j+1]==7)
        line (x7,y7,x13,y13);
}
cout<<"press c to continue"<<endl;
cin>>cont;
if(cont=='c')
{
    goto g;
}
getch();
closegraph();
    case 3:
        exit(1);
    }
    return 0;
}
