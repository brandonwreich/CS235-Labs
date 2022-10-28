#include "QSInterface.h"

class QS : public QSInterface {
    private:
        int *array;
        int size;
        int cap;
    
    public:
        QS();
        ~QS();

        void sortAll();
        void sort(int left, int right);
        int medianOfThree(int left, int right);
        int partition(int left, int right, int pivotIndex);
        string getArray() const;
        int getSize() const;
        bool addToArray(int value);
        bool createArray(int capacity);
        void clear();
};