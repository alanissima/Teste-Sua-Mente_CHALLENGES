#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
vector <string> list_task_global;

void read_file();
void write_file();
void show_list();
void add_task(string task);
void erase_task(int option_erase);

int main() {
    int option; // int opcao;
    int option_del; // int opcao_apagar;
    string task;  //  string tarefa;

    read_file(); // ler_arquivo();


    do {
        cout << "\nType [1] to Show all the tasks\nType [2] to ADD a task\nType [3] to DELETE a task\nType [0] to EXIT\n";

        cin >> option;
        cin.ignore(1, '\n');

        switch(option){
            case 1:
                cout << "SHOW:\n"; //  cout << "Mostrar:\n";
                show_list(); // mostrar_lista();
                break;
            case 2:
                cout << "TO ADD:\n" ; // cout << "Adicionar:\n";
                getline(cin, task); // getline(cin, tarefa);
                add_task(task); // adicionar_tarefa(tarefa);
                break;
            case 3:
                cout << "TO DELETE:\n"; // cout << "Apagar elemento:\n";
                cout << "WHICH TASK DO YOU WANT TO DELETE?\n"; // cout << "Qual tarefa vc deseja apagar?\n";
                show_list(); // mostrar_lista();
                cin >>  option_del; //   cin >> opcao_apagar;

                erase_task(option_del); //  apagar_tarefa(opcao_apagar);

                break;
            default:
                cout << "INVALID OPTION\n"; //cout << "Opcao invalida\n";
                break;
        }
    }while(option != 0);

    return 0;
}


void read_file(){  // ler_arquivo
    string line;  // string linha
    ifstream file; // ifstream arquivo
    file.open("tasks.txt"); // arquivo.open ("tarefas.txt");

    if(file.is_open()){
        while (!file.eof()){
            getline(file, line);
            if (line.size() > 0){
                list_task_global.push_back(line);  //lista_tarefas_global.push_back(linha);
            }
        }
    }

    sort(list_task_global.begin(), list_task_global.end());
    file.close();
}

void write_file(){ // void escrever_arquivo()
    ofstream file; // ofstream arquivo;
    file.open("tasks.txt"); // arquivo.open("tarefas.txt")

    for(string task : list_task_global){
        file << task << endl;
    }

    file.close();
}

void add_task(string task){ // void adicionar_tarefa(string tarefa){
    list_task_global.push_back(task);
    sort(list_task_global.begin(),list_task_global.end());

    write_file(); // escrever_arquivo();
}

void erase_task(int option_erase){ // void apagar_tarefa(int opcao_apagar){
    list_task_global.erase(list_task_global.begin() + option_erase);

    write_file(); // escrever_arquivo();
}

void show_list(){ // void mostrar_lista(){
    for(int i = 0; i < list_task_global.size(); i++){
        cout << i << ") " << list_task_global[i] << endl;
    }
}
