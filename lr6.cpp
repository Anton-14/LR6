// lr6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct address {
    string street;
    int house_number;
    int flat_number;
};
struct citizen {
    string fps; // first name| Patronymic| surname;
    address d;
    string sex;
    int age;
};

void sort(vector<citizen>& arr, int n)
{
    citizen t;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++) {
            const char* d1 = arr[i].fps.c_str();
            const char* d2 = arr[j].fps.c_str();
            if (strcmp(d1, d2) > 0)
            {
                t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
}
int main()
{  
    int f = 0;
	vector <citizen> human (5);

    human[0] = { "David Michael Draiman" , "Hollywood street", 33, 12, "male", 47 };
    human[1] = { "Daniel Joseph Donegan", "Lenina street",66 ,45 , "male", 52};
    human[2] = { "John Robert Moyer", "World's street", 11, 14 , "male", 46};
    human[3] = { "Mike Unknown Wengren", "Gaidara street", 12, 34 , "male", 49};
    human[4] = {"Bart Homer Simpson", "Park Lein street", 742, 1 , "male", 10};
    sort (human,5);
    for (int i = 0; i <= 4; i++) {
        if (human[i].age >= 7 && human[i].age <= 18) {
            f++;
        }
    }
    ofstream lr6;
    lr6.open("lr6.txt");
    for (int i = 0; i <= 4; ++i) {
        lr6 << "\ncitizen number=" << i << endl;
        lr6 << "fps=" << human[i].fps << endl;
        lr6 << "street=" << human[i].d.street << endl;
        lr6 << "House number=" << human[i].d.house_number << endl;
        lr6 << "flat number=" << human[i].d.flat_number << endl;
        lr6 << "sex=" << human[i].sex << endl;
        lr6 << "age=" << human[i].age << endl;
    }
    lr6 << "\nschool guys :" << endl;
    for (citizen i : human)
    {
        if (i.age >= 7 && i.age <= 18)
        {
            lr6 << i.fps << endl;
            lr6 << i.age << endl;
        }
    }
    lr6.close();
    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
