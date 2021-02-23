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

        out  << element.fps << '\n';
        out << element.d.street << '\n';
        out <<  element.d.house_number << '\n';
        out << element.d.flat_number << '\n';
        out <<  element.sex << '\n';
        out <<  element.age << '\n';
    }
    return out;
}

istream& operator>>(istream& in, address& human) {

    in >> human.street >> human.house_number >> human.flat_number;
    return in;
}

istream& operator>>(istream& in, vector <citizen>& human)  // я так и не понял зачем мне это, написал, потому что в правках указано, что нужно перегрузить >>

{
    for (citizen& human : human) {
        getline(in, human.fps);
        getline(in, human.d.street);
        in >> human.d.house_number;
        in >> human.d.flat_number;
        getline(in , human.sex);
        in >> human.age;
    }
    return in;
}

 bool operator<(const citizen& c1, const citizen& c2)
{
    if (c1.fps < c2.fps)
        return true;
    if (c1.fps > c2.fps)
        return false;
    if (c1.sex < c2.sex)
        return true;
    if (c1.sex > c2.sex)
        return false;
    if (c1.age < c2.age)
        return true;
    if (c1.age > c2.age)
        return false;
    return false;
}
 bool operator<(const address& a1, const address& a2)
 {
     if (a1.street < a2.street)
         return true;
     if (a1.street > a2.street)
         return false;
     if (a1.house_number < a2.house_number)
         return true;
     if (a1.house_number > a2.house_number)
         return false;
     if (a1.flat_number < a2.flat_number)
         return true;
     if (a1.flat_number > a2.flat_number)
         return false;
     return false;
 }

 bool operator>(const citizen& c1, const citizen& c2)
 {
     if (c1.fps < c2.fps)
         return false;
     if (c1.fps > c2.fps)
         return true;
     if (c1.sex < c2.sex)
         return false;
     if (c1.sex > c2.sex)
         return true;
     if (c1.age < c2.age)
         return false;
     if (c1.age > c2.age)
         return true;
     return true;
 }
 bool operator>(const address& a1, const address& a2)
 {
     if (a1.street < a2.street)
         return false;
     if (a1.street > a2.street)
         return true;
     if (a1.house_number < a2.house_number)
         return false;
     if (a1.house_number > a2.house_number)
         return true;
     if (a1.flat_number < a2.flat_number)
         return false;
     if (a1.flat_number > a2.flat_number)
         return true;
     return true;
 }

void sort(vector<citizen>& arr, int n)
{
    
    int start = 0;
    int finish = arr.size() - 1;

    while (start < finish) {
        for (int i = 0; i < finish; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], (arr)[i + 1]);
            }
        }
        start++;
        for (int i = finish - 1; i > start; i--) {
            if ((arr)[i] < (arr)[i - 1]) {
                swap((arr)[i], (arr)[i - 1]);
            }
        }
        finish--;
    }
}



void pupil(vector <citizen> human) {
    string str;
    string last;
    int counter = 0;
    cout << "enter street : ";
    getline(cin, str);
   
    for (citizen hum : human) {
       last =  last += hum.d.street.back();
        if ((str == hum.d.street) && (hum.age >= 7 && hum.age <= 18)) {
            cout << hum.fps << endl;
            counter++;
           
            
        }
         else if (str != last) {
            cout << "";
            
        }
      
    }
    cout << counter << " pupils";
}
void write(vector<citizen> human, string file)
{
    ofstream file_w;
    file_w.open(file, ios::out);
    file_w << human;
    file_w.close();
}
void read_Bin(vector<citizen>& human, string file)
{
    ifstream infile(file, ios::binary);
    if (!infile.is_open())
    {
        cout << "error file oppening" << endl;
       
    }
    else {
        citizen cit;
        while (!infile.eof())
        {
            int s;
            infile.read(reinterpret_cast<char*>(&s), sizeof(s));
            cit.fps.resize(s);
            infile.read(cit.fps.data(), s);
            infile.read(reinterpret_cast<char*>(&s), sizeof(s));
            cit.d.street.resize(s);
            infile.read(cit.d.street.data(), s);
            infile.read(reinterpret_cast<char*>(&cit.d.flat_number), sizeof(cit.d.flat_number));
            infile.read(reinterpret_cast<char*>(&cit.d.house_number), sizeof(cit.d.house_number));
            infile.read(reinterpret_cast<char*>(&s), sizeof(s));
            cit.sex.resize(s);
            infile.read(cit.sex.data(), s);
            infile.read(reinterpret_cast<char*>(&cit.age), sizeof(cit.age));
            if (infile.eof()) break;
            human.push_back(cit);
        }
        infile.close();
    }
}

void write_Bin(vector<citizen>& human, string file)
{
    ofstream of_file(file, ios::binary);
    if (!of_file.is_open())
    {
       cout << "error file oppening" << endl;
        
    }
    else {
        for (citizen cit : human)
        {
            int s = cit.fps.size();
            of_file.write(reinterpret_cast<char*>(&s), sizeof(s));
            of_file.write(cit.fps.c_str(), s);
            s = cit.d.street.size();
            of_file.write(reinterpret_cast<char*>(&s), sizeof(s));
            of_file.write(cit.d.street.c_str(), s);
            of_file.write(reinterpret_cast<char*>(&cit.d.flat_number), sizeof(cit.d.flat_number));
            of_file.write(reinterpret_cast<char*>(&cit.d.house_number), sizeof(cit.d.house_number));
            s = cit.sex.size();
            of_file.write(reinterpret_cast<char*>(&s), sizeof(s));
            of_file.write(cit.sex.c_str(), s);
            of_file.write(reinterpret_cast<char*>(&cit.age), sizeof(cit.age));
        }
    }
}

int main(int argc, char* argv[])
{  
  
    ///////////////////////////////////////////////////////
    
    string output_file = argv[1];   

    string output_file2 = argv[2];     //// files 

    /////////////////////////////////////////////////////

    int hmp = 0;
	vector <citizen> human;
    citizen david;
    david.fps = "David Michael Draiman";
    david.d.street = "Hollywood street";
    david.d.house_number = 666;
    david.d.flat_number = 65;
    david.sex = "male";
    david.age = 47;
    /////////////////////
    citizen dan;
    dan.fps = "Daniel Joseph Donegan ";
    dan.d.street = "world`s street";
    dan.d.house_number = 123;
    dan.d.flat_number = 321;
    dan.sex = "male";
    dan.age = 53;
    ////////////////////
    citizen mike;
    mike.fps = "Mike Unknown Wengern";
    mike.d.street = "privet drive";
    mike.d.house_number = 56;
    mike.d.flat_number = 1;
    mike.sex = "male";
    mike.age = 49;
    /////////////////////
    citizen john;
    john.fps = "John Robert Moyer";
    john.d.street = "Park Lein Street";
    john.d.house_number = 7;
    john.d.flat_number = 97;
    john.sex = "male";
    john.age = 11;
    ///////////////////////
    citizen bart;
    bart.fps = "Bart Homer Simpson";
    bart.d.street = "Park Lein Street";
    bart.d.house_number = 742;
    bart.d.flat_number = 1;
    bart.sex = "male";
    bart.age = 10;
    //////////////////////
    human.push_back(david);
    human.push_back(mike);
    human.push_back(dan);
    human.push_back(john);
    human.push_back(bart);
    ////////////////////////

    sort (human,5);

    write(human, output_file);

    write_Bin(human, output_file2);
    human.clear();
     read_Bin(human, output_file2);
     cout << human;
  
     pupil(human);


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
