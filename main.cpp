#include <iostream>

using namespace std;

void block_partition(float *A[], int m,int n)
{
    float a[m/2][n/2];
    float b[m/2][n-(n/2)];
    float c[m-(m/2)][n/2];
    float d[m-(m/2)][n-(n/2)];

    for(int i=0; i < (m/2);i++)
    {
        for(int j=0; j < (n/2); j++)
        {
            a[i][j] = A[i][j];
        }
    }

    for(int i=0; i < (m/2);i++)
    {
        for(int j=0; j < (n- n/2); j++)
        {
            b[i][j] = A[0+i][(n/2)+j];
        }
    }

    for(int i=0; i < (m - m/2);i++)
    {
        for(int j=0; j < (n - n/2); j++)
        {
            c[i][j] = A[(m/2)+i][0 + j];
        }
    }

    for(int i=0; i < (m - m/2);i++)
    {
        for(int j=0; j < (n- n/2); j++)
        {
            d[i][j] = A[(m/2) + i][(n/2) + j];
        }
    }


    /* just to print all array to check correct block partition*/

    for(int i=0; i < (m/2);i++)
    {
        for(int j=0; j < (n/2); j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    for(int i=0; i < (m/2);i++)
    {
        for(int j=0; j < (n- n/2); j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;

    }
    cout << endl;

    for(int i=0; i < (m- m/2);i++)
    {
        for(int j=0; j < (n/2); j++)
        {
            cout << c[i][j] << " ";//= A[(m/2 + 1)+i][0 + j];
        }
        cout << endl;
    }

    cout << endl;

    for(int i=0; i < (m- m/2);i++)
    {
        for(int j=0; j < (n- n/2); j++)
        {
            cout << d[i][j] << " ";// = A[(m/2 + 1) + i][(n/2 + 1) + j];
        }
        cout << endl;
    }
}

/**
  * Function return block number to which (i,j) belongs.
  * @param i,j denotes position
  * @param m,n matrix of size m by n
  * @authr some user (this is the documentation keyword error)
  */
int block_number(int i,int j, int m, int n)
{
    if( i < m/2 && j < n/2)
        return 0;
    else if(i < m/2 && j >= n/2)
        return 1;
    else if(i >= m/2 && j < n/2)
        return 2;
    else
        return 3;
}

float** block_wise_mul(float *A[],float *B[],int m, int n, int p)
{
    /**
    * C = A*B
    */
    float *C[m];
    for(int i=0; i < m; i++)
        C[i] = new float[p];

    if(m==1 && n==1 && p==1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }



    float *a[m/2];
    for(int i=0; i < m/2;i++)
        a[i] = new float[n/2];

    float *b[m/2];
    for(int i=0; i < m/2;i++)
        a[i] = new float[n-(n/2)];

    float *c[m-(m/2)];
    for(int i=0; i < m/2;i++)
        a[i] = new float[n/2];

    float *d[m-(m/2)];
    for(int i=0; i < m/2;i++)
        a[i] = new float[n-(n/2)];



    float *e[n/2];
    for(int i=0; i<n/2; i++)
        e[i] = new float[p/2];

    float *f[n/2];
    for(int i=0; i < m/2;i++)
        a[i] = new float[p-(p/2)];

    float *g[n-(n/2)];
    for(int i=0; i < m/2;i++)
        a[i] = new float[p/2];

    float *h[n-(n/2)];
    for(int i=0; i < m/2;i++)
        a[i] = new float[p-(p/2)];


    /**
    Breaking of matrix A into blocks
    */

    for(int i=0; i < (m/2);i++)
    {
        for(int j=0; j < (n/2); j++)
        {
            a[i][j] = A[i][j];
        }
    }

    for(int i=0; i < (m/2);i++)
    {
        for(int j=0; j < (n- n/2); j++)
        {
            b[i][j] = A[0+i][(n/2)+j];
        }
    }

    for(int i=0; i < (m - m/2);i++)
    {
        for(int j=0; j < (n - n/2); j++)
        {
            c[i][j] = A[(m/2)+i][0 + j];
        }
    }

    for(int i=0; i < (m - m/2);i++)
    {
        for(int j=0; j < (n- n/2); j++)
        {
            d[i][j] = A[(m/2) + i][(n/2) + j];
        }
    }


    /**
    breaking of matrix B into blocks
    */

    for(int i=0; i < (n/2);i++)
    {
        for(int j=0; j < (p/2); j++)
        {
            a[i][j] = A[i][j];
        }
    }

    for(int i=0; i < (n/2);i++)
    {
        for(int j=0; j < (p- p/2); j++)
        {
            b[i][j] = A[0+i][(p/2)+j];
        }
    }

    for(int i=0; i < (n - n/2);i++)
    {
        for(int j=0; j < (p - p/2); j++)
        {
            c[i][j] = A[(n/2)+i][0 + j];
        }
    }

    for(int i=0; i < (n - n/2);i++)
    {
        for(int j=0; j < (p- p/2); j++)
        {
            d[i][j] = A[(n/2) + i][(p/2) + j];
        }
    }

    /**
    float a[m/2][n/2];
    float b[m/2][n-(n/2)];
    float c[m-(m/2)][n/2];
    float d[m-(m/2)][n-(n/2)];

    float e[n/2][p/2];
    float f[n/2][p-(p/2)];
    float g[n-(n/2)][p/2];
    float h[n-(n/2)][p-(p/2)];
    */

    float **a_e = block_wise_mul(a, e, m/2, n/2, p/2);
    float **b_g = block_wise_mul(b, g, m/2, n- (n/2), p/2);
    float **a_f = block_wise_mul(a, f, m/2, n/2, p-(p/2));
    float **b_h = block_wise_mul(b, h, m/2, n - (n/2), p - (p/2));
    float **c_e = block_wise_mul(c, e, m-(m/2), n/2, p/2);
    float **d_g = block_wise_mul(d, g, m-(m/2), n-(n/2), p/2);
    float **c_f = block_wise_mul(c, f, m-(m/2), n/2, p-(p/2));
    float **d_h = block_wise_mul(d, h, m-(m/2), n-(n/2), p-(p/2));

    for(int i=0; i< m; i++)
    {
        for(int j=0; j < n; j++)
        {
            switch(block_number(i,j, m, n))
            {
                case 0:
                    C[i][j] = a_e[i][j] + b_g[i][j];
                    break;
                case 1:
                    C[i][j] = a_f[i][j-(n/2 + 1)] + b_h[i][j-(n/2 + 1)];
                    break;
                case 2:
                    C[i][j] = c_e[i - (m/2 + 1)][j] + d_g[i - (m/2 + 1)][j];
                    break;

                case 3:
                    C[i][j] = c_f[i - (m/2 + 1)][j - (n/2 + 1)] + d_h[i - (m/2 + 1)][j - (n/2 + 1)];
                    break;

            }
        }
    }


    return C;
}
void strassen(float *A[],float *B[],int m, int n, int p)
{
    /*float p1[m/2];
    for(int i=0;i < m/2 ;i++)
        p[i] = new float[n-n/2]

    float p2[5];*/
}

int main()
{
    cout << "Hello world!" << endl;

    int m = ( rand() % 5) + 1;
    int n = ( rand() % 5) + 1;
    int p = (rand() % 5) + 1;

    float *A[m];
    for(int i=0;i < m;i++)
        A[i] = new float[n];

    for(int i=0; i< m; i++)
        for(int j=0; j< n;j++)
            A[i][j] = (rand() % 100) + 1;

    //print complete array
    /*
    for(int i=0;i < m;i++)
    {
        for(int j=0;j<n;j++)
            cout << A[i][j] << " ";
        cout << endl;
    }*/

    float *B[m];
    for(int i=0;i < n;i++)
        A[i] = new float[p];

    for(int i=0; i< n; i++)
        for(int j=0; j< p;j++)
            B[i][j] = (rand() % 100) + 1;



    block_wise_mul(A, B, m, n, p);
    return 0;
}
