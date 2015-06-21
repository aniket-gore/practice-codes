#include<iostream>

using namespace std;

//Referred
/*
To find log2(13) we know it is between 3 & 4 because 8<13<16. Then do binary search.
log2(sqrt(8*16)) = 3.5 and sqrt(8*16) = 11.313. Since 11.31 < 13, log2(13) is between 3.5 to 4 i.e. low = mid.
*/
double Log2(double val)
{
    int lox,hix;
    double rval, lval;
    hix = 0;
    while((1<<hix)<val)
        hix++;
    lox =hix-1;
    lval = (1<<lox) ;
    rval = (1<<hix);
    double lo=lox,hi=hix;
   // cout<<lox<<" "<<hix<<endl;
    //cout<<lval<<" "<<rval;
    while( fabs(lval-val)>1e-7)
    {
        double mid = (lo+hi)/2;
        double midValue = sqrt(lval*rval);

        if ( midValue > val)
        {
             hi = mid;
             rval = midValue;
        }
        else{
            lo=mid;
            lval = midValue;
        }
    }
    return lo;

}
/*
int main(){
	cout<<Log2(13)<<endl;
	return 1;
}*/