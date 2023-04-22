//*****������� ������ ��������� ������� �����*****//

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>
#define E 0.01

float **mat=NULL;	//�������
float **mat2=NULL;	//��������������� �������
float *mat3=NULL;	//������������ ������� �������� k-1
float *mat4=NULL;	//������������ ������� �������� k
int i,j;		//�������� �����
int u;			//���-�� ���������
int nCount=0;	//���������� ��������

void PrintIter();

bool Compare() //������� ��������� �������: |(k-1)-k|<E
{
	if(nCount==100) {printf("\n\nMatrix is not decide!!!"); return false; }
	for (i=0;i<u;i++)
	{
		//PrintIter(); //�������� �������� �� �����, ����� �������� �������� ����� ����������������
		if (fabs(mat4[i]-mat3[i])>E)
			return true;
	}
	return false;


}

void Print(float num) //������� �� ����� �����
{
	if(num<0) printf("%.2f ",num);
	else      printf(" %.2f ",num);
}

void PrintIter()  //������� �� ����� ��������
{
	printf("\nIteracia %d:",nCount);
	if (fabs(mat4[i]-mat3[i])>10)
		printf(" X%d=%.0f E=%.1f",i+1,mat4[i],mat4[i]-mat3[i]);
	else	printf(" X%d=%f E=%f",i+1,mat4[i],mat4[i]-mat3[i]);

}

void main()
{
	//setlocale(LC_CTYPE,"Russian");
	clrscr();
	char num[50]={NULL}; //��������� �����
	
	//�������� ������
	printf("Vvedi kol-vo uravneniy>:");
	scanf("%d",&u);   
	mat = new float*[u];
	for (i=0;i<u;i++)
		mat[i]= new float[u+1];

	mat2 = new float*[u];
	for (i=0;i<u;i++)
		mat2[i]= new float[u+1];

	mat3 = new float[u+1];  
	mat4 = new float[u+1];
	for (i=0;i<u+1;i++) { mat3[i]=1; mat4[i]=1; }


	//���� �������
	printf("\nVvedite matricy:\n");
	for (i=0;i<u;i++)
	{
		nCount=0;
		for (j=0;j<u+1;j++)
		{
			gotoxy(j+nCount+1,i+4);
			scanf("%s",num);
			nCount+=strlen(num);
			mat[i][j]=atof(num);
		}	      
	}

	
	printf("\nIshodnaia matrica:");
	for (i=0;i<u;i++)
	{
		printf("\n");
		for (j=0;j<u+1;j++)
			Print(mat[i][j]);
	}


	//�������������� � �������������� ����
	for(i=0;i<u;i++)
		for (j=0;j<u;j++)
			mat2[i][j]=-(mat[i][j]/mat[i][i]);
	for(i=0;i<u;i++)
	{
		mat2[i][i]=0;
		mat2[i][u]=mat[i][u]/mat[i][i];
	}

		
	printf("\n\nPreobrazovanaia matrica:");
	for (i=0;i<u;i++)
	{
		printf("\n");
		for (j=0;j<u+1;j++)
			Print(mat2[i][j]);
	}


	nCount=0;
	do //��������
	{
		nCount++;
		for(i=0;i<u;i++) //�������� ������� 4 � ������� 3
			mat3[i]=mat4[i];

		for (i=0;i<u;i++)
		{
			mat4[i]=0;
			for (j=0;j<u+1;j++)
				mat4[i]+=mat2[i][j]*mat3[j];
		}

	} while(Compare());


	printf("\n\nOTVET:");
	for (i=0;i<u;i++)
		printf(" X%d=%.4f ",i+1,mat4[i]);
	printf("\nIteraciy=%d",nCount);

	delete []mat;
	delete []mat2;
	delete []mat3;
	delete []mat4;
	getch();
}

