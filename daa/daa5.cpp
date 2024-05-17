#include <iostream>
using namespace std;

const int N = 4;     // Matrix size
// N must be a power of 2 (N = 2^k)
// If N is not a power of 2, we add additional rows and columns as needed
// This program automatically does not add extra rows and columns

template<typename T>
void Strassen(int n, T A[][N], T B[][N], T C[][N]);

template<typename T>
void input(int n, T p[][N]);

template<typename T>
void output(int n, T C[][N]);

int main() {

    int A[N][N],B[N][N],C[N][N];

    cout<<"Enter A\n";
    input(N,A);
    cout<<"\nEnter B\n";
    input(N,B);
    cout<<"\nMatrix A is:\n";
    output(N, A);
    cout<<"\nMatrix B is:\n";
    output(N, B);

    //C=A*B
    Strassen(N, A, B, C);

    output(N, C);

    return 0;
}

// Input
template<typename T>
void input(int n, T p[][N]) {
     for(int i=0; i<n; i++) {
        cout<<"Please Input Line "<<i+1<<endl;
        for(int j=0; j<n; j++) {
           cin>>p[i][j];
        }
     }
}

// Output
template<typename T>
void output(int n, T C[][N]) {
    cout<<"\n";
     for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
           cout<<C[i][j]<<"\t";
        }
        cout<<"\n";
     }
}

// Multiplication
template<typename T>
void Matrix_Multiply(T A[][N], T B[][N], T C[][N]) {  // Calculating A*B -> C
     //output(2,A);
     //output(2,B);
     for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
           C[i][j] = 0;
           for(int t=0; t<2; t++) {
              C[i][j] = C[i][j] + A[i][t]*B[t][j];
           }
        }
     }
}

// Addition
template <typename T>
void Matrix_Add(int n, T X[][N], T Y[][N], T Z[][N]) {
     //output(n,X);
     //output(n,Y);
     for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
           Z[i][j] = X[i][j] + Y[i][j];
        }
     }
}

// Under construction
template <typename T>
void Matrix_Sub(int n, T X[][N], T Y[][N], T Z[][N]) {
     for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
           Z[i][j] = X[i][j] - Y[i][j];
        }
     }
}

//              STRASSEN
template <typename T>
void Strassen(int n, T A[][N], T B[][N], T C[][N]) {
     T A11[N][N], A12[N][N], A21[N][N], A22[N][N];
     T B11[N][N], B12[N][N], B21[N][N], B22[N][N];
     T C11[N][N], C12[N][N], C21[N][N], C22[N][N];
     T M1[N][N], M2[N][N], M3[N][N], M4[N][N], M5[N][N], M6[N][N], M7[N][N];
     T AA[N][N], BB[N][N];

     if(n == 2) {  //2-order
        Matrix_Multiply(A, B, C);
     } else {

        for(int i=0; i<n/2; i++) {
           for(int j=0; j<n/2; j++) {
              A11[i][j] = A[i][j];
              A12[i][j] = A[i][j+n/2];
              A21[i][j] = A[i+n/2][j];
              A22[i][j] = A[i+n/2][j+n/2];

              B11[i][j] = B[i][j];
              B12[i][j] = B[i][j+n/2];
              B21[i][j] = B[i+n/2][j];
              B22[i][j] = B[i+n/2][j+n/2];
           }
        }

        cout<<"\n Dividing A and B :\n";
        cout<<"\n\tA11:\n";
        output(n/2, A11);

        cout<<"\n\tA12:\n";
        output(n/2, A12);

        cout<<"\n\tA21:\n";
        output(n/2, A21);

        cout<<"\n\tA22:\n";
        output(n/2, A22);

        cout<<"\n\tB11:\n";
        output(n/2, B11);

        cout<<"\n\tB12:\n";
        output(n/2, B12);

        cout<<"\n\tB21:\n";
        output(n/2, B21);

        cout<<"\n\tB22:\n";
        output(n/2, B22);

        cout<<"\n\n\n---------------------------------------";
        cout<<"\n---------------------------------------";
        cout<<"\n---------------------------------------";


        // Calculation of M1 = (A0 + A3) * (B0 + B3)
        cout<<"\n-------------------------------------";
        cout<<"\nM1 =\n_________";
        output(n/2, A11);
        cout<<"++++++++";
        output(n/2, A22);
        cout<<"_________\n********\n_________";
        output(n/2, B11);
        cout<<"++++++++";
        output(n/2, B22);
        cout<<"_________\n------------------------------------";

        Matrix_Add(n/2, A11, A22, AA);
        Matrix_Add(n/2, B11, B22, BB);
        Strassen(n/2, AA, BB, M1);


        // Calculation of M2 = (A2 + A3) * B0
        cout<<"------------------------------------";
        cout<<"\nM2 =\n_________";
        output(n/2, A21);
        cout<<"++++++++";
        output(n/2, A22);
        cout<<"_________\n********\n_________";
        output(n/2, B11);
        cout<<"_________\n------------------------------------";

        Matrix_Add(n/2, A21, A22, AA);
        Strassen(n/2, AA, B11, M2);


        // Calculation M3 = A0 * (B1 - B3)
        cout<<"------------------------------------";
        cout<<"\nM3 =\n_________";
        output(n/2, A11);
        cout<<"_________\n********\n_________";
        output(n/2, B12);
        cout<<"--------";
        output(n/2, B22);
        cout<<"_________\n------------------------------------";

        Matrix_Sub(n/2, B12, B22, BB);
        Strassen(n/2, A11, BB, M3);


        // Calculation M4 = A3 * (B2 - B0)
        cout<<"------------------------------------";
        cout<<"\nM4 =\n_________";
        output(n/2, A22);
        cout<<"_________\n********\n_________";
        output(n/2, B21);
        cout<<"--------";
        output(n/2, B11);
        cout<<"_________\n------------------------------------";

        Matrix_Sub(n/2, B21, B11, BB);
        Strassen(n/2, A22, BB, M4);


        // Calculation M5 = (A0 + A1) * B3
        cout<<"------------------------------------";
        cout<<"\nM5 =\n_________";
        output(n/2, A11);
        cout<<"++++++++";
        output(n/2, A12);
        cout<<"_________\n********\n_________";
        output(n/2, B22);
        cout<<"_________\n------------------------------------";

        Matrix_Add(n/2, A11, A12, AA);
        Strassen(n/2, AA, B22, M5);


        // Calculation M6 = (A2 - A0) * (B0 + B1)
        cout<<"------------------------------------";
        cout<<"\nM6 =\n_________";
        output(n/2, A21);
        cout<<"--------";
        output(n/2, A11);
        cout<<"_________\n********\n_________";
        output(n/2, B11);
        cout<<"++++++++";
        output(n/2, B12);
        cout<<"_________\n------------------------------------";

        Matrix_Sub(n/2, A21, A11, AA);
        Matrix_Add(n/2, B11, B12, BB);
        Strassen(n/2, AA, BB, M6);


        // Calculation M7 = (A1 - A3) * (B2 + B3)
        cout<<"------------------------------------";
        cout<<"\nM7 =\n_________";
        output(n/2, A12);
        cout<<"--------";
        output(n/2, A22);
        cout<<"_________\n********\n_________";
        output(n/2, B21);
        cout<<"++++++++";
        output(n/2, B22);
        cout<<"_________\n------------------------------------";

        Matrix_Sub(n/2, A12, A22, AA);
        Matrix_Add(n/2, B21, B22, BB);
        Strassen(n/2, AA, BB, M7);

        cout<<"\n\n\n---------------------------------------";
        cout<<"\n---------------------------------------";
        cout<<"\n---------------------------------------";

        cout<<"\n_________\nM1=";
        output(n/2, M1);
        cout<<"_________\nM2=";
        output(n/2, M2);
        cout<<"_________\nM3=";
        output(n/2, M3);
        cout<<"_________\nM4=";
        output(n/2, M4);
        cout<<"_________\nM5=";
        output(n/2, M5);
        cout<<"_________\nM6=";
        output(n/2, M6);
        cout<<"_________\nM7=";
        output(n/2, M7);

        cout<<"\n\n\n---------------------------------------";
        cout<<"\n---------------------------------------";
        cout<<"\n---------------------------------------";


        // Calculation C0 = M1 + M4 - M5 + M7
        cout<<"\n------------------------------------";
        cout<<"\nC11 =\n_________";
        output(n/2, M1);
        cout<<"+++++++";
        output(n/2, M4);
        cout<<"-------";
        output(n/2, M5);
        cout<<"++++++++";
        output(n/2, M7);
        cout<<"_________\n------------------------------------";
        Matrix_Add(n/2, M1, M4, AA);
        Matrix_Sub(n/2, M7, M5, BB);
        Matrix_Add(n/2, AA, BB, C11);

        // Calculation C1 = M3 + M5
        cout<<"------------------------------------";
        cout<<"\nC12 =\n_________";
        output(n/2, M3);
        cout<<"+++++++";
        output(n/2, M5);
        cout<<"_________\n------------------------------------";
        Matrix_Add(n/2, M3, M5, C12);

        // Calculation C2 = M2 + M4
        cout<<"------------------------------------";
        cout<<"\nC21 =\n_________";
        output(n/2, M2);
        cout<<"+++++++";
        output(n/2, M4);
        cout<<"_________\n------------------------------------";
        Matrix_Add(n/2, M2, M4, C21);

        // Calculation C3 = M1 - M2 + M3 + M6
        cout<<"------------------------------------";
        cout<<"\nC22 =\n_________";
        output(n/2, M1);
        cout<<"-------";
        output(n/2, M2);
        cout<<"+++++++";
        output(n/2, M3);
        cout<<"++++++++";
        output(n/2, M6);
        cout<<"_________\n------------------------------------";
        Matrix_Sub(n/2, M1, M2, AA);
        Matrix_Add(n/2, M3, M6, BB);
        Matrix_Add(n/2, AA, BB, C22);

        cout<<"\n\n\n---------------------------------------";
        cout<<"\n---------------------------------------";
        cout<<"\n---------------------------------------";

        cout<<"\n_________\nC11=";
        output(n/2, C11);
        cout<<"_________\nC12=";
        output(n/2, C12);
        cout<<"_________\nC21=";
        output(n/2, C21);
        cout<<"_________\nC22=";
        output(n/2, C22);
        cout<<"_________";


        cout<<"\n\n\n---------------------------------------";
        cout<<"---------------------------------------";
        cout<<"\nFinal Answer:\n\n";

        for(int i=0; i<n/2; i++) {
           for(int j=0; j<n/2; j++) {
              C[i][j] = C11[i][j];
              C[i][j+n/2] = C12[i][j];
              C[i+n/2][j] = C21[i][j];
              C[i+n/2][j+n/2] = C22[i][j];
           }
        }
     }
}