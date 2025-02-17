
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include "div.h"

#define NRANSI
#include "nrutil.h"
#define TINY 1.0e-20;

#if defined(__STDC__) || defined(ANSI) || defined(NRANSI) /* ANSI */

#define NR_END 1
#define FREE_ARG char*





// void _init()
// {
// }

// void _fini()
// {
// }





void nrerror(char error_text[])
/* Numerical Recipes standard error handler */
{
	fprintf(stderr,"Numerical Recipes run-time error...\n");
	fprintf(stderr,"%s\n",error_text);
	fprintf(stderr,"...now exiting to system...\n");
	exit(1);
}





double *dvector(long nl, long nh)
/* allocate a double vector with subscript range v[nl..nh] */
{
	double *v;

	v=(double *)malloc((size_t) ((nh-nl+1+NR_END)*sizeof(double)));
	if (!v) nrerror("allocation failure in dvector()");
	return v-nl+NR_END;
}






void free_dvector(double *v, long nl, long nh)
/* free a double vector allocated with dvector() */
{
	free((FREE_ARG) (v+nl-NR_END));
}





int *ivector(long nl, long nh)
/* allocate an integer vector with subscript range v[nl..nh] */
{
	int *v;

	v=(int *)malloc((size_t) ((nh-nl+1+NR_END)*sizeof(int)));
	if (!v) nrerror("allocation failure in ivector()");
	return v-nl+NR_END;
}





void free_ivector(int *v, long nl, long nh)
/* free an integer vector allocated with ivector() */
{
	free((FREE_ARG) (v+nl-NR_END));
}
#endif /* ANSI */





int ludcmp(double **a, int n, int *indx, double *d)
{
	int i,imax,j,k;
	double big,dum,sum,temp;
	double *vv;
        int ierr=0;

	vv=dvector(1,n);
	*d=1.0;
	for (i=1;i<=n;i++) {
		big=0.0;
		for (j=1;j<=n;j++)
			if ((temp=fabs(a[i][j])) > big) big=temp;
/*		if (big == 0.0) nrerror("Singular matrix in routine ludcmp");*/
		if (big == 0.0) {
                    ierr=1;
                    break;
                }
		vv[i]=1.0/big;
	}
        
        if (!ierr) {
	    for (j=1;j<=n;j++) {
	    	    for (i=1;i<j;i++) {
			sum=a[i][j];
			for (k=1;k<i;k++) sum -= a[i][k]*a[k][j];
			a[i][j]=sum;
		    }
		    big=0.0;
		    for (i=j;i<=n;i++) {
			sum=a[i][j];
			for (k=1;k<j;k++)
				sum -= a[i][k]*a[k][j];
			a[i][j]=sum;
			if ( (dum=vv[i]*fabs(sum)) >= big) {
				big=dum;
				imax=i;
			}
		    }
		    if (j != imax) {
			for (k=1;k<=n;k++) {
				dum=a[imax][k];
				a[imax][k]=a[j][k];
				a[j][k]=dum;
			}
			*d = -(*d);
			vv[imax]=vv[j];
		    }
		    indx[j]=imax;
		    if (a[j][j] == 0.0) a[j][j]=TINY;
		    if (j != n) {
			dum=1.0/(a[j][j]);
			for (i=j+1;i<=n;i++) a[i][j] *= dum;
		    }
	    }
        }
        
	free_dvector(vv,1,n);
        
        return ierr;
}
#undef TINY
#undef NRANSI





void lubksb(double **a, int n, int *indx, double b[])
{
	int i,ii=0,ip,j;
	double sum;

	for (i=1;i<=n;i++) {
		ip=indx[i];
		sum=b[ip];
		b[ip]=b[i];
		if (ii)
			for (j=ii;j<=i-1;j++) sum -= a[i][j]*b[j];
		else if (sum) ii=i;
		b[i]=sum;
	}
	for (i=n;i>=1;i--) {
		sum=b[i];
		for (j=i+1;j<=n;j++) sum -= a[i][j]*b[j];
		b[i]=sum/a[i][i];
	}
}






int matinv(double **ainv, double **a, int nra)
{
	double d,*col;
	int i,j,*indx;
        int ierr=0;

	indx=ivector(1,nra+1);
	col=dvector(1,nra+1);

	ierr=ludcmp(a, nra, indx, &d);

        if (!ierr) {
	    for (j=1;j<=nra;j++) {
		for (i=1;i<=nra;i++) col[i]=0.0;
		col[j]=1.0;
		lubksb(a,nra,indx,col);
		for (i=1;i<=nra;i++) ainv[i][j]=col[i];
	    }
        }

	free_dvector(col,1,nra+1);
	free_ivector(indx,1,nra+1);

        return ierr;
}





#define NRANSI

extern int ncom;
extern double *pcom,*xicom,(*nrfunc)(double []);

double f1dim(double x)
{
	int j;
	double f,*xt;

	xt=dvector(1,ncom);
	for (j=1;j<=ncom;j++) xt[j]=pcom[j]+x*xicom[j];
	f=(*nrfunc)(xt);
	free_dvector(xt,1,ncom);
	return f;
}
#undef NRANSI





#define NRANSI
#define GOLD 1.618034
#define GLIMIT 100.0
#define TINY 1.0e-20
#define SHFT(a,b,c,d) (a)=(b);(b)=(c);(c)=(d);

void mnbrak(double *ax, double *bx, double *cx, double *fa, double *fb, double *fc,
	double (*func)(double))
{
	double ulim,u,r,q,fu,dum;

	*fa=(*func)(*ax);
	*fb=(*func)(*bx);
	if (*fb > *fa) {
		SHFT(dum,*ax,*bx,dum)
		SHFT(dum,*fb,*fa,dum)
	}
	*cx=(*bx)+GOLD*(*bx-*ax);
	*fc=(*func)(*cx);
	while (*fb > *fc) {
		r=(*bx-*ax)*(*fb-*fc);
		q=(*bx-*cx)*(*fb-*fa);
		u=(*bx)-((*bx-*cx)*q-(*bx-*ax)*r)/
			(2.0*SIGN(FMAX(fabs(q-r),TINY),q-r));
		ulim=(*bx)+GLIMIT*(*cx-*bx);
		if ((*bx-u)*(u-*cx) > 0.0) {
			fu=(*func)(u);
			if (fu < *fc) {
				*ax=(*bx);
				*bx=u;
				*fa=(*fb);
				*fb=fu;
				return;
			} else if (fu > *fb) {
				*cx=u;
				*fc=fu;
				return;
			}
			u=(*cx)+GOLD*(*cx-*bx);
			fu=(*func)(u);
		} else if ((*cx-u)*(u-ulim) > 0.0) {
			fu=(*func)(u);
			if (fu < *fc) {
				SHFT(*bx,*cx,u,*cx+GOLD*(*cx-*bx))
				SHFT(*fb,*fc,fu,(*func)(u))
			}
		} else if ((u-ulim)*(ulim-*cx) >= 0.0) {
			u=ulim;
			fu=(*func)(u);
		} else {
			u=(*cx)+GOLD*(*cx-*bx);
			fu=(*func)(u);
		}
		SHFT(*ax,*bx,*cx,u)
		SHFT(*fa,*fb,*fc,fu)
	}
}
#undef GOLD
#undef GLIMIT
#undef TINY
#undef SHFT
#undef NRANSI





#define NRANSI
#define ITMAX 1000
#define CGOLD 0.3819660
#define ZEPS 1.0e-10
#define SHFT(a,b,c,d) (a)=(b);(b)=(c);(c)=(d);

double brent(double ax, double bx, double cx, double (*f)(double), double tol,
	double *xmin)
{
	int iter;
	double a,b,d,etemp,fu,fv,fw,fx,p,q,r,tol1,tol2,u,v,w,x,xm;
	double e=0.0;

	a=(ax < cx ? ax : cx);
	b=(ax > cx ? ax : cx);
	x=w=v=bx;
	fw=fv=fx=(*f)(x);
	for (iter=1;iter<=ITMAX;iter++) {
		xm=0.5*(a+b);
		tol2=2.0*(tol1=tol*fabs(x)+ZEPS);
		if (fabs(x-xm) <= (tol2-0.5*(b-a))) {
			*xmin=x;
			return fx;
		}
		if (fabs(e) > tol1) {
			r=(x-w)*(fx-fv);
			q=(x-v)*(fx-fw);
			p=(x-v)*q-(x-w)*r;
			q=2.0*(q-r);
			if (q > 0.0) p = -p;
			q=fabs(q);
			etemp=e;
			e=d;
			if (fabs(p) >= fabs(0.5*q*etemp) || p <= q*(a-x) || p >= q*(b-x))
				d=CGOLD*(e=(x >= xm ? a-x : b-x));
			else {
				d=p/q;
				u=x+d;
				if (u-a < tol2 || b-u < tol2)
					d=SIGN(tol1,xm-x);
			}
		} else {
			d=CGOLD*(e=(x >= xm ? a-x : b-x));
		}
		u=(fabs(d) >= tol1 ? x+d : x+SIGN(tol1,d));
		fu=(*f)(u);
		if (fu <= fx) {
			if (u >= x) a=x; else b=x;
			SHFT(v,w,x,u)
			SHFT(fv,fw,fx,fu)
		} else {
			if (u < x) a=u; else b=u;
			if (fu <= fw || w == x) {
				v=w;
				w=u;
				fv=fw;
				fw=fu;
			} else if (fu <= fv || v == x || v == w) {
				v=u;
				fv=fu;
			}
		}
	}
	nrerror("Too many iterations in brent");
	*xmin=x;
	return fx;
}
#undef ITMAX
#undef CGOLD
#undef ZEPS
#undef SHFT
#undef NRANSI





#define NRANSI
#define TOL 2.0e-4

int ncom;
double *pcom,*xicom,(*nrfunc)(double []);

void linmin(double p[], double xi[], int n, double *fret, double (*func)(double []))
{
	double brent(double ax, double bx, double cx,
		double (*f)(double), double tol, double *xmin);
	double f1dim(double x);
	void mnbrak(double *ax, double *bx, double *cx, double *fa, double *fb,
		double *fc, double (*func)(double));
	int j;
	double xx,xmin,fx,fb,fa,bx,ax;

	ncom=n;
	pcom=dvector(1,n);
	xicom=dvector(1,n);
	nrfunc=func;
	for (j=1;j<=n;j++) {
		pcom[j]=p[j];
		xicom[j]=xi[j];
	}
	ax=0.0;
	xx=1.0;
	mnbrak(&ax,&xx,&bx,&fa,&fx,&fb,f1dim);
	*fret=brent(ax,xx,bx,f1dim,TOL,&xmin);
	for (j=1;j<=n;j++) {
		xi[j] *= xmin;
		p[j] += xi[j];
	}
	free_dvector(xicom,1,n);
	free_dvector(pcom,1,n);
}
#undef TOL
#undef NRANSI





int minfun_n;
double (*minfun_func)(double []);

double func2(double *pth_nr)
{
	int i;
	double *pth,fval;
	
	pth=calloc(minfun_n,sizeof(double));

	for (i=0;i<minfun_n;i++) {
		pth[i]=pth_nr[i+1];
	}

	fval=minfun_func(pth);

	free(pth);

	return fval;
}





#define NRANSI
#define ITMAX 1000

void powell(double p[], double **xi, int n, double ftol, int *iter, double *fret,
	double (*func)(double []))
{
	int i,ibig,j;
	double del,fp,fptt,t,*pt,*ptt,*xit;

	pt=dvector(1,n);
	ptt=dvector(1,n);
	xit=dvector(1,n);
	*fret=(*func)(p);
	for (j=1;j<=n;j++) pt[j]=p[j];
	for (*iter=1;;++(*iter)) {
		fp=(*fret);
		ibig=0;
		del=0.0;
		for (i=1;i<=n;i++) {
			for (j=1;j<=n;j++) xit[j]=xi[j][i];
			fptt=(*fret);
			linmin(p,xit,n,fret,func);
			if (fabs(fptt-(*fret)) > del) {
				del=fabs(fptt-(*fret));
				ibig=i;
			}
		}
		if (2.0*fabs(fp-(*fret)) <= ftol*(fabs(fp)+fabs(*fret))) {
			free_dvector(xit,1,n);
			free_dvector(ptt,1,n);
			free_dvector(pt,1,n);
			return;
		}
		if (*iter == ITMAX) nrerror("powell exceeding maximum iterations.");
		for (j=1;j<=n;j++) {
			ptt[j]=2.0*p[j]-pt[j];
			xit[j]=p[j]-pt[j];
			pt[j]=p[j];
		}
		fptt=(*func)(ptt);
		if (fptt < fp) {
			t=2.0*(fp-2.0*(*fret)+fptt)*SQR(fp-(*fret)-del)-del*SQR(fp-fptt);
			if (t < 0.0) {
				linmin(p,xit,n,fret,func);
				for (j=1;j<=n;j++) {
					xi[j][ibig]=xi[j][n];
					xi[j][n]=xit[j];
				}
			}
		}
	}
}
#undef ITMAX
#undef NRANSI





int** create_integer_matrix(int nrows, int ncols)
{
	int irow;
	int** a;
	
//	declare matrix dynamically

	a=(int**) calloc(nrows,sizeof(double*));

	for (irow=0;irow<nrows;irow++) {
		a[irow]=(int*) calloc(ncols,sizeof(double));
	}

	return a;
}





void destroy_integer_matrix(int **a, int nrows, int ncols)
{
	int irow;

	for (irow=0;irow<nrows;irow++) {
		free(a[irow]);
	}	

	free(a);

	return;
}





void print_integer_matrix(int **a, int nrows, int ncols)
{
	int irow,icol;

	for (irow=0;irow<nrows;irow++) {
		for (icol=0;icol<ncols;icol++) {
			printf("element [%d][%d] of matrix = %d\n",irow,icol,a[irow][icol]);
		}
	}	

	return;
}





#if 0
double** create_double_matrix(int nrows, int ncols)
{
	int irow;
	double** a;
	
//	declare matrix dynamically

	a=(double**) calloc(nrows,sizeof(double*));

	for (irow=0;irow<nrows;irow++) {
		a[irow]=(double*) calloc(ncols,sizeof(double));
	}

	return a;
}
#else
double** create_double_matrix(int, int);
#endif





void destroy_double_matrix(double **a, int nrows, int ncols)
{
	int irow;

	for (irow=0;irow<nrows;irow++) {
		free(a[irow]);
	}	

	free(a);

	return;
}





void print_double_matrix(double **a, int nrows, int ncols)
{
	int irow,icol;

	for (irow=0;irow<nrows;irow++) {
		for (icol=0;icol<ncols;icol++) {
			printf("element [%d][%d] of matrix = %f\n",irow,icol,a[irow][icol]);
		}
	}	

	return;
}





int mat_invert(double **ainv, double **a, int nra)
{
	int i,j;
	double **a2,**a2inv;
        int ierr=0;

	a2=create_double_matrix(nra+1,nra+1);
	a2inv=create_double_matrix(nra+1,nra+1);

	for (i=0;i<nra;i++) {
		for (j=0;j<nra;j++) {
			a2[i+1][j+1]=a[i][j];
		}
	}

	ierr=matinv(a2inv,a2,nra);

        if (!ierr) {        
	    for (i=0;i<nra;i++) {
		for (j=0;j<nra;j++) {
			ainv[i][j]=a2inv[i+1][j+1];
		}
	    }
        }
        
	destroy_double_matrix(a2, nra+1, nra+1);
	destroy_double_matrix(a2inv, nra+1, nra+1);

        return ierr;
}





int mat_mult(double **c, double **a, int nra, int nca, double **b, int ncb)
{
	int i,j,k;
	double sum;

	for (i=0;i<nra;i++) {
		for (j=0;j<ncb;j++) {
			sum=0.0;
			for (k=0;k<nca;k++) {
				sum=sum+a[i][k]*b[k][j];
			}
			c[i][j]=sum;
		}
	}

	return 0;
}





int mat_transp(double **at, double **a, int nra, int nca)
{
	int i,j;

	for (i=0;i<nra;i++) {
		for (j=0;j<nca;j++) {
			at[j][i]=a[i][j];
		}
	}

	return 0;
}





int polyfit(double **coeff, double **xdata, double **ydata, int ndata, int norder)
{
	int i,j;
	double **H, **HT, **wrk1, **wrk2;
        int ierr=0;

	H=create_double_matrix(ndata,norder+1);
	for (i=0;i<ndata;i++) {
		H[i][0]=1.0;
		for (j=1;j<norder+1;j++) {
			H[i][j]=pow(xdata[i][0],j);
		}
	}

	HT=create_double_matrix(norder+1,ndata);
	mat_transp(HT,H,ndata,norder+1);

	wrk1=create_double_matrix(norder+1,norder+1);
	mat_mult(wrk1,HT,norder+1,ndata,H,norder+1);

	wrk2=create_double_matrix(norder+1,norder+1);
	ierr=mat_invert(wrk2,wrk1,norder+1);

	destroy_double_matrix(wrk1,norder+1,norder+1);

        if (!ierr) {
	    wrk1=create_double_matrix(norder+1,ndata);
	    mat_mult(wrk1,wrk2,norder+1,norder+1,HT,ndata);

	    mat_mult(coeff,wrk1,norder+1,ndata,ydata,1);

	    destroy_double_matrix(wrk1,norder+1,ndata);
        }
        
	destroy_double_matrix(wrk2,norder+1,norder+1);

	return ierr;
}





void polyget(double **pd, double x, double **c, int nc)
{
	int nnd,j,i,nd;
	double cnst=1.0;

	nd=nc;
	
	pd[0][0]=c[nc][0];

	for (j=1;j<=nd;j++) pd[j][0]=0.0;

	for (i=nc-1;i>=0;i--) {
		nnd=(nd < (nc-i) ? nd : nc-i);
		for (j=nnd;j>=1;j--)
			pd[j][0]=pd[j][0]*x+pd[j-1][0];
		pd[0][0]=pd[0][0]*x+c[i][0];
	}

	for (i=2;i<=nd;i++) {
		cnst *= i;
		pd[i][0] *= cnst;
	}
}





int minfun(double *pth, int n, double (*func)(double []))
{
	int status;
	int niter,i,j;
	double fret,ftol,*pth_nr,**xi;

	status=0;

//	store in globals
	minfun_n=n;
	minfun_func=func;
	
	ftol=1.e-8;

	pth_nr=calloc(n+1,sizeof(double));

	for (i=0;i<n;i++) {
		pth_nr[i+1]=pth[i];
	}
	
	xi=create_double_matrix(n+1,n+1);

	for (j=0;j<n+1;j++) {
		for (i=0;i<n+1;i++) {
			xi[i][j]=0.0;
			if (i==j) {xi[i][j]=1.0;}
		}
	}

	powell(pth_nr,xi,n,ftol,&niter,&fret,func2);

	for (i=0;i<n;i++) {
		pth[i]=pth_nr[i+1];
	}

	destroy_double_matrix(xi,n+1,n+1);

	free(pth_nr);

	return status;
}
