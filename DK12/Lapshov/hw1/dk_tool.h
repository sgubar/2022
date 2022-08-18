int how_many_words(char buf[]){
	int number = 0;
	int indx = 0;
	
	while(buf[indx]!='\0'){
		
		if(buf[indx]!=' '){
			
			while(buf[indx]!=' '){
				
				if(buf[indx]=='\0' || buf[indx]=='.' || buf[indx]=='!' || buf[indx]=='?'){
					if(buf[indx-1]==' ' || indx==0)
						return number;
					else
						return number+1;
				}
				
				indx++;
			}
			
			number++;
		}
		else
			indx++;
	}
	
	return number;
}
