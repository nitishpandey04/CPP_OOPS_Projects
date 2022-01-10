class Polynomial {
    
    public:
    
    int *degCoeff;
    
    int capacity;
    
    Polynomial() {
        
        degCoeff = new int[5];
        
        for (int i = 0 ; i < 5 ; i ++) {
            
            degCoeff[i] = 0;
        }
        
        capacity = 5;
    }
    
    Polynomial(const Polynomial & p) {
        
        capacity = p.capacity;
        
        degCoeff = new int[capacity];
        
        for (int i = 0 ; i < capacity ; i ++) {
            
            degCoeff[i] = p.degCoeff[i];
        }
    }
    
    void setCoefficient(int degree, int coefficient) {
        
        if (degree < capacity) {
            
            degCoeff[degree] = coefficient;
        }
        
        else {
        	
            int * newdegCoeff = new int[degree + 1];
            
            for (int i = 0 ; i < capacity ; i ++) {
                
                newdegCoeff[i] = degCoeff[i];
            }
            
            for (int i = capacity ; i < degree ; i ++) {
                
                newdegCoeff[i] = 0;
            }
            
            newdegCoeff[degree] = coefficient;
            
            delete [] degCoeff;
            
            degCoeff = newdegCoeff;
            
            capacity = degree + 1;
        }
    }
    
    Polynomial operator+ (const Polynomial & p) const {
        
    	Polynomial pNew;
        
        for (int i = 0 ; i < max(p.capacity, capacity) ; i ++) {
            
        	int firstcoeff = 0, secondcoeff = 0;
            
            if (i < capacity) firstcoeff = degCoeff[i];
            
            if (i < p.capacity) secondcoeff = p.degCoeff[i];
            
            pNew.setCoefficient(i, firstcoeff + secondcoeff);
        }
        
        return pNew;
    }
    
    Polynomial operator- (const Polynomial & p) const {
        
    	Polynomial pNew;
        
        for (int i = 0 ; i < max(p.capacity, capacity) ; i ++) {
            
        	int firstcoeff = 0, secondcoeff = 0;
            
            if (i < capacity) firstcoeff = degCoeff[i];
            
            if (i < p.capacity) secondcoeff = p.degCoeff[i];
            
            pNew.setCoefficient(i, firstcoeff - secondcoeff);
        }
        
        return pNew;
    }
    
    Polynomial operator* (const Polynomial & p) const {
        
        Polynomial pNew;
        
        for (int i = 0 ; i < capacity ; i ++) {
            
            for (int j = 0 ; j < p.capacity ; j ++) {
                
            	int d = i + j;
                
                if (d >= pNew.capacity) {
                    
                    pNew.setCoefficient(d, 0);
                }
                
                int c = degCoeff[i] * p.degCoeff[j];
                
                c += pNew.degCoeff[d];
                
                pNew.setCoefficient(d, c);
            }
        }
        
        return pNew;
    }
    
    void operator= (const Polynomial & p) {
        
        capacity = p.capacity;
        
        delete [] degCoeff;
        
        degCoeff = new int[capacity];
        
        for (int i = 0 ; i < capacity ; i ++) {
            
            degCoeff[i] = p.degCoeff[i];
        }
    }
    
    void print() const {
	
        for (int i = 0 ; i < capacity ; i ++) {
            
            if (!degCoeff[i]) continue;
            
            cout << degCoeff[i] << "x" << i << (i == capacity - 1 ? "\n" : " ");
        }
    }
};
