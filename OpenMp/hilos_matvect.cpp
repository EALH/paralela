/*mat_as_vect.cpp
 *  Manejar una matriz como un conjunto de  vectores
 *  Created by mav on 04/03/20.
 *  Copyleft 2020 __UAEM__. Zumpango. */
#include <cstdio>
#include <cstdlib>
#include<pthread.h>
#include<iostream>
#include<fstream>
using namespace std;
/*estructura de paso de datos a la funcion*/
struct params
{
	/* Los vectores amultiplicar.  */
	float *w1;
	float *w2;
	/* The numero de productos.  */
	int cols;
	//inicio de conteo y final
	int inic;
};
//arreglos de hilos y de estructuras
pthread_t thread_id[4];
struct params thr_arg[4];
//declaracion de matriz y vectores
float **A;
float *v,*w;
//funciones para menejos de la matriz y los vectores
float** crea_mat(int ,int );
float * crea_vect(int );
//int ini_mat(float **,int ,int );
int ini_vect(float *,int );
int muestra_mat(float **,int ,int );
int muestra_vect(float *,int );
void* mult_hilo (void* );
float  prod_vv(float *,float *,int );
float** lee_mat(char *,int ,int );
float* lee_vect(char *,int );

int main(int argc,char * argv[]){
	int i,k,hi;
	int ren=atoi(argv[1]);
	int col=atoi(argv[2]);
char nommat[9]="matA.dat";
char nomvect[9]="vecV.dat";
	A=crea_mat(ren,col);
	A=lee_mat(nommat,ren,col);
	//ini_mat(A,ren,col);
	v=crea_vect(col);
	v=lee_vect(nomvect,ren);
	//ini_vect(v,col);
	w=crea_vect(ren);
	ini_vect(w,ren );
		for (i=0;i<ren;i++){
		//definimos que hilo va a procesar el renglon i,0,1,2,3
			hi=i%4;
		thr_arg[hi].w1=A[i];
		thr_arg[hi].w2=v;
		thr_arg[hi].cols=col;
		thr_arg[hi].inic=i;
		pthread_create (&thread_id[hi], NULL, &mult_hilo, &thr_arg[hi]);
		//cout<<thread_id[hi]<<endl;
		//pthread_join (thread_id[hi], NULL);
		}
	for (i=0;i<ren%4;i++){
	pthread_join (thread_id[hi], NULL);}
	muestra_vect(w,ren);
	pthread_exit(NULL);
	return 0;}
	//definicion de funciones
float* lee_vect(char *nom_arch,int m)
{ int i;
	float *VV;
	VV=crea_vect(m);
	ini_vect(VV,m);
	fstream fd2;
	/* para lectura es in escritura out*/
	fd2.open(nom_arch,ios::in);
	while(!fd2.eof())
		{ int i,j;
			for (i=0;i<m;i++)
				{
					fd2>>VV[i];
				}
						}
	fd2.close();
	cout<<"vector leido"<<endl;
	return VV;}
float** crea_mat(int m,int n)
{ int j;
	float **M;
	M=new float*[m];
	for (j=0;j<m;j++){M[j]=new float[n];}
	return M;}
//crea vector dinamico
float * crea_vect(int m)
{
	float *VV;
	VV=new float[m];
	return VV;}

int ini_vect(float *M,int m)
{ int j;
		for (j=0;j<m;j++)
		{	M[j]=0.1;}
	return 0;}
int muestra_mat(float **M,int m,int n)
{ int i,j;
	for (i=0;i<m;i++)
	{
		for (j=0;j<m;j++)
		{ cout<<M[i][j]<<" "; }
		cout<<endl;
	}
	return 0;}

int muestra_vect(float *M,int m)
{ int j;
		for (j=0;j<m;j++)
		{ cout<<M[j]<<" ,"; }
		cout<<endl;
	return 0;
}
/*Calcula producto de vector por vector  */
float  prod_vv(float *MM,float *UU,int n)
{
	int j;
	float W=0;

	for (j=0;j<n;j++){

		W= W+MM[j]*UU[j];
	}
	return W;
}

void* mult_hilo (void* parameters)
{
	/* Cast the cookie pointer to the right type.  */
	struct params* p=(struct params*) parameters;
	int i,k;
	i=p->inic;
	w[i]=prod_vv(p->w1,p->w2,p->cols);
	return NULL;}
float** lee_mat(char *nom_arch,int m,int n)
{ int i,j;
float **MM;
	MM=crea_mat(m,n);
	//ini_mat(MM,m,n);
	fstream fd1;
	/* para lectura es in escritura out*/
	fd1.open(nom_arch,ios::in);
	while(!fd1.eof())
		{ int i,j;
			for (i=0;i<m;i++)
				{
					for (j=0;j<n;j++)
						{ fd1>>MM[i][j];}
				}
		}
	fd1.close();
	cout<<"Matriz leida"<<endl;
	return MM;
}


