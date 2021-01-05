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

ostream& operator<<(ostream& out, const vector<citizen>& live)
{
    for (auto& element : live) {

        out << " \nfps of a citizen : " << element.fps ;
        out << " \nstreet living : " << element.d.street  ;
        out << " \nhouse number :" << element.d.house_number ;
        out << " \nflat number :" << element.d.flat_number;
        out << " \ngender :" << element.sex;
        out << " \nage :" << element.age << endl;
    }
    return out;
}

 


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
void pupil(ostream& out, vector <citizen> live , int hmp , string fps) {
    
        out << "Pupils in the town: " << hmp << endl;
        out << "name of the pupil : " << fps;
    
}
int main()
{  
    int hmp = 0;
	vector <citizen> human (5) ;

    human[0] = { "David Michael Draiman" , "Hollywood street", 33, 12, "male", 47 };
    human[1] = { "Daniel Joseph Donegan", "Lenina street",66 ,45 , "male", 52};
    human[2] = { "John Robert Moyer", "World's street", 11, 14 , "male", 46};
    human[3] = { "Mike Unknown Wengren", "Gaidara street", 12, 34 , "male", 49};
    human[4] = {"Bart Homer Simpson", "Park Lein street", 742, 1 , "male", 10};
    sort (human,5);

    for (int i = 0; i <= 4; i++) {
        if (human[i].age >= 7 && human[i].age <= 18) {
            hmp++;          
        }
    }
    
    ofstream l6("l6.txt", ios::out); 
        l6 << human;

        for (int b = 0; b < 4; b ++) {
            if (human[b].age >= 7 && human[b].age <= 18) {
                pupil(l6, human, hmp, human[b].fps);
            }
        }
    l6.close();



    ofstream bin("lab_6.txt", ios::binary);
    for (auto i : human)
    {
        bin.write(reinterpret_cast<char*>(&i.fps), sizeof(i.fps));
        bin.write(reinterpret_cast<char*>(&i.d.street), sizeof(i.d.street));
        bin.write(reinterpret_cast<char*>(&i.d.house_number), sizeof(i.d.house_number));
        bin.write(reinterpret_cast<char*>(&i.d.flat_number), sizeof(i.d.flat_number));
        bin.write(reinterpret_cast<char*>(&i.sex), sizeof(i.sex));
        bin.write(reinterpret_cast<char*>(&i.age), sizeof(i.age));
    }
    bin.close();
    
    ifstream bin_in("lab_6.txt",ios::binary);
    for (auto i : human)
    {
        getline(bin_in, i.fps);
        getline(bin_in, i.d.street);
        bin_in.read(reinterpret_cast<char*>(&i.d.house_number), sizeof(i.d.house_number));
        bin_in.read(reinterpret_cast<char*>(&i.d.flat_number), sizeof(i.d.flat_number));
        getline(bin_in, i.sex);
        bin_in.read(reinterpret_cast<char*>(&i.age), sizeof(i.age));
    }
    bin_in.close();
    
   
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
