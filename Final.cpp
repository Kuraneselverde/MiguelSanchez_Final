#include <iostream>
#include <fstream>
#include <cmath>


using namespace std;

int main()
{
  double dt=0.1;
  int nt=int(10/dt);  
  double m=7294.29;
  double q=2.0;
  double Ex[nt];
  double Ey[nt];  
  double X[nt];
  double Y[nt];
  double vx[nt];
  double vy[nt];
  double vxm[nt];
  double vym[nt];   
    
  ofstream outfile;
  
  for(int i=0;i<nt;i++)
  {
      if (i<30)
      {
          Ex[i]=0.0;
          Ey[i]=0.0;
      }
      else if(29<i<70)
      {
          Ex[i]=0.0;
          Ey[i]=3.0;
      }
      else if(29<i<70)
      {
          Ex[i]=0.0;
          Ey[i]=0.0;
      }
  }  
  
  X[0]=1.0;
  Y[0]=0.0;  
  
  vx[0]=0.0;
  vy[0]=1.0;
    
  vxm[0]=0.0;
  vym[0]=1.0;  
  
  outfile.open("datos.dat");
  
  double T=0.0;
  for(int t=0;t<(nt-1);t++)
  {
      T+=dt;
      vxm[t+1]=vx[t]+ ((q/m)*Ex[t]*dt)/2;
      vym[t+1]=vy[t]+ ((q/m)*Ey[t]*dt)/2;
      X[t+1]=X[t]+(vxm[t]*dt);
      Y[t+1]=Y[t]+(vym[t]*dt);
      vx[t+1]=vxm[t]+ ((q/m)*Ex[t+1]*dt)/2;
      vy[t+1]=vym[t]+ ((q/m)*Ey[t+1]*dt)/2;
      outfile << X[t+1] << " " << Y[t+1] << " " << T << endl;       
  } 
  return 0;
}
