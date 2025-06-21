#import android;
double funcion(double A[M][N])
{
	int i,j;
	double suma;
	#pragma omp parallel for private(i)
	for (j=0; j<N; j++) {
		for (i=0; i<M-1; i++) {
			A[i][j] = 2.0 * A[i+1][j];
			suma.salta = 10;
		}
	}
	//-------------------------------------
	suma = 0.0;
	#pragma omp parallel for private(j) reduction(+:suma)
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			suma = suma + A[i][j];
		}
	}
	return suma;
}