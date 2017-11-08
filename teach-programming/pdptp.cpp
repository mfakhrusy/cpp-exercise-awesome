#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
int main()
{
    //KAMUS
    float i,x,n,fs,N,fx,error,interval;
    float L = 10;
    int p;
    const float phi = 22/7;
    //ALGORITMA
    do
    {
        cout << "Pilihan menu : \n";
        cout << "1. Soal nomor 1 \n";
        cout << "2. Soal nomor 2 \n";
        cout << "3. Exit \n";
        cout << "Masukkan pilihan : "; cin >> p;
        //JIKA PILIHAN NOMOR 1
        if(p==1)
        {
            cout << "Masukkan nilai x : "; cin >> x;
            fx=x;
            cout << "Jadi nilai fx = " << fx << endl;
        }
        //JIKA PILIHAN NOMOR 2
        else if (p==2)
        {
            cout << "Masukkan nilai L : "; cin >> L;
            cout << "Masukkan interval : "; cin >> interval;
            
            ofstream outfile;
            outfile.open ("Number_2.txt");
            
            outfile<<"x		N		 fs			error"<<endl;
			for(x=-L;x<=L;x=x+interval)
            {

                N=1;
                fs=0;
                for(n=1;n<=N;n++)
                {
                    fs=-2*L*pow(-1,n)*sin(n*phi*x/L)/(n*phi) + fs;
                }

                error = (fs-x)/x*100;
                if(error<0)
                {
                    error=error*-1;
                }
                outfile<<x<<"		"<<N<<"		"<<fs<<"			"<<error<<endl;

                N=3;
                fs=0;
                for(n=1;n<=N;n++)
                {
                    fs=-2*L*pow(-1,n)*sin(n*phi*x/L)/(n*phi) + fs;
                }

                error = (fs-x)/x*100;
                if(error<0)
                {
                    error=error*-1;
                }
                outfile<<x<<"		"<<N<<"		"<<fs<<"			"<<error<<endl;

                N=10;
                fs=0;
                for(n=1;n<=N;n++)
                {
                    fs=-2*L*pow(-1,n)*sin(n*phi*x/L)/(n*phi) + fs;
                }

                error = (fs-x)/x*100;
                if(error<0)
                {
                    error=error*-1;
                }
                outfile<<x<<"		"<<N<<"		"<<fs<<"			"<<error<<endl;

                N=100;
                fs=0;
                for(n=1;n<=N;n++)
                {
                    fs=-2*L*pow(-1,n)*sin(n*phi*x/L)/(n*phi) + fs;
                }

                error = (fs-x)/x*100;
                if(error<0)
                {
                    error=error*-1;
                }
                outfile<<x<<"		"<<N<<"		"<<fs<<"			"<<error<<endl;

            }
            outfile.close ();
        }
    }while(p!=3);
    return 0;
}
