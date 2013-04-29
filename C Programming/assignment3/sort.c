/*Colin Wadge Assignment 3 V2*/
#include <string.h>
#include "records.h"
/* compare functions for use with qsort function*/
/*each function is relative to the 12 available choices*/
int cmpSplus(const void *p, const void *q){
	const record *pp = p;
	const record *qq = q;
	return pp->score - qq->score;
}
int cmpSminus(const void *p, const void *q){
	const record *pp = p;
	const record *qq = q;
	return qq->score - pp->score;
}
int cmpNplus(const void *p, const void *q){
	const record *pp = p;
	const record *qq = q;
	int n = 0;
	n = strcmp(pp->name.last,qq->name.last);
	if (n == 0){
		return strcmp(pp->name.first,qq->name.first); 
	}
	return n;
}
int cmpNminus(const void *p, const void *q){
	const record *pp = p;
	const record *qq = q;
	int n = 0;
	n = strcmp(qq->name.last,pp->name.last);
	if(n == 0){
		return strcmp(qq->name.first,pp->name.first); 		
	}
	return n;
}
int cmpNplusSminus(const void *p, const void *q){
	const record *pp = p;
	const record *qq = q;
	int n = 0,m;
	n = strcmp(pp->name.last,qq->name.last);
	if(n == 0){
		m = strcmp(pp->name.first,qq->name.first); 		
		if(m == 0){
			return qq->score - pp->score;	
		}
		return m;
	}
	return n;
}
int cmpNplusSplus(const void *p, const void *q){
	const record *pp = p;
	const record *qq = q;
	int n = 0,m;
	n = strcmp(pp->name.last,qq->name.last);
	if(n == 0){
		m = strcmp(pp->name.first,qq->name.first); 		
		if(m == 0){
			return pp->score - qq->score;	
		}
		return m;
	}
	return n;
}
int cmpNminusSminus(const void *p, const void *q){
	const record *pp = p;
	const record *qq = q;
	int n = 0,m;
	n = strcmp(qq->name.last,pp->name.last);
	if(n == 0){
		m = strcmp(qq->name.first,pp->name.first); 		
		if(m == 0){
			return qq->score - pp->score;	
		}
		return m;
	}
	return n;
}
int cmpNminusSplus(const void *p, const void *q){
	const record *pp = p;
	const record *qq = q;
	int n = 0,m;
	n = strcmp(qq->name.last,pp->name.last);
	if(n == 0){
		m = strcmp(qq->name.first,pp->name.first); 		
		if(m == 0){
			return pp->score - qq->score;	
		}
		return m;
	}
	return n;
}
int cmpSplusNminus(const void *p, const void *q){
	const record *pp = p;
	const record *qq = q;
	int n = 0, m = 0;
	n = pp->score - qq->score;
	if(n == 0){
		m = strcmp(qq->name.last,pp->name.last);
		if(m == 0){
			return strcmp(qq->name.first,pp->name.first); 	  
		}
		return m;
	}
	return n;
}
int cmpSplusNplus(const void *p, const void *q){
	const record *pp = p;
	const record *qq = q;
	int n = 0, m = 0;
	n = pp->score - qq->score;
	if(n == 0){
		m = strcmp(pp->name.last,qq->name.last);
		if(m == 0){
			return strcmp(pp->name.first,qq->name.first); 	  
		}
		return m;
	}
	return n;
}
int cmpSminusNminus(const void *p, const void *q){
	const record *pp = p;
	const record *qq = q;
	int n = 0, m = 0;
	n = qq->score - pp->score;
	if(n == 0){
		m = strcmp(qq->name.last,pp->name.last);
		if(m == 0){
			return strcmp(qq->name.first,pp->name.first); 	  
		}
		return m;
	}
	return n;
}
int cmpSminusNplus(const void *p, const void *q){
	const record *pp = p;
	const record *qq = q;
	int n = 0, m = 0;
	n = qq->score - pp->score;
	if(n == 0){
		m = strcmp(pp->name.last,qq->name.last);
		if(m == 0){
			return strcmp(pp->name.first,qq->name.first); 	  
		}
		return m;
	}
	return n;
}