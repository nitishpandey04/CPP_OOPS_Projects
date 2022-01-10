class DynamicArray {

    int * data;
    int nextIndex;
    int capacity;

    public:

    DynamicArray() {

        data = new int[5];
        
        nextIndex = 0;
        
        capacity = 5;
    }

    DynamicArray(const DynamicArray & d) {

        data = new int[d.capacity];

        for (int i = 0 ; i < d.nextIndex ; i ++) {

            data[i] = d.data[i];
        }

        nextIndex = d.nextIndex;

        capacity = d.capacity;
    }

    void operator=(const DynamicArray & d) {

        data = new int[d.capacity];

        for (int i = 0 ; i < d.nextIndex ; i ++) {

            data[i] = d.data[i];
        }

        nextIndex = d.nextIndex;

        capacity = d.capacity;
    }

    int insert(int value) {

        if (nextIndex == capacity) {

            int * newData = new int[capacity * 2];

            for (int i = 0 ; i < capacity ; i ++) {

                newData[i] = data[i];
            }

            delete [] data;

            data = newData;

            capacity *= 2;
        }

        data[nextIndex] = value;

        nextIndex ++;

        return (nextIndex - 1);
    }

    int insert(int index, int value) {

        if ((index < nextIndex) && (index >= 0)) {

            data[index] = value;

            return index;
        }

        else if (index == nextIndex) {

            return insert(value);
        }

        else return -1;
    }

    int get(int index) const {

        if (index < 0 && index >= nextIndex) return -1; 
        // -1 is a possible value
        // should raise error instead of return -1

        else return data[index];
    }

    int sum() const {

        int s = 0;

        for (int i = 0 ; i < nextIndex ; i ++) {

            s += data[i];
        }

        return s;
    }

    int max() const {

        int mx = data[0];

        for (int i = 1 ; i < nextIndex ; i ++) {

            if (data[i] > mx) mx = data[i];
        }

        return mx;
    }

    int min() const {

        int mn = data[0];

        for (int i = 1 ; i < nextIndex ; i ++) {

            if (data[i] < mn) mn = data[i];
        }

        return mn;
    }

    void print() const {

        for (int i = 0 ; i < nextIndex ; i ++) {

            cout << data[i] << (i == nextIndex - 1 ? "\n" : " ");
        }
    }
};
