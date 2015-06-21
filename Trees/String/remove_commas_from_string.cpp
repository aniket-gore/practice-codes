

char *RemoveCommas(char *arr) { 
	char *curr = arr, *tail = arr; 
         while (*curr) { 
             if (*curr != ',') {
                 if (curr != tail) 
					*tail = *curr;
                 curr++;
                 tail++;
            } else  
                curr++;     
         }
         *tail = '\0';
         return arr;
}