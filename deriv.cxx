#include <iostream>
#include <cmath>

using namespace std;


void print(double* p, const int N, const double dx,const double xmin)
{
   for(int i=0; i<N; i++)
       cout << i*dx + xmin << "\t" << p[i] << endl;

}

double* fillarray(double* p, const int N, const double dx,const double xmin){
	double a = 0;
	for(int i = 0; i < N; i++){
		a = xmin + (i * dx);
		p[i] = exp(-(a*a));

	}

}

double* derive(double* p, const int N, const double dx){
	double xim1 = 0;
	double xip1 = p[1];
	double xtemp = 0;
	for(int i = 0; i < N ; i++){
		xtemp = p[i];
		p[i] = (xip1-xim1)/(2.*dx);
		xim1 = xtemp;
		xip1 = p[i+2];
}
}



int main(){
  const int N = 256;
  double p[N];
  const double xmax = 15;
  const double xmin = -15;
  const double dx = (xmax-xmin)/(N-1);



  // call to function which fills array p here
  fillarray(p,N,dx,xmin);
  // call to functio which calculates the derivative
  derive(p,N,dx);


  print(p,N,dx,xmin);

  return 0;
}
