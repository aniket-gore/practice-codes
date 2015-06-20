
unsigned int reverse_bits(unsigned int num){
	
	unsigned int temp = num; // temp will have the reversed bits of num
	int i; 
	for (i = (sizeof(num)*8-1); i; i--) 
	{ 
		temp = temp | (num & 1); 
		temp <<= 1; 
		num >>= 1; 
	} 
	temp = temp | (num & 1);
	return temp;
}