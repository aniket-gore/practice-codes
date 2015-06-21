
int gcd(int a, int b) 
{ 
int remainder; 
while(b) 
{ 
remainder = a % b; 
a = b; 
b = remainder; 
} 
return(a); 
}