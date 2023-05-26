
#include <iostream>
using namespace std;

class Node 
{
private:
    int data;
    Node* next;
public:
    //constructores

    Node(int newValue)
    {
        data = newValue;
        next = nullptr;
    }
    //destructor
    ~Node() {
        cout << "Node ha sido borrado";
    }
    //setters
    void setData(int v_value)
    {
        data = v_value;
    }
    void setNextNode(Node* v_nextNode)
    {
        next = v_nextNode;
    }
    //getters
    int getData()
    {
        return data;
    }
    Node* getNextNode()
    {
        return next;
    }
};

class List
{
private:
    Node* head;
public:
    List() 
    {
        head = nullptr;
    }
    ~List()
    {
        Node* current = head;
        while (current != nullptr)
        {
            Node* next = current->getNextNode();
            delete current;
            current = next;
        }
    }
    void insert(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) 
        {
            head = newNode;
        }
        else 
        {
            Node* current = head;
            while (current->getNextNode() != nullptr) 
            {
                current = current->getNextNode();
            }
            current->setNextNode(newNode);
        }
    }

    void print() const 
    {
        Node* current = head;
        while (current != nullptr) 
        {
            cout << current->getData() << " ";
            current = current->getNextNode();
        }
        cout << endl;
    }
};
    

int main() {
    List* myList = new List();

    myList->insert(1);
    myList->insert(2);
    myList->insert(10);
    myList->insert(5);
    myList->print();

    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
