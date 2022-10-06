#include <fstream>
#include <ctime>
#include <iostream>
using namespace std;

int randNumber(int min, int max)
{
    int randomNumber;
    randomNumber = (rand() % (max - min + 1)) + min;
    return randomNumber;
}

class Object
{
    private:
        string Name;

    public:
        void setName(string name) { Name = name; }
        string getName() { return Name; }

        void readData(ifstream &file)
        {
            string name;
            getline(file, name);
            setName(name);
        }
};

class Store : public Object
{
    private:
        string Date;

    public:
        void setDate(string date) { Date = date; }
        string getDate() { return Date; }

        void readObjectData(ifstream &fileObject)
        {
            readData(fileObject);

            string date;
            getline(fileObject, date);
            setDate(date);
        }

        void Welcome()
        {
            cout << "Hello. Welcome at " << getName() << endl;
            cin.ignore();
        }
        void goMainStore()
        {
            cout << getName() << " is in the main store." << endl;
            cin.ignore();
        }
        void goFishmonger()
        {
            cout << getName() << " is going to the fishmonger." << endl;
            cin.ignore();
        }
        void goButcher()
        {
            cout << getName() << " is going to the butcher." << endl;
            cin.ignore();
        }
        void goDrinkSection()
        {
            cout << getName() << " is going to the Beverage Section." << endl;
            cin.ignore();
        }
        void goVendingMachine()
        {
            cout << getName() << " is going to the Vending Machine." << endl;
            cin.ignore();
        }
        void goCashier()
        {
            cout << getName() << " is going to the cashier." << endl;
            cin.ignore();
        }
        void leaveStore()
        {
            cout << getName() << " goes out of the store." << endl;
            cin.ignore();
        }
};

class People : public Store
{
    private:
        string LastName;
        int Age;

    public:
        void setLastName(string lastName) { LastName = lastName; }
        string getLastName() { return LastName; }
        void setAge(int age) { Age = age; }
        int getAge() { return Age; }

        void readPeopleData(ifstream &filePeople)
        {
            readObjectData(filePeople);

            string lastName, age;
            getline(filePeople, lastName);
            setLastName(lastName);
            getline(filePeople, age);
            setAge(atof(age.c_str()));
        }

        void sayHi()
        {
            cout << "Hi. I am " << getName() << endl;
            cin.ignore();
        }
};

class Employee : public People
{
    private:
        int WorkAges;
        string Role;
    
    public:
        void setWorkAges(int workAges) { WorkAges = workAges; }
        int getWorkAges() { return WorkAges; }
        void setRole(string role) { Role = role; }
        string getRole() { return Role; }

        void readEmployeeData(int i)
        {
            ifstream fileEmployee;
            fileEmployee.open("employeeData.txt", ios::in);

            string ignore;
            int j = i * 6;
            while(j--) getline(fileEmployee, ignore);

            readPeopleData(fileEmployee);

            string workAges, role;
            getline(fileEmployee, workAges);
            setWorkAges(atof(workAges.c_str()));
            getline(fileEmployee, role);
            setRole(role);

            fileEmployee.close();
        }

        void employeeIntro()
        {
            cout << "I am the " << getRole() << " that works today" << endl;
            cin.ignore();
        }
        void sayTotalSum(double sum)
        {
            cout << "The total comes to " << sum << "$." << endl;
            cin.ignore();
        }
        string changeCheque(string cheque)
        {
            if (cheque == "Paid") cheque = "NotPaid";
            else cheque = "Paid";
            return cheque;
        }
        void chequeRequest()
        {
            cout << "I will control the cheque of the customer" << endl;
            cin.ignore();
        }
        int checkCheque(double sum, string cheque)
        {
            if (sum == 0 && cheque == "NotPaid")
            { 
                cout << "The customer did not buy anything. He is free to leave." << endl;
                cin.ignore();
                return 1;
            }
            else if (cheque == "NotPaid") 
            {
                cout << "The customer have not paid! He cannot leave. \n" << endl;
                cin.ignore();
                return 0;
            }
            else 
            {
                cout << "It is all right.\n" << endl;
                cin.ignore();
                return 1;
            }
        }
};

class Customer : public People
{
    private:
        string Cheque;
        double Balance;
        double Sum;

    public:
        void setCheque(string cheque) { Cheque = cheque; }
        string getCheque() { return Cheque; }
        void setBalance(double balance) { Balance = balance; }
        double getBalance() { return Balance; }
        void setSum(double sum) { Sum = sum; }
        double getSum() { return Sum; }

        void readCustomerData(int i)
        {
            ifstream fileCustomer;
            fileCustomer.open("customerData.txt", ios::in);

            string ignore;
            int j = i * 7;
            while(j--) getline(fileCustomer, ignore);
            

            readPeopleData(fileCustomer);

            string cheque, balance, sum;
            getline(fileCustomer, cheque);
            setCheque(cheque);
            getline(fileCustomer, balance);
            setBalance(atof(balance.c_str()));
            getline(fileCustomer, sum);
            setSum(atof(sum.c_str()));

            fileCustomer.close();
        }

        void enterStore()
        {
            cout << "Customer " << getName() << " has entered the store." << endl;
            cin.ignore();
        }
        void checkBalance() 
        { 
            cout << getName() << " is checking the balance. Total = ";
            cout << Balance << "$." << endl;
            cin.ignore();
        }
        void addSum(double price) { Sum = Sum + price; }
        void payHotDrink(double price)
        {
            Balance = Balance - price;
            cout << "Notification: " << price;
            cout << "$ have been substracted from the balance of the customer." << endl;
            cout << "Remaining balance: " << getBalance() << "$." << endl; 
            cin.ignore();
        }
        void Payment() 
        { 
            Balance = Balance - Sum; 
            cout << "Notification: " << Sum;
            cout << "$ have been substracted from the balance of the customer." << endl;
            cout << "Remaining balance: " << getBalance() << "$." << endl; 
            cin.ignore();
        }
        void showCheque()
        {
            cout << getName() << " shows the cheque" << endl;
            cout << "+-------------+" << endl;
            if (Cheque == "Paid") cout << "|    " << Cheque << "     |" << endl;
            else cout << "|   " << Cheque << "   |" << endl;
            cout << "+-------------+" << endl;
            cin.ignore();
        }
};

class Item : public Store
{
    private:
        double Price;

    public:
        void setPrice(double price) { Price = price; }
        double getPrice() { return Price; }

        void readItemData(ifstream &fileItem)
        {
            readObjectData(fileItem);

            string price;
            getline(fileItem, price);
            setPrice(atof(price.c_str()));
        }

        void takeItem()
        {
            cout << "The customer took " << getName() << endl;
            cin.ignore();
        }
};

class Food : public Item
{
    private:
        double Mass;

    public:
        void setMass(double mass) { Mass = mass; }
        double getMass() { return Mass; }    

        void readFoodData(int i)
        {
            ifstream fileFood;
            fileFood.open("foodData.txt", ios::in);

            string ignore;
            int j = i * 4;
            while(j--) getline(fileFood, ignore);
            
            readItemData(fileFood);

            string mass;
            getline(fileFood, mass);
            setMass(atof(mass.c_str()));

            fileFood.close();
        }

        void foodDescription()
        {
            cout << "Price: " << getMass() << " kg of " << getName();
            cout << " for " << getPrice() << "$." << endl;
            cin.ignore();
        }
};

class Drink : public Item
{
    private:
        double Volume;

    public:
        void setVolume(double volume) { Volume = volume; }
        double getVolume() { return Volume; }   

        void readDrinkData(int i)
        {
            ifstream fileDrink;
            fileDrink.open("drinkData.txt", ios::in);

            string ignore;
            int j = i * 4;
            while(j--) getline(fileDrink, ignore);
            
            readItemData(fileDrink);

            string volume;
            getline(fileDrink, volume);
            setVolume(atof(volume.c_str()));

            fileDrink.close();
        }

        void drinkDescription()
        {
            cout << "Price: " << getVolume() << " L of " << getName();
            cout << " for " << getPrice() << "$." << endl;
            cin.ignore();
        }
};

int main(void)
{
    srand(time(NULL));
    system("clear");

    int customerNr = 10;
    int employeeNr = 4;
    int foodNr = 12;
    int drinkNr = 8;

    Store store;
    store.setName("Random Store");
    store.setDate("12.03.1998");
    store.Welcome();

    Customer customer, customers[customerNr];
    for (int i = 0; i < customerNr; i++)
    {
        customer.readCustomerData(i);
        customers[i].setName(customer.getName());
        customers[i].setDate(customer.getDate());
        customers[i].setLastName(customer.getLastName());
        customers[i].setCheque(customer.getCheque());
        customers[i].setBalance(customer.getBalance());
        customers[i].setSum(customer.getSum());
        customers[i].setAge(customer.getAge());
    }

    Employee employee, employees[employeeNr];
    for (int i = 0; i < employeeNr; i++)
    {
        employee.readEmployeeData(i);
        employees[i].setName(employee.getName());
        employees[i].setDate(employee.getDate());
        employees[i].setLastName(employee.getLastName());
        employees[i].setAge(employee.getAge());
        employees[i].setWorkAges(employee.getWorkAges());
        employees[i].setRole(employee.getRole());
    }

    Food food, foods[foodNr];
    for (int i = 0; i < foodNr; i++)
    {
        food.readFoodData(i);
        foods[i].setName(food.getName());
        foods[i].setDate(food.getDate());
        foods[i].setPrice(food.getPrice());
        foods[i].setMass(food.getMass());
    }
    
    Drink drink, drinks[drinkNr];
    for (int i = 0; i < drinkNr; i++)
    {
        drink.readDrinkData(i);
        drinks[i].setName(drink.getName());
        drinks[i].setDate(drink.getDate());
        drinks[i].setPrice(drink.getPrice());
        drinks[i].setVolume(drink.getVolume());
    }

    for (int i = 0; i < customerNr; i++)
    {
        system("clear");
        customers[i].enterStore();
        customers[i].checkBalance();
        int times = randNumber(1, 3);

        while (times--)
        {
            system("clear");
            int option = randNumber(1, 5);
            int nr = 0;

            switch (option)
            {
                case 1:
                    customers[i].goMainStore();
                    nr = randNumber(0, 4);
                    foods[nr].takeItem();
                    foods[nr].foodDescription();
                    customers[i].addSum(foods[nr].getPrice());
                break;

                case 2:
                    customers[i].goFishmonger();
                    nr = randNumber(5, 7);
                    foods[nr].takeItem();
                    foods[nr].foodDescription();
                    customers[i].addSum(foods[nr].getPrice());
                break;

                case 3:
                    customers[i].goButcher();
                    nr = randNumber(8, 11);
                    foods[nr].takeItem();
                    foods[nr].foodDescription();
                    customers[i].addSum(foods[nr].getPrice());
                break;

                case 4:
                    customers[i].goDrinkSection();
                    nr = randNumber(0, 4);
                    drinks[nr].takeItem();
                    drinks[nr].drinkDescription();
                    customers[i].addSum(drinks[nr].getPrice());
                break;

                case 5:
                    customers[i].goVendingMachine();
                    nr = randNumber(5, 7);
                    drinks[nr].takeItem();
                    customers[i].payHotDrink(drinks[nr].getPrice());
                break;

                default:
                    cout << "ERROR! Closing Simulation" << endl;
                    cin.ignore();
                    return 0;
                break;
            }
        }

        system("clear");
        int select = randNumber(1, 100);
        if (select <= 90 && customers[i].getSum() != 0)
        {
            customers[i].goCashier();
            employees[0].sayHi();
            employees[0].employeeIntro();
            employees[0].sayTotalSum(customers[i].getSum());
            customers[i].Payment();
            customers[i].setCheque(employees[i].changeCheque(customers[i].getCheque()));
            customers[i].setSum(0);
        }

        system("clear");
        select = randNumber(1, 100);
        if (select <= 30)
        {
            employees[3].sayHi();
            employees[3].employeeIntro();
            employees[3].chequeRequest();
            customers[i].showCheque();
            employees[3].checkCheque(customers[i].getSum(), customers[i].getCheque());
        }

        customers[i].leaveStore();
    }

    return 0;
}

