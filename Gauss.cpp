#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<iostream.h>

void sort (float  **a, int n,int l)
{
	float max=0,d;
	int maxi=0;
   int i;

	for(i=l;i<n;i++)
	{
		if(fabs(a[i][l])>max)
		{

			max=fabs(a[i][l]);
			maxi=i;
		}
	}

	for(i=0;i<n+1;i++)
	{
		d=a[l][i];
		a[l][i]=a[maxi][i];
		a[maxi][i]=d;
	}
		
}

void Gaysa (float **M,int n)
{
	int i,j,l;
	float *x,d;
	x=new  float[n];	
	for(l=0;l<n;l++)
	{
		sort(M,n,l);
		for(i=l;i<n-1;i++)
		{
			d=M[i+1][l]/M[l][l];
			for(j=l;j<n+1;j++)
				M[i+1][j]=M[i+1][j]-d*M[l][j];
		}
	}

	x[n-1]=M[n-1][n]/M[n-1][n-1];

	for(i=n-1-1,l=1;i>=0;i--,l++)
	{
		d=0;
		for(j=n-l;j<n;j++)
		{
			d=d+x[j]*M[i][j];
		}
		x[i]=(M[i][n]-d)/M[i][i];
	}

	cout<<"\nIXI \n";
	for(i=n-1;i>=0;i--)
	{
		cout<<"X"<<i+1<<"="<<x[i];
		cout<<"\n";
	}                     
	
	system("pause");
}


void main()
{
        clrscr();
        float **mat=NULL;  //Матрица
        int i,j;         //Счетчики цикла
        int v,u;         //Кол-во строк и столбцов
        float *max;  //Максимальный элемент строки
        float *min;  //Минимальный элемент строки
        int ret=0;
        
        int n,x,y;
        int nCount=0;
        char st[50];
        float f;



        //printf("Vvedite st->");
        //cin >> st;
        //scanf("%s",&st);
        //printf("n mod 0.1=%f ",n % 0.1);
        //printf("n div 0.1=%f \n",n / 0.1);
        nCount=strlen(st);
        f = atof(st);
        //printf(" nCount=%d f=%2f ",nCount,f);



        /*
        while(n != 0)
        {
        n = n / 10;
        printf(" N=%d ",n);
        nCount++;
        }
        printf("END=%d",nCount);

        getch();
        x=wherex(); y=wherey(); gotoxy(10,10); printf("x=%d y=%d",x,y); gotoxy(x,y);
        */

        //Создание матрицы
        printf("Vvedite kol-vo strok->");
        scanf("%d",&v);
        printf("Vvedite kol-vo stolbcov->");
        scanf("%d",&u);



        mat = new float*[v];
        for (i=0;i<v;i++)
        {
                mat[i]= new float[u];
        }

        //Ввод матрицы
        printf("Vvedite matricy:\n");
        for (i=0;i<v;i++)
        for (j=0;j<u;j++)
                {                
                gotoxy(j*2+1,i+4);
                scanf ("%f",&mat[i][j]);

                }

        clrscr();
        printf("Ishodnaia matrica:");
        for (i=0;i<v;i++)
        {
                printf("\n");
                for (j=0;j<u;j++)
                printf ("%f ",mat[i][j]);
        }

        Gaysa(mat,v);
                                           /*
       //Поиск максимального и минимального элементов
        for (i=0;i<v;i++)
        {
                max=&mat[i][0];
                min=&mat[i][0];
                for (j=1;j<u;j++)
                {
                        if (mat[i][j]>*max)
                        max=&mat[i][j];
                        if (mat[i][j]<*min)
                        min=&mat[i][j];
                }
                //Элементы меняются местами
                int n;
                n=*max;
                *max=*min;
                *min=n;
                }

        //Вывод матрицы
        printf("\nPolucenaia matrica:");
        for (i=0;i<v;i++)
        {
                printf("\n");
                for (j=0;j<u;j++)
                printf ("%d ",mat[i][j]);
        }                     */

        getch();
}
