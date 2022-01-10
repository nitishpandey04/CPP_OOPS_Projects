class Fraction {

    private:

    int numerator;
    int denominator;

    static int gcd(int a, int b) {

        int gcd = 1;
        for (int i = 2 ; i <= min(a, b) ; i ++) {
            if ((a % i == 0) && (b % i == 0)) gcd = i;
        }
        return gcd;
    }

    static int lcm(int a, int b) {
        return (a / gcd(a, b)) * b;
    }

    public:
    Fraction(int n, int d) {
        numerator = n;
        denominator = d;
        simplify();
    }

    void print() const {
        cout << numerator << " / " << denominator << "\n";
    }

    void simplify() {
        int g = gcd(numerator, denominator);
        numerator /= g;
        denominator /= g;
    }

    Fraction operator+ (const Fraction & f) const {

        int l = lcm(denominator, f.denominator);
        int x = l / denominator;
        int y = l / f.denominator;
        int n = x * numerator + (y * f.numerator);

        Fraction fNew(n, l);
        fNew.simplify();
        return fNew;
    }

    Fraction operator- (const Fraction & f) const {

        int l = lcm(denominator, f.denominator);
        int x = l / denominator;
        int y = l / f.denominator;
        int n = x * numerator - (y * f.numerator);

        Fraction fNew(n, l);
        fNew.simplify();
        return fNew;
    }

    Fraction operator* (const Fraction & f) const {

        int n = numerator * f.numerator;
        int d = denominator * f.denominator;

        Fraction fNew(n, d);
        fNew.simplify();
        return fNew;
    }

    Fraction operator/ (const Fraction & f) const {

        int n = numerator * f.denominator;
        int d = denominator * f.numerator;

        Fraction fNew(n, d);
        fNew.simplify();
        return fNew;
    }

    bool operator== (const Fraction & f) const {

        return ((numerator == f.numerator) && (denominator == f.denominator));
    }

    // pre increment
    Fraction& operator++ () {
        numerator = numerator + denominator;
        simplify();

        return *this;
    }

    Fraction& operator-- () {

        numerator = numerator - denominator;
        simplify();

        return *this;
    }

    // post increment
    Fraction operator++ (int) {
        
        Fraction fNew = *this;
        numerator += denominator;
        simplify();

        return fNew;
    }

    Fraction operator-- (int) {

        Fraction fNew = *this;
        numerator -= denominator;
        simplify();

        return fNew;
    }

    // assignment operations
    Fraction& operator+= (const Fraction &f) {

        int l = lcm(denominator, f.denominator);
        int x = l / denominator;
        int y = l / f.denominator;
        int n = x * numerator + (y * f.numerator);

        numerator = n;
        denominator = l;
        return *this;
    }

    Fraction& operator-= (const Fraction &f) {

        int l = lcm(denominator, f.denominator);
        int x = l / denominator;
        int y = l / f.denominator;
        int n = x * numerator - (y * f.numerator);

        numerator = n;
        denominator = l;
        return *this;
    }

    Fraction& operator*= (const Fraction & f) {

        numerator *= f.numerator;
        denominator *= f.denominator;

        simplify();
        return *this;
    }

    Fraction& operator/= (const Fraction & f) {

        numerator *= f.denominator;
        denominator *= f.numerator;

        simplify();
        return *this;
    }
};
