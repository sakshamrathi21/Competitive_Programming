#include <iostream>
#include <memory>

class MyClass {
    public:
        MyClass(int val): value(val) {
            std:: cout<<"Constructing MyClass with value: " << value << std::endl;
        }
        ~MyClass() {
            std::cout<< "Destructing MyClass with value: "<< value <<std::endl;
        }

        void printValue() const {
            std:: cout<<"Value: " << value <<std::endl;
        }

    private:
        int value;
};

int main() {
    std::unique_ptr<MyClass> uniquePtr(new MyClass(42));
    //std::unique_ptr<MyClass> anotherptr = uniquePtr;
    std::unique_ptr<MyClass> movedPtr = std::move(uniquePtr);
    uniquePtr.reset(); //This line won't delete the object again.

    std::shared_ptr<MyClass> sharedPtr1 = std::make_shared<MyClass>(100);
    std::shared_ptr<MyClass> sharedPtr2 = sharedPtr1;

    sharedPtr1.reset();
    sharedPtr2.reset();

    std::shared_ptr<MyClass> sharedPtr3 = std::make_shared<MyClass>(200);
    std::weak_ptr<MyClass> weakPtr = sharedPtr3;

    if(std::shared_ptr<MyClass> sharedPtrCopy = weakPtr.lock()) {
        sharedPtrCopy->printValue();
    }
    else {
        std::cout<< "Object no longer exists!" <<std::endl;
    }
    sharedPtr3.reset();



}