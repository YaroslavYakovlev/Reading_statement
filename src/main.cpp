#include <iostream>
#include <sstream>
#include <fstream>

  struct data_statement
  {
    std::string name;
    std::string data;
    int money;
  };


int main(){
  std::cout << "Reading statement" << std::endl;
  std::fstream statement("..\\src\\File\\statement.txt", std::ios::app | std::ios::binary | std::ios::in);
  std::string action;
  data_statement ds;
 
  std::cin >> action;
  if(statement.is_open()){
    if(action == "list"){
      std::cout << "Print statement" << std::endl;
      while(!statement.eof()){
        statement >> ds.name; 
        statement >> ds.data;
        statement >> ds.money;
        
        std::cout << "Name: " << ds.name.c_str() 
                  << " Data: " << ds.data.c_str() 
                  << " Money: " << ds.money << std::endl;
      }

    }else if(action == "add"){
      std::cout << "Write in statement" << std::endl;
      std::cout << "Enter elements: 1 - name, 2 - data, 3 - money" << std::endl;
      std::cin >> ds.name;
      std::cin >> ds.data;
      std::cin >> ds.money;
      statement << ds.name << " " << ds.data << " " << ds.money << "\n";
    }else{
      std::cout << "ERROR action" << std::endl;
    }
  }

statement.close();
  
  return 0;
}


// Что нужно сделать

// Вы уже создавали программу чтения и записи ведомости. 
// Теперь её надо будет обобщить и дополнить использованием структур.

// Формат ведомости прежний. 
// Сначала идёт имя и фамилия получателя 
// денежных средств, далее — дата выдачи 
// в формате ДД.ММ.ГГГГ., затем — сумма выплаты в рублях. 
// Данные разделяются между собой пробелами. 
// В конце каждой записи должен быть перевод строки.

// Структура данных записи должна соответствовать 
// указанному формату.

// При старте программы пользователь указывает команду, 
// которую следует осуществить: list или add. 
// Команда read осуществляет чтение из файла 
// ведомости как и прежде, только уже в структуры 
// данных и отображает их на экране.

// Команда add добавляет новую запись в конец ведомости.

// Советы и рекомендации

// Чтобы определить конец файла, используйте 
// функцию file.eof() как и прежде. 
// Из-за завершающего переноса строки, 
// также стоит проверить и имя. Если оно 
// было считает пустым, то можно считать, 
// что файл закончился.