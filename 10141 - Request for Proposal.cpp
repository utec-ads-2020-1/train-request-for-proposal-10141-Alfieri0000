#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int N_Req;
int N_Prop;

struct Propuestas{
    string Nombre = "";
    float costo = 0;
    int requerimientos = 0;
};

string Ganadores[1000];
int contador_ganadores = 0;

void obtenerValores(){
    string Entrada;
    
    string S_Req;
    string S_Prop;
    
    getline(cin,Entrada);
    istringstream iss(Entrada);
    
    iss >> S_Req;
    stringstream geek1(S_Req);
    geek1 >> N_Req;
    
    iss >> S_Prop;
    stringstream geek2(S_Prop);
    geek2 >> N_Prop;
    
}

void Evaluacion(){
    
    //Consigo Requerimientos
    string Req_Actuales[N_Req];
    for (int i = 0;i < N_Req;i++){
        getline(cin,Req_Actuales[i]);
    }
    
    //Consigo Cada Propuesta
    struct Propuestas prop[N_Prop]{
    };
    for (int i = 0;i < N_Prop;i++){
        //Nombre
        getline(cin,prop[i].Nombre);
        
        
        //Costo y Requerimientos cumplidos
        string CyR;
        string Costos;
        string R_Cump;
        
        getline(cin,CyR);
        istringstream iss(CyR);
        
        iss >> Costos;
        prop[i].costo = stof(Costos);
        
        iss >> R_Cump;
        stringstream geek(R_Cump);
        geek >> prop[i].requerimientos;
        
        //Verificación de requerimientos
        string validacion;
        for (int j = 0;j < prop[i].requerimientos;j++){
            getline(cin,validacion);
        }
    }

    
    //Evaluar ganador y agregarlo a la lista
    int longitud = sizeof(prop)/sizeof(prop[0]);
    int max = prop[0].requerimientos;
    int ubicacion = 0;
    for (int j = 1;j < longitud;j++){
        if (max < prop[j].requerimientos){
            max = prop[j].requerimientos;
            ubicacion = j;
        }
    }
    //Obtengo el maximo primero, si existen de igual tamaño y no son el mismo
    for (int j = 0;j < longitud;j++){
        if (max == prop[j].requerimientos && ubicacion != j){
            
            //Si tienen mismos requerimientos cumplidos y diferente lugar evaluo costos
            if (prop[ubicacion].costo > prop[j].costo){
                max = prop[j].requerimientos;
                ubicacion = j;
            }
        }
    }

    //Agrego ganador a la lista de ganadores
    Ganadores[contador_ganadores] = prop[ubicacion].Nombre;
    contador_ganadores++;
}


int main(){
    int concursos = 1;
    while (concursos == 1){
        
        //Obtengo enteros de valores
        obtenerValores();
        if (N_Prop == 0 && N_Req == 0){
            concursos = 0;
        }
        else{
            Evaluacion();
        }
    }
    for (int i = 0;i<contador_ganadores;i++){
        cout << "RFP #" << i+1 << endl;
        cout << Ganadores[i] << endl;
        cout << endl;
    }
        
    
    
    return 0;
}

